#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonClicked();
    void onClearButtonClicked();

private:
    QGridLayout* gridLayout;
    QPushButton* buttons[10][10]; // Максимальный размер сетки 10x10
    int gridSize;
    bool playerTurn; // true - игрок, false - компьютер
    QString playerSymbol, computerSymbol;

    void initializeGrid(int size);
    void changeTurn();
    bool checkWin(char symbol);
    void computerMove();
    QPushButton* getRandomEmptyButton();
};
#endif // MAINWINDOW_H
