#include <string>
#include <iostream>

enum class TreeType {
    Deciduous,
    Coniferous
};

class Tree {
public:
    Tree(const std::string& name, int age, TreeType type) :
        name_(name), age_(age), type_(type) {}

    virtual ~Tree() = default;

    virtual void printInfo() const {
        std::cout << "Name: " << name_ << std::endl;
        std::cout << "Age: " << age_ << std::endl;
        std::cout << "Type: " << (type_ == TreeType::Deciduous ? "Deciduous" : "Coniferous") << std::endl;
    }

    const std::string& getName() const { return name_; }
    int getAge() const { return age_; }
    TreeType getType() const { return type_; }

protected:
    std::string name_;
    int age_;
    TreeType type_;
};


class ForestTree : public Tree {
public:
    ForestTree(const std::string& name, int age, TreeType type, double woodAmount) :
        Tree(name, age, type), woodAmount_(woodAmount) {}

    void printInfo() const override {
        Tree::printInfo();
        std::cout << "Wood amount: " << woodAmount_ << std::endl;
    }

    double getWoodAmount() const { return woodAmount_; }

private:
    double woodAmount_;
};


class FruitTree : public Tree {
public:
    FruitTree(const std::string& name, int age, TreeType type, double harvestMass, int storageDuration) :
        Tree(name, age, type), harvestMass_(harvestMass), storageDuration_(storageDuration) {}

    void printInfo() const override {
        Tree::printInfo();
        std::cout << "Harvest mass: " << harvestMass_ << std::endl;
        std::cout << "Average storage duration: " << storageDuration_ << std::endl;
    }

    double getHarvestMass() const { return harvestMass_; }
    int getStorageDuration() const { return storageDuration_; }

private:
    double harvestMass_;
    int storageDuration_;
};



#include <vector>
#include <algorithm>

class TreeContainer {
public:
    void addTree(const Tree& tree) {
        trees_.push_back(tree);
    }

    void printTreeInfo() const {
        for (const auto& tree : trees_) {
            tree.printInfo();
            std::cout << std::endl;
        }
    }

    int countTreesByType(TreeType type) const {
        return std::count_if(trees_.begin(), trees_.end(),
            [type](const Tree& tree) { return tree.getType() == type; });
    }

    int countForestTrees() const {
        return std::count_if(trees_.begin(), trees_.end(),
            [](const Tree& tree) { return dynamic_cast<const ForestTree*>(&tree) != nullptr; });
    }

    int countFruitTrees() const {
        return std::count_if(trees_.begin(), trees_.end(),
            [](const Tree& tree) { return dynamic_cast<const FruitTree*>(&tree) != nullptr; });
    }

    void sortTrees() {
        std::sort(trees_.begin(), trees_.end(),
            [](const Tree& a, const Tree& b) {
                if (a.getName() != b.getName()) {
                    return a.getName() < b.getName();
                }
                else {
                    return a.getAge() > b.getAge();
                }
            });
    }

private:
    std::vector<Tree> trees_;
};




#include <fstream>
#include <sstream>

// ... (Tree, ForestTree, FruitTree, TreeContainer class definitions)

int main() {
    TreeContainer container;

    std::ifstream file("trees.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string type, name, treeTstring;
            int age;
            TreeType treeType;

            iss >> type >> name >> age >> treeTstring;
            
            if (treeTstring == "Deciduous") {
                treeType = TreeType::Deciduous;
            }
            else if (treeTstring == "Coniferous") {
                treeType = TreeType::Coniferous;
            }
            else {
                throw _exception();
            }

            if (type == "ForestTree") {
                double woodAmount;
                iss >> woodAmount;
                container.addTree(ForestTree(name, age, treeType, woodAmount));
            }
            else if (type == "FruitTree") {
                double harvestMass;
                int storageDuration;
                iss >> harvestMass >> storageDuration;
                container.addTree(FruitTree(name, age, treeType, harvestMass, storageDuration));
            }
        }
    }
    else {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Print tree information
    container.printTreeInfo();

    // Count trees by type and kind
    std::cout << "Number of deciduous trees: " << container.countTreesByType(TreeType::Deciduous) << std::endl;
    std::cout << "Number of coniferous trees: " << container.countTreesByType(TreeType::Coniferous) << std::endl;
    // ... (Similarly for coniferous, forest, and fruit trees)

    // Sort trees and print again
    container.sortTrees();
    container.printTreeInfo();

    return 0;
}