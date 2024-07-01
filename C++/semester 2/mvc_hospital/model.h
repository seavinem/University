#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QList>
#include <QString>

class Model : public QObject {
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);

    QList<QList<QString>> searchPatient(const QString &query);

private:
    QList<QList<QString>> loadPatientsFromFile();

    QList<QList<QString>> patients;
};

#endif // MODEL_H
