#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "model.h"

class MainView;

class Controller : public QObject {
    Q_OBJECT

public:
    explicit Controller(MainView *view, QObject *parent = nullptr);

    void handleSearch(const QString &query);

private:
    Model *model;
    MainView *view;
};

#endif // CONTROLLER_H
