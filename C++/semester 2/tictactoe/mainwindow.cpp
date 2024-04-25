#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttons[0][0] = ui->field_00;
    buttons[0][1] = ui->field_01;
    buttons[0][2] = ui->field_02;
    buttons[1][0] = ui->field_10;
    buttons[1][1] = ui->field_11;
    buttons[1][2] = ui->field_12;
    buttons[2][0] = ui->field_20;
    buttons[2][1] = ui->field_21;
    buttons[2][2] = ui->field_22;

    connect(ui->field_00, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->field_01, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->field_02, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->field_10, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->field_11, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->field_12, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->field_20, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->field_21, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->field_22, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearBoard()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClicked()
{
    QPushButton *button = (QPushButton *)sender();
    if (button->text() != "" || !button || endGame()) {
        return;
    }

    button->setText(currentPlayer == 1 ? "X" : "O");

    if (checkForWin()) {
        ui->currentPlayerlabel->setText(QString("Player wins!").arg(currentPlayer));
        return;
    }
    else if(checkForDraw()) {
        ui->currentPlayerlabel->setText("Draw!");
        return;
    }

    currentPlayer = (currentPlayer == 1) ? 2 : 1;

    if (currentPlayer == 2) {
        makeComputerMove();
    }
}

void MainWindow::clearBoard()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buttons[i][j]->setText("");
        }
    }
    ui->currentPlayerlabel->setText("");
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    if(currentPlayer == 2) {
        makeComputerMove();
    }
}

bool MainWindow::checkForWin()
{
    for (int i = 0; i < 3; ++i) {
        if (buttons[i][0]->text() == buttons[i][1]->text() && buttons[i][1]->text() == buttons[i][2]->text() && buttons[i][0]->text() != "") {
            return true;
        }
        if (buttons[0][i]->text() == buttons[1][i]->text() && buttons[1][i]->text() == buttons[2][i]->text() && buttons[0][i]->text() != "") {
            return true;
        }
    }

    if (buttons[0][0]->text() == buttons[1][1]->text() && buttons[1][1]->text() == buttons[2][2]->text() && buttons[0][0]->text() != "") {
        return true;
    }
    if (buttons[0][2]->text() == buttons[1][1]->text() && buttons[1][1]->text() == buttons[2][0]->text() && buttons[0][2]->text() != "") {
        return true;
    }

    return false;
}

bool MainWindow::checkForDraw() {
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(buttons[i][j]->text() == "")
                return false;
        }
    }
    return true;
}

bool MainWindow::endGame() {
    return checkForWin() || checkForDraw();
}

void MainWindow::makeComputerMove()
{
    QVector<QPair<int, int>> availableCells;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (buttons[i][j]->text() == "") {
                availableCells.push_back(qMakePair(i, j));
            }
        }
    }

    if (!availableCells.isEmpty()) {
        srand(time(0));
        int randomIndex = rand()%(availableCells.size());
        int row = availableCells[randomIndex].first;
        int col = availableCells[randomIndex].second;
        buttons[row][col]->setText("O");

        if (checkForWin()) {
            ui->currentPlayerlabel->setText("Computer wins!");
            return;
        }
        else if(checkForDraw()) {
            ui->currentPlayerlabel->setText("Draw!");
            return;
        }
        else {
            currentPlayer = 1;
        }
    }
}
