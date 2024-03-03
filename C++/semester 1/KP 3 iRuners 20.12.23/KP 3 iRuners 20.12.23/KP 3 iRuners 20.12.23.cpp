#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

class Rhombus {

    int a1, b1, a2, b2;

public:
    Rhombus(const int& a1, const int& b1, const int& a2, const int& b2) {
        this->a1 = a1;
        this->b1 = b1;
        this->a2 = a2;
        this->b2 = b2;
    }

    void SetA1(const int& a1) {
        this->a1 = a1;
    }
    void SetB1(const int& b1) {
        this->b1 = b1;
    }
    void SetA2(const int& a2) {
        this->a2 = a2;
    }
    void SetB2(const int& b2) {
        this->b2 = b2;
    }

    int GetA1() const {
        return this->a1;
    }
    int GetB1() const {
        return this->b1;
    }
    int GetA2() const {
        return this->a2;
    }
    int GetB2() const {
        return this->b2;
    }

    double perimeter() const {
        return 4 * sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
    }
};


int main()
{
    int N, a1, b1, a2, b2;
    vector<Rhombus> rhombuses;
    set<double> perimeters;
    
    ifstream input("in.txt");
    input >> N;

    for (int i = 0; i < N; i++) {
        input >> a1 >> b1 >> a2 >> b2;
        Rhombus romb(a1, b1, a2, b2);
        rhombuses.push_back(romb);
    }

    input.close();


    for (const auto& it : rhombuses) {
        perimeters.insert(it.perimeter());
    }


    ofstream output("out.txt");

    output << perimeters.size();

    output.close();
}