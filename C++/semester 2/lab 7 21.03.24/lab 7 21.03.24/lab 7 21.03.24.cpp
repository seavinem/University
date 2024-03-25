#include "SStudData.h"
using namespace std;




// Формирование вектора из объектов SStudData
void getStudentsInfoFromFile(vector<SStudData>& studentsInfo) {
    ifstream input("in.txt");
    string line;
    while (getline(input, line)) {

        string Name;
        int ID;
        vector<SMark> Marks;
        int pos = 0;

        Name = line.substr(0, line.find(";"));
        pos += Name.size() + 1;

        ID = stoi(line.substr(pos, line.find_first_of(";", pos)));
        pos += to_string(ID).size() + 1;

        SStudData student(Name, ID, Marks);


        line = line.substr(pos);
        while (line.find_first_not_of(",") != -1) {
            SMark mark;
            pos = 0;

            mark.Subject = line.substr(0, line.find("-"));
            pos += mark.Subject.size() + 1;

            mark.Mark = stoi(line.substr(pos, line.find(",")));

            student.addMark(mark);

            if (line.find(",") != -1) {
                line = line.substr(line.find(",") + 1);
            }
            else {
                line = "";
            }
        }
        studentsInfo.push_back(student);
    }
    input.close();
}
//void getStudentsInfoFromFile(map<int, SStudData>& sessionResults) {
//    ifstream input("in.txt");
//    string line;
//    while (getline(input, line)) {
//
//        SStudData student;
//        int pos = 0;
//
//        student.Name = line.substr(0, line.find(", "));
//        pos += student.Name.size() + 2;
//
//        student.Number = stoi(line.substr(pos, line.find_first_of(",", pos)));
//        pos += to_string(student.Number).size() + 2;
//
//        line = line.substr(pos);
//
//        while (line.find_first_not_of("|") != -1) {
//            SMark mark;
//            pos = 0;
//
//            mark.Subject = line.substr(0, line.find(":"));
//            pos += mark.Subject.size() + 2;
//
//            mark.Mark = stoi(line.substr(pos, line.find("|") - 1));
//
//            student.Marks.push_back(mark);
//
//            if (line.find("|") != -1) {
//                line = line.substr(line.find("|") + 2);
//            }
//            else {
//                line = "";
//            }
//        }
//
//        sessionResults[student.Number] = student;
//    }
//    input.close()
//}


void printStudentsSortedByNumber(const map<int, SStudData>& students)
{
    for (const auto& student : students) {
        cout << setw(6) << student.first << " - " << setw(17) << left << student.second.Name << " - | ";
        for (const auto& mark : student.second.Marks)
        {
            cout << setw(5) << mark.Subject << ": " << setw(2) << mark.Mark << " | ";
        }
        cout << endl;
    }
}

void printStudentsInfo(const map<int, SStudData>& students) {
    vector<SStudData> studentsInfo;
    int x = 1;

    for (const auto& student : students) {
        studentsInfo.push_back(student.second);
    }
    sort(studentsInfo.begin(), studentsInfo.end());

    for (const auto& student : studentsInfo)
    {
        cout << setw(4) << to_string(x) + ", " << setw(19) << student.Name + ", " << student.Number << ", " << setprecision(3) << student.averageMark() << endl;
        x++;
    }
}

void printStudentsInRange(const map<int, SStudData>& students, double min, double max) {
    if (!(min >= 1 && min <= 10) || !(max >= 1 && max <= 10)) {
        cout << "Введен недопустимый диапазон" << endl;
        return;
    }

    vector<pair<int, SStudData>> sortedByAverage(students.begin(), students.end());
    sort(sortedByAverage.begin(), sortedByAverage.end(), [](const auto& a, const auto& b) { return a.second.averageMark() > b.second.averageMark(); });

    for (const auto& student : sortedByAverage) {
        if (student.second.averageMark() >= min && student.second.averageMark() <= max)
            cout << setw(17) << student.second.Name << " - " << student.second.averageMark() << endl;
    }
}

void printStudentsBySubject(const map<int, SStudData>& students, const string& subject) {
    vector<pair<string, int>> result;

    for (const auto& student : students) {
        for (const auto& it : student.second.Marks) {
            if (it.Subject == subject) {
                result.push_back(make_pair(student.second.Name, it.Mark));
                break;
            }
        }
    }

    if (result.size() == 0) {
        cout << "В списке предметов введенного предмета нет" << endl;
        return;
    }


    sort(result.begin(), result.end(), [](const auto& a, const auto& b) { return a.second > b.second; });

    for (const auto& student : result) {
        cout << setw(17) << student.first << " - " << student.second << endl;
    }
}

void printCountStudentsBySubject(const map<int, SStudData>& students) {
    map<string, int> result;

    for (const auto& student : students) {
        for (const auto& mark : student.second.Marks)
            result[mark.Subject]++;
    }

    vector<pair<string, int>> sortedResult(result.begin(), result.end());
    sort(sortedResult.begin(), sortedResult.end(), [](const auto& a, const auto& b) { return a.second > b.second; });

    for (const auto& it : sortedResult) {
        cout << setw(5) << it.first << " - " << it.second << endl;
    }
}

double averageMarkForSubject(const map<int, SStudData>& students, const string& subject) {
    double total = 0, count = 0;

    for (const auto& student : students) {
        for (const auto& mark : student.second.Marks) {
            if (mark.Subject == subject) {
                total += mark.Mark;
                count++;
            }
        }
    }

    return total / count;
}
void printSubjectsAndAverages(const map<int, SStudData>& students) {
    map<string, double> subjectScores;
    for (const auto& student : students) {
        for (const auto& mark : student.second.Marks) {
            subjectScores[mark.Subject] = averageMarkForSubject(students, mark.Subject);
        }
    }

    vector<pair<string, double>> subjectScoresSorted(subjectScores.begin(), subjectScores.end());
    sort(subjectScoresSorted.begin(), subjectScoresSorted.end(), [](const auto& a, const auto& b) { return a.second > b.second; });

    for (const auto& subject : subjectScoresSorted)
    {
        cout << setw(5) << subject.first << " - " << subject.second << std::endl;
    }
}

void printMaxScoreStudents(const map<int, SStudData>& students) {
    int max = 0;
    multimap<string, int> result;

    for (const auto& student : students) {
        if (student.second.sumMarks() > max) {
            max = student.second.sumMarks();
        }
    }

    for (const auto& student : students) {

        if (student.second.sumMarks() == max) {
            result.emplace(student.second.Name, student.second.sumMarks());
        }
    }

    for (const auto& student : result) {
        cout << setw(17) << student.first << " - " << student.second << endl;
    }
}

void printFailedStudents(const map<int, SStudData>& students) {
    multimap<string, vector<SMark>> result;

    for (const auto& student : students) {
        vector<SMark> badMarks;

        for (const auto& mark : student.second.Marks) {
            if (mark.Mark >= 1 && mark.Mark <= 3) {
                badMarks.push_back(mark);
            }
        }
        if (badMarks.size() != 0) {
            result.emplace(student.second.Name, badMarks);
        }
    }


    if (result.size() == 0) {
        cout << "Нет неудовлетворительных отметок - все студенты успешно сдали экзамены" << endl;
        return;
    }


    for (const auto& student : result) {
        cout << setw(17) << student.first << " - | ";
        for (const auto& mark : student.second) {
            cout << setw(5) << mark.Subject << ": " << mark.Mark << " | ";
        }
        cout << endl;
    }
}


int main() {
    setlocale(LC_ALL, "ru");
    ifstream input("in.txt");

    int min = 6, max = 10;
    string subject = "ОиМП";
    map<int, SStudData> sessionResults;
    vector<SStudData> studentsInfo;


    if (!input.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }
    if (input.peek() == EOF) {
        cout << "Файл пуст" << endl;
        return 1;
    }

    string line;
    bool isEmpty = true;
    while (getline(input, line)) {
        if (line.find_first_not_of(" \n\t") != -1) {
            isEmpty = false;
            break;
        }
    }

    if (isEmpty) {
        cout << "Файл пуст" << endl;
        return 1;
    }

    input.close();



    try {
        getStudentsInfoFromFile(studentsInfo);
    }
    catch (...) {
        cout << "Информация в файле введена неверно" << endl;
        return 1;
    }

    input.close();



    cout << "Список всех студентов по номеру зачетки:" << endl << endl;
    printStudentsSortedByNumber(sessionResults);


    cout << endl << "------------------------------------------------------------------------" << endl;
    cout << endl << "Список всех студентов и их средний балл:" << endl << endl;
    printStudentsInfo(sessionResults);


    cout << endl << "------------------------------------------------------------------------" << endl;
    cout << endl << "Список студентов, средний балл которых принадлежит диапазону " << min << " - " << max << ":" << endl << endl;
    printStudentsInRange(sessionResults, min, max);


    cout << endl << "------------------------------------------------------------------------" << endl;
    cout << endl << "Cписок студентов, которые сдавали предмет " << subject << " и их баллы:" << endl << endl;
    printStudentsBySubject(sessionResults, subject);


    cout << endl << "------------------------------------------------------------------------" << endl;
    cout << endl << "Количество студентов, сдававших каждый из предмет:" << endl << endl;
    printCountStudentsBySubject(sessionResults);


    cout << endl << "------------------------------------------------------------------------" << endl;
    cout << endl << "Cредний балл для каждого предмета:" << endl << endl;
    printSubjectsAndAverages(sessionResults);


    cout << endl << "------------------------------------------------------------------------" << endl;
    cout << endl << "Cписок студентов с максимальным количеством баллов:" << endl << endl;
    printMaxScoreStudents(sessionResults);


    cout << endl << "------------------------------------------------------------------------" << endl;
    cout << endl << "Cписок студентов с неудовлетворительными оценками(1,2,3):" << endl << endl;
    printFailedStudents(sessionResults);
}

