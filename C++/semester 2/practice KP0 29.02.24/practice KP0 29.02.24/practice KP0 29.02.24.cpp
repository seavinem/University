#include <iostream>
#include <algorithm>
#include "Character.h"

int main() {
    setlocale(LC_ALL, "ru");


// ----------------------------- Инициаизация объектов классов Character и Wizard -----------------------------


    try {
        cout << endl << "----------------------------- Инициаизация объектов классов Character и Wizard -----------------------------" << endl;
        cout << endl;

        Character elf(Race::ELF, "Elf1", State::NORMAL, false);
        Character human(Race::HUMAN, "Human1", State::NORMAL);
        Character dwarf(Race::DWARF, "Dwarf1", State::PARALYZED, false);

        Wizard elfWizard(Race::ELF, "Elf2 (WIZARD)", 1000, 1500, 2, { Artifact::STAFF, Artifact::SPHERE });
        Wizard humanWizard(Race::HUMAN, "Human2 (WIZARD)", 700, 1000, 3, { Artifact::BOOK, Artifact::MANUAL, Artifact::TALISMAN });
        Wizard dwarfWizard(Race::DWARF, "Dwarf2 (WIZARD)", 850, 1100, 3, { Artifact::DICE, Artifact::STONE, Artifact::STAFF });


        // -------------- Вывод на экран --------------

        cout << elf << endl
            << human << endl
            << dwarf << endl
            << elfWizard << endl
            << humanWizard << endl
            << dwarfWizard << endl;


        // -------------- Копирование и присваивание --------------


        cout << endl;
        cout << endl << "----------------------------- Копирование и присваивание -----------------------------" << endl;
        cout << endl;

        Character temp = human;
        Character temp2(human);

        cout << temp << endl
            << temp2 << endl;


        // -------------- Set- и Get- методы --------------

        
        cout << endl;
        cout << endl << "----------------------------- Set- и Get- методы -----------------------------" << endl;
        cout << endl;

        human.setName("HumanFirst");
        humanWizard.setManaTotal(10000);
        elfWizard.addArtifact(Artifact::DICE);

        cout << "У объекта human изменено имя: " << human.getName() << endl
            << "У объекта humanWizard изменено максимальное количество маны: " << humanWizard.getManaTotal() << endl
            << "У объекта elf добавлен артифакт, количество артифактов: " << elfWizard.getArtifactAmmount() << endl << endl;


        // ----------------------------- Семантика перемещения -----------------------------

        cout << endl;
        cout << endl << "----------------------------- Семантика перемещения -----------------------------" << endl;
        cout << endl;

        Character human2(Race::HUMAN, "Human3", State::PARALYZED, false);
        Character human3(Race::HUMAN, "Human4", State::NORMAL, true);

        human3 = move(human2);
        cout << human3 << endl;

        Character human4(move(human3));
        cout << human4 << endl;



        // ----------------------------- Массив объектов -----------------------------

        vector<Character*> characters{ &elf, &human, &dwarf, &elfWizard, &humanWizard, &dwarfWizard };


        // -------------- Сортировка по имени --------------

        cout << endl;
        cout << endl << "----------------------------- Элементы массива персонажей ролевой игры -----------------------------" << endl;
        cout << endl;

        for (auto& character : characters) {
            cout << *character << endl;
        }

        sort(characters.begin(), characters.end(), [](const Character* a, const Character* b) { return (*a).getName() < (*b).getName(); });


        // -------------- Вывод на экран --------------

        cout << endl;
        cout << endl << "----------------------------- Элементы массива, отсортированные по имени -----------------------------" << endl;
        cout << endl;

        for (auto& character : characters) {
            cout << *character << endl;
        }


        // -------------- Подсчёт объектов каждого класса --------------

        int countEverage = 0, countWizard = 0;

        for (auto& character : characters) {

            if (dynamic_cast<Character*>(character)) {
                countEverage++;
            }
            if (dynamic_cast<Wizard*>(character)) {
                countWizard++;
            }
        }


        cout << endl;
        cout << endl << "Количество персонажей ролевой игры: " << countEverage << endl
            << "Количество персонажей, владеющих магией: " << countWizard << endl;
    }
    catch (exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}
