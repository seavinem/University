#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QTableWidget>
#include <QPushButton>
#include "controller.h"

class MainView : public QWidget {
    Q_OBJECT

public:
    MainView(QWidget *parent = nullptr);
    void displayResults(const QList<QList<QString>> &results);

private slots:
    void onSearchButtonClicked();

private:
    QLineEdit *searchInput;
    QTableWidget *resultTable;
    QPushButton *searchButton;
    Controller *controller;
};

#endif // MAINVIEW_H
