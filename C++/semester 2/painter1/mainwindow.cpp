#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tabWidget = new QTabWidget(this);
    tabWidget->addTab(new Netherlands(), "Нидерланды");
    tabWidget->addTab(new Sweden(), "Швеция");
    setCentralWidget(tabWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void Netherlands::paintEvent(QPaintEvent *) {
    QPainter painter;
    int hFlag, wFlag;
    int hSpace = 0, wSpace = 0;
    painter.begin(this);


    if(3 * height() > 2 * width()){
        hSpace = (height()-width() * 2 / 3)/2;
        wFlag = width();
        hFlag = wFlag * 2 / 3;
    }
    else {
        wSpace = (width()- height() * 3 / 2)/2;
        hFlag = height();
        wFlag = hFlag * 3 / 2;
    }

    painter.setPen(QColor(174, 28, 40));
    painter.setBrush(QBrush(QColor(174, 28, 40)));
    painter.drawRect(wSpace, hSpace, wFlag, hFlag / 3);

    painter.setPen(Qt::white);
    painter.setBrush(QBrush(Qt::white));
    painter.drawRect(wSpace, hFlag / 3 + hSpace, wFlag, hFlag / 3);

    painter.setPen(QColor(33, 70, 139));
    painter.setBrush(QBrush(QColor(33, 70, 139)));
    painter.drawRect(wSpace, hFlag * 2 / 3 + hSpace, wFlag, hFlag / 3);

    painter.end();
}

void Sweden::paintEvent(QPaintEvent*) {
    QPainter painter;
    int hFlag, wFlag;
    int hSpace = 0, wSpace = 0;
    painter.begin(this);


    if(8 * height() > 5 * width()){
        hSpace = (height()-width() * 5 / 8)/2;
        wFlag = width();
        hFlag = wFlag * 5 / 8;
    }
    else {
        wSpace = (width()- height() * 8 / 5)/2;
        hFlag = height();
        wFlag = hFlag * 8 / 5;
    }

    painter.setPen(QColor(0, 106, 167));
    painter.setBrush(QBrush(QColor(0, 106, 167)));
    painter.drawRect(wSpace, hSpace, wFlag, hFlag);

    painter.setPen(QColor(254, 204, 0));
    painter.setBrush(QBrush(QColor(254, 204, 0)));
    painter.drawRect(wSpace , hFlag * 4 / 10 + hSpace, wFlag, hFlag * 2 / 10);
    painter.drawRect(wFlag * 5 / 16 + wSpace, hSpace, wFlag * 2 / 16, hFlag);

    painter.end();
}
