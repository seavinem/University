#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct SMark
{
    string Subject; //�������
    int Mark; //������
};

class SStudData {
    string Name; //�������
    int ID; //����� �������
    vector <SMark> Marks; //���-�� ������

public:
    SStudData();
    SStudData(const string& Name, const int& ID, const vector<SMark>& Marks);

    SStudData(const SStudData& student);

    SStudData& operator = (const SStudData& student);

    void addMark(const SMark& mark);
    int sumMarks() const;
    double averageMark() const;
    
    string getName() const;
    int getID() const;
    vector<SMark> getMarks() const;

    friend ostream& operator << (ostream& out, const SStudData& student);
};
