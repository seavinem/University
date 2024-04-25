#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void buttonClicked();
    void clearBoard();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *currentPlayerLabel;
    QPushButton *clearButton;
    QPushButton *buttons[3][3]; // 3x3 grid of buttons
    int currentPlayer = 1;
    QTimer *timer;

    bool checkForWin();
    bool checkForDraw();
    bool endGame();
    void makeComputerMove();
};
#endif // MAINWINDOW_H
