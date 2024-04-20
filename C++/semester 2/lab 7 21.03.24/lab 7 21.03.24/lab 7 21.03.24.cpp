#include "SStudData.h"
#include <windows.h>
using namespace std;




// --------------- vector из объектов SStudData ---------------

void getStudentsInfoFromFile(vector<SStudData>& studentsInfo) {
    ifstream input("in.txt");
    string line;

    while (getline(input, line)) {

        int pos = 0;

        string Name;
        int ID;

        Name = line.substr(0, line.find(";"));
        pos += Name.size() + 1;

        ID = stoi(line.substr(pos, line.find_first_of(";", pos)));
        pos += to_string(ID).size() + 1;
        
        vector<SMark> Marks;
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

void printVectorStudents(const vector<SStudData>& students) {
    for (const auto& student : students) {
        cout << student;
    }
}

bool comparator1(SStudData a, SStudData b) {
    if (a.getName() != b.getName()) {
        return a.getName() < b.getName();
    }
    else {
        return a.getID() < b.getID();
    }
}
void printStudentsSortedByNameNumber(vector<SStudData>& students) {
    sort(students.begin(), students.end(), comparator1);

    printVectorStudents(students);
}


// --------------- map<int, SStudData>, ключ – номер зачетки ---------------

map<int, SStudData> vectorStudentsToMap(vector<SStudData>& students) {

    map<int, SStudData> sessionResults;

    for (const auto& student : students) {
        sessionResults[student.getID()] = student;
    }
    return sessionResults;
}

void printMapStudents(const map<int, SStudData>& students) {
    for (const auto& student : students) {
        cout << setw(6) << student.first << " -> " << student.second;
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
            result.emplace(student.second.getName(), student.second.sumMarks());
        }
    }

    for (const auto& student : result) {
        cout << setw(12) << student.first << " - " << student.second << endl;
    }
}

void printFailedStudents(const map<int, SStudData>& students) {
    multimap<string, vector<SMark>> result;

    for (const auto& student : students) {
        vector<SMark> badMarks;

        for (const auto& mark : student.second.getMarks()) {
            if (mark.Mark <= 2) {
                badMarks.push_back(mark);
            }
        }
        if (badMarks.size() != 0) {
            result.emplace(student.second.getName(), badMarks);
        }
    }

    if (result.size() == 0) {
        cout << "Нет неудовлетворительных отметок - все студенты успешно сдали экзамены" << endl;
        return;
    }

    for (const auto& student : result) {
        cout << setw(12) << student.first << " - | ";
        for (const auto& mark : student.second) {
            cout << setw(5) << mark.Subject << ": " << mark.Mark << " | ";
        }
        cout << endl;
    }
}


void printStudentsAverages(const map<int, SStudData>& sessionResults) {
    multimap<string, double> averages;

    for (const auto& student : sessionResults) {
        averages.emplace(student.second.getName(), student.second.averageMark());
    }


    for (const auto& student : averages) {
        cout << setw(12) << student.first << " - ";
        cout.precision(2); 
        cout << student.second;
        cout << endl;
    }
}

bool comparator2(SStudData a, SStudData b) {
    if (a.getName() != b.getName()) {
        return a.getName() < b.getName();
    }
    else {
        return a.averageMark() > b.averageMark();
    }
}
void printStudentsSortedByNameAverage(const map<int, SStudData>& students) {
    vector<SStudData> studentsInfo;

    for (const auto& student : students) {
        studentsInfo.push_back(student.second);
    }
    sort(studentsInfo.begin(), studentsInfo.end(), comparator2);


    for (const auto& student : studentsInfo) {
        cout << setw(12) << student.getName() << " ";
        cout.precision(2);
        cout << setw(4) << student.averageMark() << " " << student.getID() << endl;
    }
}

bool comparator3(SStudData a, SStudData b) {
    if (a.averageMark() != b.averageMark()) {
        return a.averageMark() > b.averageMark();
    }
    else {
        return a.getName() < b.getName();
    }
}
void printStudentsInRange(const map<int, SStudData>& students, double min, double max) {
    if (!(min >= 1 && min <= 10) || !(max >= 1 && max <= 10)) {
        cout << "Введен недопустимый диапазон" << endl;
        return;
    }

    vector<SStudData> studentsInfo;
    for (const auto& student : students) {
        if(student.second.averageMark() >= min && student.second.averageMark() <= max)
            studentsInfo.push_back(student.second);
    }

    if (studentsInfo.size() == 0) {
        cout << "В данном диапазоне нет студентов" << endl;
    }
    else {
        sort(studentsInfo.begin(), studentsInfo.end(), comparator3);

        for (const auto& student : studentsInfo) {
            cout << setw(12) << student.getName() << " ";
            cout.precision(2);
            cout << student.averageMark() << endl;
        }
    }
 
}

void printStudentsBySubject(const map<int, SStudData>& students, const string& subject) {

    multimap<string, int> studentsInfo;
    for (const auto& student : students) {
        for (const auto& mark : student.second.getMarks()) {
            if (mark.Subject == subject) {
                studentsInfo.emplace(student.second.getName(), mark.Mark);
                break;
            }
        }
    }

    if (studentsInfo.size() == 0) {
        cout << "Ни один студент не сдавал заданный предмет" << endl;
    }
    else {
        for (const auto& student : studentsInfo) {
            cout << setw(12) << student.first << " - " << student.second << endl;
        }
    }
}

void printCountStudentsBySubject(const map<int, SStudData>& students) {
    map<string, int> result;

    for (const auto& student : students) {
        for (const auto& mark : student.second.getMarks())
            result[mark.Subject]++;
    }

    for (const auto& it : result) {
        cout << setw(5) << it.first << " - " << it.second << endl;
    }
}


int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    ifstream input("in.txt");

    double min, max;
    string subject;
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

        cout << "Введите границы промежутка для поиска среднего балла студентов в диапазоне: ";
        cin >> min >> max;
        cout << "Введите название предмета для поиска студентов, сдававших его: ";
        cin >> subject;


        // ------------------------- 1) Вводом из текстового файла сформировать vector из объектов SStudData -------------------------

        cout << endl << "------------------------------------------------------------------------" << endl;
        cout << "1) Вводом из текстового файла сформировать vector из объектов SStudData" << endl << endl;

        getStudentsInfoFromFile(studentsInfo);
        printVectorStudents(studentsInfo);
        cout << endl;



        // -------------- 2) Единая сортировка объектов SStudData по убыванию фамилий, затем – по возрастанию № зачетки --------------

        cout << endl << "------------------------------------------------------------------------" << endl;
        cout << "2) Единая сортировка объектов SStudData по убыванию фамилий, затем – по возрастанию № зачетки" << endl << endl;

        printStudentsSortedByNameNumber(studentsInfo);
        cout << endl;



        // ----------------------- 3) Сформировать из vector контейнер map<int, SStudData>, ключ – номер зачетки -----------------------

        cout << endl << "------------------------------------------------------------------------" << endl;
        cout << "3) Сформировать из vector контейнер map<int, SStudData>, ключ – номер зачетки" << endl << endl;

        sessionResults = vectorStudentsToMap(studentsInfo);
        printMapStudents(sessionResults);
        cout << endl;



        // --------------------------------------- 4) Найти студента с максимальной суммой баллов ---------------------------------------
        
        cout << endl << "------------------------------------------------------------------------" << endl;
        cout << "4) Найти студента с максимальной суммой баллов" << endl << endl;

        printMaxScoreStudents(sessionResults);
        cout << endl;
        
        
        
        // --------------------------------- 5) Найти всех студентов, не сдавших сессию (хотя бы одна 2) ---------------------------------
        
        cout << endl << "------------------------------------------------------------------------" << endl;
        cout << "5) Найти всех студентов, не сдавших сессию (хотя бы одна 2)" << endl << endl;

        printFailedStudents(sessionResults);
        cout << endl;
        
        
        
        // ---------------------------------------- 6) Вычислить средний балл по каждому студенту ----------------------------------------
        
        cout << endl << "------------------------------------------------------------------------" << endl;
        cout << "6) Вычислить средний балл по каждому студенту" << endl << endl;

        printStudentsAverages(sessionResults);
        cout << endl;
        
        
        
        // ---------------- 7) Вывести список студентов в порядке возрастания фамилий, далее - по убыванию среднего балла ----------------
        
        cout << endl << "------------------------------------------------------------------------" << endl;
        cout << "7)  Вывести список студентов в порядке возрастания фамилий, далее - по убыванию среднего балла" << endl << endl;

        printStudentsSortedByNameAverage(sessionResults);
        cout << endl;
        
        
        
        // ---------------------- 8) Вывести список студентов, средний балл которых принадлежит заданному диапазону ----------------------
        
        cout << endl << "------------------------------------------------------------------------" << endl;
        cout << "8) Вывести список студентов, средний балл которых принадлежит заданному диапазону -> " << min << ".." << max << endl << endl;

        printStudentsInRange(sessionResults, min, max);
        cout << endl;
        
        
        
        // -------------------------------- 9) Вывести список студентов, которые сдавали заданный предмет --------------------------------
        
        cout << endl << "------------------------------------------------------------------------" << endl;
        cout << "9) Вывести список студентов, которые сдавали заданный предмет -> " << subject << endl << endl;

        printStudentsBySubject(sessionResults, subject);
        cout << endl;
        
        
        
        // ----------------------------------------- 10) Сколько студентов сдавало каждый предмет -----------------------------------------
        
        cout << endl << "------------------------------------------------------------------------" << endl;
        cout << "10) Сколько студентов сдавало каждый предмет" << endl << endl;

        printCountStudentsBySubject(sessionResults);
    }
    catch (...) {
        cout << "Информация в файле введена неверно" << endl;
        return 1;
    }

    input.close();



    //cout << "Список всех студентов по номеру зачетки:" << endl << endl;
    //printStudentsSortedByNumber(sessionResults);


    //cout << endl << "------------------------------------------------------------------------" << endl;
    //cout << endl << "Список всех студентов и их средний балл:" << endl << endl;
    //printStudentsInfo(sessionResults);


    //cout << endl << "------------------------------------------------------------------------" << endl;
    //cout << endl << "Список студентов, средний балл которых принадлежит диапазону " << min << " - " << max << ":" << endl << endl;
    //printStudentsInRange(sessionResults, min, max);


    //cout << endl << "------------------------------------------------------------------------" << endl;
    //cout << endl << "Cписок студентов, которые сдавали предмет " << subject << " и их баллы:" << endl << endl;
    //printStudentsBySubject(sessionResults, subject);


    //cout << endl << "------------------------------------------------------------------------" << endl;
    //cout << endl << "Количество студентов, сдававших каждый из предмет:" << endl << endl;
    //printCountStudentsBySubject(sessionResults);


    //cout << endl << "------------------------------------------------------------------------" << endl;
    //cout << endl << "Cредний балл для каждого предмета:" << endl << endl;
    //printSubjectsAndAverages(sessionResults);


    //cout << endl << "------------------------------------------------------------------------" << endl;
    //cout << endl << "Cписок студентов с максимальным количеством баллов:" << endl << endl;
    //printMaxScoreStudents(sessionResults);


    //cout << endl << "------------------------------------------------------------------------" << endl;
    //cout << endl << "Cписок студентов с неудовлетворительными оценками(1,2,3):" << endl << endl;
    //printFailedStudents(sessionResults);
}



//
//double averageMarkForSubject(const map<int, SStudData>& students, const string& subject) {
//    double total = 0, count = 0;
//
//    for (const auto& student : students) {
//        for (const auto& mark : student.second.Marks) {
//            if (mark.Subject == subject) {
//                total += mark.Mark;
//                count++;
//            }
//        }
//    }
//
//    return total / count;
//}
//void printSubjectsAndAverages(const map<int, SStudData>& students) {
//    map<string, double> subjectScores;
//    for (const auto& student : students) {
//        for (const auto& mark : student.second.Marks) {
//            subjectScores[mark.Subject] = averageMarkForSubject(students, mark.Subject);
//        }
//    }
//
//    vector<pair<string, double>> subjectScoresSorted(subjectScores.begin(), subjectScores.end());
//    sort(subjectScoresSorted.begin(), subjectScoresSorted.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
//
//    for (const auto& subject : subjectScoresSorted)
//    {
//        cout << setw(5) << subject.first << " - " << subject.second << std::endl;
//    }
//}
//
//void printMaxScoreStudents(const map<int, SStudData>& students) {
//    int max = 0;
//    multimap<string, int> result;
//
//    for (const auto& student : students) {
//        if (student.second.sumMarks() > max) {
//            max = student.second.sumMarks();
//        }
//    }
//
//    for (const auto& student : students) {
//
//        if (student.second.sumMarks() == max) {
//            result.emplace(student.second.Name, student.second.sumMarks());
//        }
//    }
//
//    for (const auto& student : result) {
//        cout << setw(17) << student.first << " - " << student.second << endl;
//    }
//}
//

