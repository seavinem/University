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
        cout << "���: " << nameType << endl;
        cout << "��������: " << name << endl;
        cout << "�������: " << age << endl;
        cout << "���: " << (type == TreeType::Deciduous ? "�������" : "����������") << endl;
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
        Tree("������", name, age, type), woodAmount(woodAmount) {}

    void printInfo() const override {
        cout << "������ ������ -> " << endl;
        Tree::printInfo();
        cout << "���������� ���������: " << woodAmount << endl;
    }

    double getWoodAmount() const { return woodAmount; }

};

class FruitTree : public Tree {

    int harvestMass;
    int storageDuration;

public:

    FruitTree(const string& name, const int& age, const TreeType& type, const int& harvestMass, const int& storageDuration) :
        Tree("��������", name, age, type), harvestMass(harvestMass), storageDuration(storageDuration) {}

    void printInfo() const override {
        cout << "�������� ������ -> " << endl;
        Tree::printInfo();
        cout << "����� ������: " << harvestMass << endl;
        cout << "������� ����������������� ��������: " << storageDuration << endl;
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
        cout << "���������� ���������� ��������: " << coniferousCount << endl;
        cout << "���������� ������� ��������: " << deciduousCount << endl;

    }

    void countTreesByNameType() const {
        int FruitCount = 0;
        int ForestCount = 0;

        for (const auto& tree : trees) {
            if (tree->getNameType() == "������") {
                ForestCount++;
            }
            else if (tree->getNameType() == "��������") {
                FruitCount++;
            }
        }

        cout << "���������� ������ ��������: " << ForestCount << endl;
        cout << "���������� �������� ��������: " << FruitCount << endl;

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

            if (treeTstring == "�������") {
                treeType = TreeType::Deciduous;
            }
            else if (treeTstring == "����������") {
                treeType = TreeType::Coniferous;
            }
            else {
                cerr << "Error reading file: " << filename << endl;
                return;
            }


            if (nameType == "������") {
                iss >> woodAmount;
                addTree(new ForestTree(name, age, treeType, woodAmount));
            }
            else if (nameType == "��������") {
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






//if (treeTstring == "�������") {
            //    treeType = TreeType::Deciduous;
            //}
            //else if (treeTstring == "����������") {
            //    treeType = TreeType::Coniferous;
            //}
            //else {
            //    cerr << "Error reading file: " << filename << endl;
            //    return;
            //}


            //if (nameType == "������") {
            //    file >> woodAmount;
            //    addTree(new ForestTree(name, age, treeType, woodAmount));
            //}
            //else if (nameType == "��������") {
            //    file >> harvestMass >> storageDuration;
            //    addTree(new FruitTree(name, age, treeType, harvestMass, storageDuration));

            //}
            //else {
            //    cerr << "Error reading file: " << filename << endl;
            //    return;
            //}