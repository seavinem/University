#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_chartView = new ChartView(this);

    // Ensure the central widget has a layout
    if (!ui->centralwidget->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);
        ui->centralwidget->setLayout(layout);
    }
    ui->centralwidget->layout()->addWidget(m_chartView);

    // Example data
    QVector<int> data = {10, 20, 30, 40, 50};
    m_chartView->setData(data);
}

MainWindow::~MainWindow()
{
    delete ui;
}
