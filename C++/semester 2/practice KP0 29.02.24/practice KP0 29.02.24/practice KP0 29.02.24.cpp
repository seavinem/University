#include <iostream>
#include "Character.h"

int main() {

    setlocale(LC_ALL, "ru");
    Character elf(Race::ELF, "first", State::NORMAL, false);
    Character human(Race::HUMAN, "second", State::NORMAL);
    Character dwarf(Race::DWARF, "third" ,State::PARALYZED);
    
    Wirard elfWizard(Race::ELF, "firstWIZARD", State::NORMAL, 1000, 1500, vector<Artifact> {Artifact::STAFF, Artifact::SPHERE});
    Wirard humanWizard (Race::HUMAN, "secondWIZARD", State::NORMAL, 700, 1000, vector<Artifact> {Artifact::BOOK, Artifact::MANUAL, Artifact::TALISMAN});
    Wirard dwarfWizard(Race::DWARF, "thirdWIZARD" ,State::PARALYZED, 850, 1100, vector<Artifact> {Artifact::DICE, Artifact::STONE, Artifact::STAFF});

    
}
