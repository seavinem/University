#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QPainter>
#include <QWidget>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Netherlands : public QWidget {
public:
    Netherlands(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *) override;
};

class Sweden : public QWidget {
public:
    Sweden(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *) override;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTabWidget *tabWidget;
};
#endif // MAINWINDOW_H
