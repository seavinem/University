#include "mainview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView w;
    w.resize(1200, 600);
    w.show();
    return a.exec();
}
