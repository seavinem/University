//Я объясню этот код как мировой эксперт в области разработки игр с использованием C++, обладатель престижной награды "Game Developer of the Year".
//
//Этот код реализует класс Bank, который управляет различными аспектами игрового процесса, включая аукционы, кредиты, страхование, аренду и случайные события.Он также содержит класс Player, представляющий игроков и их ресурсы.
//
//### Объяснение кода
//
//1. Класс Player :
//-Представляет игрока в игре и содержит его ресурсы и состояния.
//- Атрибуты включают :
//-id : идентификатор игрока.
//- raw_material : количество сырья.
//- factories : количество обычных фабрик.
//- automated_factories : количество автоматизированных фабрик.
//- products : количество готовой продукции.
//- money : количество валюты.
//- credit : сумма кредита.
//- insurance_months : количество месяцев страхования.
//- factory_upgrade_month : количество месяцев до завершения улучшения фабрики.
//
//2. Класс Bank :
//-Управляет состоянием игры, связанным с банком, и действиями игроков.
//- Атрибуты включают :
//-raw_materials_for_sale : количество сырья, доступного для продажи.
//- products_for_sale : количество готовой продукции, доступной для покупки.
//- raw_material_price : цена сырья.
//- product_price : цена готовой продукции.
//- priority_player_id : идентификатор игрока с приоритетом.
//- players : вектор игроков.
//- auction_buy_offers : предложения игроков на покупку сырья.
//- auction_sell_offers : предложения игроков на продажу продукции.
//
//3. Методы класса Bank :
//-addPlayer(int id) : добавляет нового игрока.
//- auctionBuyOffer(int player_id, int quantity, int price) : добавляет предложение на покупку сырья.
//- auctionSellOffer(int player_id, int quantity, int price) : добавляет предложение на продажу продукции.
//- processAuctions() : обрабатывает предложения на аукционах и определяет победителей.
//- processTurn() : обрабатывает один ход игры, включая погашение кредитов, обработку страховок и обновление фабрик.
//- grantCredit(int player_id, int amount) : выдает кредит игроку.
//- insurancePayment(int player_id) : обрабатывает платеж за страхование.
//- upgradeFactory(int player_id) : начинает улучшение фабрики.
//- chargeRent(int player_id) : взымает арендную плату с игрока.
//- handleRandomEvent() : обрабатывает случайные события.
//
//4. Основная функция :
//-Создает объект банка и добавляет игроков.
//- Симулирует несколько ходов игры, вызывая методы банка для обработки каждого хода, включая проведение аукционов, обновление фабрик и случайные события.
//
//### Примерный ход работы
//
//1. Добавление игроков :
//
//bank.addPlayer(0);
//bank.addPlayer(1);
//bank.addPlayer(2);
//
//
//2. Симуляция ходов :
//
//for (int turn = 0; turn < 12; ++turn) {
//    bank.processTurn();
//    bank.handleRandomEvent();
//
//    // Примеры действий
//    bank.auctionBuyOffer(0, 5, 60);
//    bank.auctionSellOffer(1, 5, 80);
//
//    bank.processAuctions();
//    bank.chargeRent(0);
//    bank.chargeRent(1);
//    bank.chargeRent(2);
//
//    bank.upgradeFactory(0);
//    bank.insurancePayment(1);
//}
//
//
//### Подробности методов
//
//- processAuctions() :
//    -Определяет лучшую покупательскую и продажную оферты.
//    - Обрабатывает их и обновляет состояние игроков.
//
//    - processTurn() :
//    -Обрабатывает ежемесячные действия : погашение кредитов, уменьшение количества месяцев страхования и обновление фабрик.
//    - Переход приоритетного игрока.
//
//    - handleRandomEvent() :
//    -Случайным образом выбирает событие и применяет его к случайному игроку.
//
//    Этот код служит основой для 
// управления банковскими операциями в игре, учитывая все правила и условия, описанные в вашем вопросе.

#include "Bank.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    Bank bank(100, 100, 50, 100);

    bank.addPlayer(0);
    bank.addPlayer(1);
    bank.addPlayer(2);

    bank.getPlayers();
    cout << endl;
    cout << endl;
    cout << endl;

    // Simulate a few turns
    for (int turn = 0; turn < 12; ++turn) {
        bank.processTurn();
        bank.handleRandomEvent();

        // Example actions
        bank.auctionBuyOffer(0, 5, 60);
        bank.auctionSellOffer(1, 1, 80);

        bank.processAuctions();
        bank.chargeRent(0);
        bank.chargeRent(1);
        bank.chargeRent(2);
        bank.grantCredit(0, 228);
        bank.upgradeFactory(0);
        bank.insurancePayment(1);

        cout << endl;
        cout << endl;
        cout << endl;
        bank.getPlayers();
        cout << endl;
        cout << endl;
        cout << endl;
    }

    return 0;
}

