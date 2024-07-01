#include "model.h"
#include <fstream>
#include <string>

Model::Model(QObject *parent) : QObject(parent) {
    patients = loadPatientsFromFile();
}

QList<QList<QString>> Model::searchPatient(const QString &query) {
    QList<QList<QString>> results;
    for (const QList<QString> &patient : patients) {
        for (const QString &info : patient) {
            if (info.contains(query, Qt::CaseInsensitive)) {
                results.append(patient);
                break;
            }
        }
    }
    return results;
}

QList<QList<QString>> Model::loadPatientsFromFile() {
    QList<QList<QString>> data;

    std::ifstream file("patients.txt");
    std::string line;
    std::string dtr = ",";

    while(getline(file, line)) {
        QList<QString> patient;

        int start = 0;
        int end = 0;

        while (line.find_first_not_of(dtr, end) != -1) {
            start = line.find_first_not_of(dtr, end);
            end = line.find_first_of(dtr, start);

            if (end != -1) {
                patient.append(QString::fromStdString(line.substr(start, end - start)));
            }
            else {
                patient.append(QString::fromStdString(line.substr(start)));
            }
        }
        data.append(patient);
    }

    return data;
}
