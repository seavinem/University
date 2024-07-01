#include "mainview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>

MainView::MainView(QWidget *parent) : QWidget(parent), controller(new Controller(this)) {
    QVBoxLayout *mainLayout = new QVBoxLayout;

    searchInput = new QLineEdit(this);
    resultTable = new QTableWidget(this);
    searchButton = new QPushButton("Поиск", this);

    resultTable->setColumnCount(5);
    resultTable->setHorizontalHeaderLabels({"ФИО", "Палата", "Диагноз", "Перевод из палаты в палату", "Статус выписки"});
    resultTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(searchInput);
    inputLayout->addWidget(searchButton);

    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(resultTable);

    setLayout(mainLayout);

    setWindowTitle("Больница MVC");

    connect(searchButton, &QPushButton::clicked, this, &MainView::onSearchButtonClicked);
}

void MainView::onSearchButtonClicked() {
    QString query = searchInput->text();
    controller->handleSearch(query);
}

void MainView::displayResults(const QList<QList<QString>> &results) {
    resultTable->setRowCount(0);
    for (const QList<QString> &row : results) {
        int rowCount = resultTable->rowCount();
        resultTable->insertRow(rowCount);
        for (int i = 0; i < row.size(); ++i) {
            resultTable->setItem(rowCount, i, new QTableWidgetItem(row[i]));
        }
    }
}
