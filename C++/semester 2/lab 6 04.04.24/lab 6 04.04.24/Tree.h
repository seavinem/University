#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

enum class TreeType {
    Deciduous,
    Coniferous
};


class Tree {

protected:

    string nameType;
    string name;
    int age;
    TreeType type;

public:

    Tree(const string& nameType, const string& name, const int& age, const TreeType& type) :
        nameType(nameType), name(name), age(age), type(type) {}

    virtual ~Tree() = default;

    virtual void printInfo() const {
        cout << "Вид: " << nameType << endl;
        cout << "Название: " << name << endl;
        cout << "Возраст: " << age << endl;
        cout << "Тип: " << (type == TreeType::Deciduous ? "хвойное" : "лиственное") << endl;
    }

    string getName() const { return name; }
    string getNameType() const { return nameType; }
    int getAge() const { return age; }
    TreeType getType() const { return type; }

};




class ForestTree : public Tree {
    
    double woodAmount;

public:

    ForestTree(const string& name, const int& age, const TreeType& type, const double& woodAmount) :
        Tree("Лесное", name, age, type), woodAmount(woodAmount) {}

    void printInfo() const override {
        cout << "Лесное дерево -> " << endl;
        Tree::printInfo();
        cout << "Количество древесины: " << woodAmount << endl;
    }

    double getWoodAmount() const { return woodAmount; }

};

class FruitTree : public Tree {

    int harvestMass;
    int storageDuration;

public:

    FruitTree(const string& name, const int& age, const TreeType& type, const int& harvestMass, const int& storageDuration) :
        Tree("Плодовое", name, age, type), harvestMass(harvestMass), storageDuration(storageDuration) {}

    void printInfo() const override {
        cout << "Плодовое дерево -> " << endl;
        Tree::printInfo();
        cout << "Масса урожая: " << harvestMass << endl;
        cout << "Средняя продолжительность хранения: " << storageDuration << endl;
    }

    double getHarvestMass() const { return harvestMass; }
    int getStorageDuration() const { return storageDuration; }

};



class TreeContainer {
    
    vector<Tree*> trees;

public:

    void addTree(Tree* tree) {
        trees.push_back(tree);
    }

    void printTreesInfo() const {
        for (const auto& tree : trees) {
            tree->printInfo();
            cout << endl;
        }
    }

    void countTreesByType() const {
        int coniferousCount = 0;
        int deciduousCount = 0;
        for (const auto& tree : trees) {
            if (tree->getType() == TreeType::Coniferous) {
                coniferousCount++;
            }
            else if (tree->getType() == TreeType::Deciduous) {
                deciduousCount++;
            }
        }
        cout << "Количество лиственных деревьев: " << coniferousCount << endl;
        cout << "Количество хвойных деревьев: " << deciduousCount << endl;

    }

    void countTreesByNameType() const {
        int FruitCount = 0;
        int ForestCount = 0;

        for (const auto& tree : trees) {
            if (tree->getNameType() == "Лесное") {
                ForestCount++;
            }
            else if (tree->getNameType() == "Плодовое") {
                FruitCount++;
            }
        }

        cout << "Количество лесных деревьев: " << ForestCount << endl;
        cout << "Количество плодовых деревьев: " << FruitCount << endl;

    }

    void sortTrees() {
        sort(trees.begin(), trees.end(), [](const Tree* a, const Tree* b) {
                if (a->getName() != b->getName()) {
                    return a->getName() < b->getName();
                }
                else {
                    return a->getAge() > b->getAge();
                }
            });
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        TreeType treeType;
        string line, name, nameType, treeTstring;
        int age, woodAmount, harvestMass, storageDuration;

        while (std::getline(file, line)) {
            istringstream iss(line);

            iss >> nameType >> name >> age >> treeTstring;

            if (treeTstring == "Хвойное") {
                treeType = TreeType::Deciduous;
            }
            else if (treeTstring == "Лиственное") {
                treeType = TreeType::Coniferous;
            }
            else {
                cerr << "Error reading file: " << filename << endl;
                return;
            }


            if (nameType == "Лесное") {
                iss >> woodAmount;
                addTree(new ForestTree(name, age, treeType, woodAmount));
            }
            else if (nameType == "Плодовое") {
                iss >> harvestMass >> storageDuration;
                addTree(new FruitTree(name, age, treeType, harvestMass, storageDuration));

            }
            else {
                cerr << "Error reading file: " << filename << endl;
                return;
            }
        }

        file.close();
    }
};






//if (treeTstring == "Хвойное") {
            //    treeType = TreeType::Deciduous;
            //}
            //else if (treeTstring == "Лиственное") {
            //    treeType = TreeType::Coniferous;
            //}
            //else {
            //    cerr << "Error reading file: " << filename << endl;
            //    return;
            //}


            //if (nameType == "Лесное") {
            //    file >> woodAmount;
            //    addTree(new ForestTree(name, age, treeType, woodAmount));
            //}
            //else if (nameType == "Плодовое") {
            //    file >> harvestMass >> storageDuration;
            //    addTree(new FruitTree(name, age, treeType, harvestMass, storageDuration));

            //}
            //else {
            //    cerr << "Error reading file: " << filename << endl;
            //    return;
            //}