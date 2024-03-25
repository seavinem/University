#include "SStudData.h"

SStudData::SStudData() : Name(""), ID(0), Marks(vector<SMark>()) {}

SStudData::SStudData(const string& Name, const int& ID, const vector<SMark>& Marks) :
    Name(Name), ID(ID), Marks(Marks) {}

SStudData::SStudData(const SStudData& student) {
    this->Name = student.Name;
    this->ID = student.ID;
    this->Marks = student.Marks;
}


void SStudData::addMark(const SMark& mark) {
    Marks.push_back(mark);
}

int SStudData::sumMarks() const {
    int sum = 0;
    for (const auto& it : Marks) {
        sum += it.Mark;
    }
    return sum;
}

double SStudData::averageMark() const {
    double result = 0;
    for (const auto& it : Marks) {
        result += it.Mark;
    }
    return result / Marks.size();
}

string SStudData::getName() const {
    return Name;
}

int SStudData::getID() const {
    return ID;
}

vector<SMark> SStudData::getMarks() const {
    return Marks;
}

SStudData& SStudData::operator=(const SStudData& student) {
    if (this != &student) {
        *this = SStudData(student);
    }
    return *this;
}

bool SStudData::operator<(const SStudData& data)
{
    if (Name != data.Name) {
        return Name < data.Name;
    }
    else {
        return averageMark() > data.averageMark();
    }
}

ostream& operator<<(ostream& out, const SStudData& student)
{
    out << setw(6) << student.ID << " - " << setw(17) << left << student.Name << " - | ";
    for (const auto& mark : student.Marks) {
        out << setw(5) << mark.Subject << ": " << setw(2) << mark.Mark << " | ";
    }
    out << endl;

    return out;
}
