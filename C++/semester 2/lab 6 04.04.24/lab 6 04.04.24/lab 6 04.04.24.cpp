#include "Tree.h"
#include <fstream>
#include <sstream>

int main() {
    TreeContainer container;
    ifstream file("trees.txt");

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string type, name, treeTstring;
            int age;
            TreeType treeType;

            iss >> type >> name >> age >> treeTstring;

            if (treeTstring == "Хвойное") {
                treeType = TreeType::Deciduous;
            }
            else if (treeTstring == "Лиственное") {
                treeType = TreeType::Coniferous;
            }
            else {
                throw _exception();
            }

            if (type == "Лесное") {
                double woodAmount;
                iss >> woodAmount;
                container.addTree(ForestTree(name, age, treeType, woodAmount));
            }
            else if (type == "Плодовое") {
                double harvestMass;
                int storageDuration;
                iss >> harvestMass >> storageDuration;
                container.addTree(FruitTree(name, age, treeType, harvestMass, storageDuration));
            }
        }
    }
    else {
        cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Print tree information
    container.printTreeInfo();

    // Count trees by type and kind
    cout << "Number of deciduous trees: " << container.countTreesByType(TreeType::Deciduous) << std::endl;
    cout << "Number of coniferous trees: " << container.countTreesByType(TreeType::Coniferous) << std::endl;
    // ... (Similarly for coniferous, forest, and fruit trees)

    // Sort trees and print again
    container.sortTrees();
    container.printTreeInfo();

    return 0;
}