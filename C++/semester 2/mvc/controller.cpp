#include "controller.h"
#include "mainview.h"

Controller::Controller(MainView *view, QObject *parent) : QObject(parent), view(view) {
    model = new Model(this);
}

void Controller::handleSearch(const QString &query) {
    QList<QList<QString>> results = model->searchPatient(query);
    view->displayResults(results);
}
