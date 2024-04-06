#pragma once
#include <string>
#include <iostream>
using namespace std;

enum class TreeType {
    Deciduous,
    Coniferous
};


class Tree {

protected:

    string name;
    int age;
    TreeType type;

public:

    Tree(const string& name, const int& age, const TreeType& type) :
        name(name), age(age), type(type) {}

    virtual ~Tree() = default;

    virtual void printInfo() const {
        cout << "Название: " << name << std::endl;
        cout << "Возраст: " << age << std::endl;
        cout << "Тип: " << (type == TreeType::Deciduous ? "хвойное" : "лиственное") << endl;
    }

    string getName() const { return name; }
    int getAge() const { return age; }
    TreeType getType() const { return type; }

};



class ForestTree : public Tree {
    
    double woodAmount;

public:

    ForestTree(const string& name, const int& age, const TreeType& type, const double& woodAmount) :
        Tree(name, age, type), woodAmount(woodAmount) {}

    void printInfo() const override {
        cout << "Лесное дерево -> " << endl;
        Tree::printInfo();
        cout << "Количество древесины: " << woodAmount << endl;
    }

    double getWoodAmount() const { return woodAmount; }

};

class FruitTree : public Tree {

    double harvestMass;
    int storageDuration;

public:

    FruitTree(const string& name, const int& age, const TreeType& type, const double& harvestMass, const int& storageDuration) :
        Tree(name, age, type), harvestMass(harvestMass), storageDuration(storageDuration) {}

    void printInfo() const override {
        cout << "Плодовое дерево -> " << endl;
        Tree::printInfo();
        cout << "Масса урожая: " << harvestMass << endl;
        cout << "Средняя продолжительность хранения: " << storageDuration << endl;
    }

    double getHarvestMass() const { return harvestMass; }
    int getStorageDuration() const { return storageDuration; }

};


#include <vector>
#include <algorithm>

class TreeContainer {
    
    vector<Tree> trees;

public:

    void addTree(const Tree& tree) {
        trees.push_back(tree);
    }

    void printTreeInfo() const {
        for (const auto& tree : trees) {
            tree.printInfo();
            cout << endl;
        }
    }

    int countTreesByType(TreeType type) const {
        int count = 0;

        for (const auto& tree : trees) {
            if (tree.getType() == type) {
                count++;
            }
        }

        return count;
    }

    int countForestTrees() const {
        int count = 0;

        for (const auto& tree : trees) {
            if (dynamic_cast<const ForestTree*>(&tree) != nullptr) {
                count++;
            }
        }

        return count;
    }

    int countFruitTrees() const {
        int count = 0;

        for (const auto& tree : trees) {
            if (dynamic_cast<const FruitTree*>(&tree) != nullptr) {
                count++;
            }
        }

        return count;
    }

    void sortTrees() {
        sort(trees.begin(), trees.end(), [](const Tree& a, const Tree& b) {
                if (a.getName() != b.getName()) {
                    return a.getName() < b.getName();
                }
                else {
                    return a.getAge() > b.getAge();
                }
            });
    }

};