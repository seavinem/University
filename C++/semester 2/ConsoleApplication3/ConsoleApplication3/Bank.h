#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


class Player {
public:

    string name;

    int factories;
    int automated_factories;
    int factory_upgrade_month;

    int id;

    int raw_material;
    int products;
    int products_processing;

    int money;
    int credit;
    int insurance_months;
    int repayment;
    int turns_before_credit_end;
    Player(int id) : id(id), raw_material(2), products(2), money(10000), credit(0), insurance_months(0),
        repayment(0), turns_before_credit_end(0), automated_factories(0), factories(2), products_processing(0)
    {    }

    std::string getInfo() const {
        std::string info = "Информация об игроке " + std::to_string(id) + ":\n";
        info += "Сырье: " + std::to_string(raw_material) + "\n";
        info += "Обычные фабрики: " + std::to_string(factories) + "\n";
        info += "Автоматизированные фабрики: " + std::to_string(automated_factories) + "\n";
        info += "Готовая продукция: " + std::to_string(products) + "\n";
        info += "Валюта: " + std::to_string(money) + "\n";
        info += "Кредит: " + std::to_string(credit) + "\n";
        info += "Месяцы страховки: " + std::to_string(insurance_months) + "\n";
        info += "Месяцы до завершения улучшения фабрики: " + (factory_upgrade_month >= 0 ? std::to_string(factory_upgrade_month) : "не улучшается") + "\n";
        return info;
    }
};




class Bank {
private:
    int current_month;
    int raw_materials_for_sale;
    int products_for_sale;
    int raw_material_price;
    int product_price;
    int priority_player_id;


    std::vector<Player> players;


    std::map<int, std::pair<int, int>> auction_buy_offers; // <player_id, <quantity, price>>
    std::map<int, std::pair<int, int>> auction_sell_offers; // <player_id, <quantity, price>>

public:
    Bank() :current_month(0), raw_materials_for_sale(0), products_for_sale(0), raw_material_price(0), product_price(0), priority_player_id(0) {

    }


    void getPlayers() {
        for (auto& player : players) {
            std::cout << player.getInfo();
            std::cout << endl;
            std::cout << endl;
        }
    }

    void addPlayer(int id) {
        players.push_back(Player(id));
    }

    void auctionBuyOffer(int player_id, int quantity, int price) {//Банк делает запросы на покупку
        if (players[player_id].money > quantity * price) {
            auction_buy_offers[player_id] = std::make_pair(quantity, price);
        }
        else std::cout << "У игрока номер " << player_id << " недостаточно денег\n";

    }

    void auctionSellOffer(int player_id, int quantity, int price) {//Банк делает запросы на продажу
        if (players[player_id].products >= quantity) {
            auction_sell_offers[player_id] = std::make_pair(quantity, price);
        }
        else std::cout << "У игрока номер " << player_id << " недостаточно продукции\n";
    }


    void bankSellOffer() {
        raw_materials_for_sale = rand() % 10 + 1; // Случайное количество сырья от 1 до 10
        raw_material_price = rand() % 500 + 100; // Случайная цена от 100 до 600
        std::cout << "Банк предлагает " << raw_materials_for_sale << " шт. сырья по цене " << raw_material_price << " валюты за шт.\n";
    }

    void bankBuyOffer() {
        products_for_sale = rand() % 10 + 1; // Случайное количество продукции от 1 до 10
        product_price = rand() % 500 + 100; // Случайная цена от 100 до 600
        std::cout << "Банк готов купить " << products_for_sale << " шт. готовой продукции по цене " << product_price << " валюты за шт.\n";
    }




    void processAuctions() {
        // Process buy offers
        while (raw_materials_for_sale > 0 && !auction_buy_offers.empty()) {

            auto best_buy_offer = std::min_element(auction_buy_offers.begin(), auction_buy_offers.end(),
                [this](const auto& a, const auto& b) {
                    if (a.second.second == b.second.second) {
                        if (a.first == priority_player_id) return true;
                        if (b.first == priority_player_id) return false;
                        return (a.first - priority_player_id) % 4 < (b.first - priority_player_id) % 4; // Closest to priority player
                    }
                    return a.second.second > b.second.second; // Higher price is better
                });

            int player_id = best_buy_offer->first;
            int quantity = best_buy_offer->second.first;
            int price = best_buy_offer->second.second;

            if (quantity <= raw_materials_for_sale) {
                players[player_id].raw_material += quantity;
                players[player_id].money -= price * quantity;
                raw_materials_for_sale -= quantity;
                std::cout << "Player " << player_id << " bought " << quantity << " raw materials for " << price * quantity << " currency." << std::endl;
            }

            auction_buy_offers.erase(best_buy_offer->first);
        }

        // Process sell offers
        while (products_for_sale > 0 && !auction_buy_offers.empty()) {

            auto best_sell_offer = std::min_element(auction_sell_offers.begin(), auction_sell_offers.end(),
                [this](const auto& a, const auto& b) {
                    if (a.second.second == b.second.second) {
                        if (a.first == priority_player_id) return true;
                        if (b.first == priority_player_id) return false;
                        return a.first < b.first; // Closest to priority player
                    }
                    return a.second.second < b.second.second; // Lower price is better
                });

            int player_id = best_sell_offer->first;
            int quantity = best_sell_offer->second.first;
            int price = best_sell_offer->second.second;

            if (quantity <= products_for_sale) {
                players[player_id].products -= quantity;
                players[player_id].money += price * quantity;
                products_for_sale -= quantity;
                std::cout << "Player " << player_id << " sold " << quantity << " products for " << price * quantity << " currency." << std::endl;
            }

            auction_sell_offers.erase(best_sell_offer);
        }

        auction_buy_offers.clear();
        auction_sell_offers.clear();
    }


    void makeMaterial(int player_id, int material) {

        if (material > players[player_id].raw_material) {
            std::cout << "Not enough raw material" << std::endl;
        }

        int auto_processing = 0, default_processing = 0;
        int automated_factories_temp = players[player_id].automated_factories;

        while (automated_factories_temp > 0 && material > 0) {
            material -= 4;
            auto_processing += 4;
        }
        if (material < 0) {
            auto_processing += material;
        }
        players[player_id].money -= auto_processing * 20;




        int factories_temp = players[player_id].factories;

        while (factories_temp > 0 && material > 0) {
            material -= 2;
            default_processing += 2;
        }
        if (material < 0) {
            default_processing += material;
        }
        players[player_id].money -= default_processing * 50;


        players[player_id].products_processing = default_processing + auto_processing;
        players[player_id].raw_material -= players[player_id].products_processing;
    }




    void processTurn() {
        current_month++;

        bool isRandom = true;

        for (auto& player : players) {
            if (player.turns_before_credit_end > 0) {
                //player.money -= player.repayment;
                //player.credit -= player.repayment;
                player.money -= player.credit / 12;
                player.turns_before_credit_end--;
                if (player.turns_before_credit_end == 0) {
                    player.credit = 0;
                }
                std::cout << "Player " << player.id << " repaid " << player.repayment << " currency of their credit. Remaining credit: " << player.credit << std::endl;
            }

            if (player.insurance_months > 0) {
                player.insurance_months--;
                std::cout << "Player " << player.id << " has " << player.insurance_months << " months of insurance left." << std::endl;
            }

            if (player.factory_upgrade_month == 0) {
                player.money -= 1500;
                player.factories--;
                player.automated_factories++;
                std::cout << "Player " << player.id << " upgraded a factory to automated." << std::endl;
            }
            else if (player.factory_upgrade_month > 0) {
                player.factory_upgrade_month--;
            }

            chargeRent(player.id);

            if (isRandom) {
                handleRandomEvent(player.id);
                isRandom = false;
            }
        }

        // Rotate priority player
        priority_player_id = (priority_player_id + 1) % players.size();
    }

    void grantCredit(int player_id, int amount) {
        if (players[player_id].credit > 0) {
            cout << "Ó èãðîêà íîìåð " << player_id << " óæå åñòü êðåäèò\n";

        }
        else if (players[player_id].money >= amount) {
            players[player_id].credit += amount * 1.1;
            players[player_id].money += amount;
            players[player_id].repayment = players[player_id].credit / 12;
            std::cout << "Player " << player_id << " received a credit of " << amount << " currency. Total credit to repay: " << players[player_id].credit << std::endl;
        }
    }

    void insurancePayment(int player_id) {
        if (players[player_id].money >= 200) {
            players[player_id].money -= 200;
            players[player_id].insurance_months++;
            std::cout << "Player " << player_id << " paid for insurance. Total insurance months: " << players[player_id].insurance_months << std::endl;
        }
    }

    void upgradeFactory(int player_id) {
        if (players[player_id].money >= 1500 && players[player_id].factories > 0) {
            players[player_id].money -= 1500;
            players[player_id].factory_upgrade_month = 9;
            std::cout << "Player " << player_id << " started upgrading a factory. Completion in 9 months." << std::endl;
        }
    }

    void chargeRent(int player_id) {
        int rent = (players[player_id].raw_material * 20) + (players[player_id].products * 40);
        if (players[player_id].money >= rent) {
            players[player_id].money -= rent;
            std::cout << "Player " << player_id << " paid rent of " << rent << " currency." << std::endl;
        }
        else {
            std::cout << "Player " << player_id << " could not pay rent of " << rent << " currency." << std::endl;
        }
    }

    void handleRandomEvent(int player_id) {
        srand(time(0));
        int event_chance = rand() % 10;
        if (event_chance == 0) {

            int event_type = rand() % 5;

            int inheritance = 1000 + rand() % 9000;
            switch (event_type) {
            case 0:
                std::cout << "Player " << player_id << " has a birthday. Other players must gift them." << std::endl;
                for (auto& player : players) {
                    if (player.id != player_id) {
                        player.money -= 100;
                        players[player_id].money += 100;
                    }
                }
                break;
            case 1:
                if (players[player_id].insurance_months = 0) {
                    std::cout << "A factory burned down for player " << player_id << "." << std::endl;
                    if (players[player_id].factories > 0) {
                        players[player_id].factories--;
                    }
                    else if (players[player_id].automated_factories > 0) {
                        players[player_id].automated_factories--;
                    }
                }
                break;
            case 2:

                players[player_id].money += inheritance;
                std::cout << "Player " << player_id << " received an inheritance of " << inheritance << " currency." << std::endl;
                break;
            case 3:
                std::cout << "Player " << player_id << " gets a 50% discount on expenses for this turn." << std::endl;
                // Implement discount logic
                break;
            case 4:
                std::cout << "Bank crisis! Player " << player_id << " loses 500 currency." << std::endl;
                players[player_id].money -= 500;
                break;
            }
        }
    }
};