#include "model.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Model::Model(QObject *parent) : QObject(parent) {
    patients = loadPatientsFromFile();
}

QList<QList<QString>> Model::searchPatient(const QString &query) {
    QList<QList<QString>> results;
    for (const QList<QString> &patient : patients) {
        if (patient[0].contains(query, Qt::CaseInsensitive)) {
            results.append(patient);
        }
    }
    return results;
}

QList<QList<QString>> Model::loadPatientsFromFile() {
    // QList<QList<QString>> data;
    // QFile file("patients.txt");
    // QTextStream in(&file);
    // while (!in.atEnd()) {
    //     QString line = in.readLine();
    //     data.append(line.split(','));
    // }
    // file.close();
    // return data;

    QList<QList<QString>> data;
    QFile file("patients.txt");
    if (!file.exists()) {
        qDebug() << "File does not exist!";
        return data;
    }

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(',');
            if (fields.size() == 4) {  // Ensure there are exactly 4 fields
                data.append(fields);
            } else {
                qDebug() << "Invalid line format: " << line;
            }
        }
        file.close();
    } else {
        qDebug() << "Failed to open file for reading!";
    }

    return data;

    // QList<QList<QString>> data = {
    //     {"John Doe","101","Flu","Admitted"},
    //     {"Jane Smith","102","Cold","Admitted"},
    //     {"Alice Johnson","103","Fracture","Discharged"},
    //     {"Bob Brown","104","Asthma","Admitted"},
    //     };
    // return data;
}
