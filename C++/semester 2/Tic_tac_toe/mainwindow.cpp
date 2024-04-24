#include "mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    // Получаем размер сетки от пользователя
    bool ok;
    gridSize = QInputDialog::getInt(this, "Размер сетки", "Введите размерность игрового поля:", 3, 3, 10, 1, &ok);
    if (!ok) {
        // Выход, если пользователь не ввел размер
        exit(0);
    }

    // Выбор символа игрока
    QStringList symbols = {"X", "O"};
    QString selectedSymbol = QInputDialog::getItem(this, "Выбор символа", "Выберите символ (X или O):", symbols);
    playerSymbol = selectedSymbol.at(0).toLatin1();
    computerSymbol = (playerSymbol == 'X') ? 'O' : 'X';
    playerTurn = true;

    // Инициализация сетки кнопок
    initializeGrid(gridSize);

    // Кнопка "Очистить"
    QPushButton* clearButton = new QPushButton("Очистить");
    connect(clearButton, &QPushButton::clicked, this, &MainWindow::onClearButtonClicked);

    // Основной layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(gridLayout);
    mainLayout->addWidget(clearButton);

    // Центральный виджет
    QWidget* centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            delete buttons[i][j];
        }
    }
    delete gridLayout;
}

void MainWindow::initializeGrid(int size) {
    gridLayout = new QGridLayout;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            buttons[i][j] = new QPushButton;
            buttons[i][j]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            connect(buttons[i][j], &QPushButton::clicked, this, &MainWindow::onButtonClicked);
            gridLayout->addWidget(buttons[i][j], i, j);
        }
    }
}

void MainWindow::onButtonClicked() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton->text().isEmpty()) {
        clickedButton->setText(playerTurn ? playerSymbol : computerSymbol);
        if (checkWin(playerTurn ? playerSymbol : computerSymbol)) {
            QMessageBox::information(this, "Победа!", QString("Игрок %1 победил!").arg(playerTurn ? "1" : "2"));
            onClearButtonClicked();
        } else {
            changeTurn();
            if (!playerTurn) {
                computerMove();
            }
        }
    }
}

void MainWindow::onClearButtonClicked() {
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            buttons[i][j]->setText("");
        }
    }
    changeTurn(); // Меняем очередность хода после очистки
}

void MainWindow::changeTurn() {
    playerTurn = !playerTurn;
}

bool MainWindow::checkWin(char symbol) {
    // Проверка по строкам и столбцам
    for (int i = 0; i < gridSize; ++i) {
        bool rowWin = true, colWin = true;
        for (int j = 0; j < gridSize; ++j) {
            rowWin &= (buttons[i][j]->text() == symbol);
            colWin &= (buttons[j][i]->text() == symbol);
        }
        if (rowWin || colWin) return true;
    }

    // Проверка по диагоналям
    bool diag1Win = true, diag2Win = true;
    for (int i = 0; i < gridSize; ++i) {
        diag1Win &= (buttons[i][i]->text() == symbol);
        diag2Win &= (buttons[i][gridSize - i - 1]->text() == symbol);
    }
    return diag1Win || diag2Win;
}

void MainWindow::computerMove() {
    QPushButton* emptyButton = getRandomEmptyButton();
    if (emptyButton) {
        emptyButton->setText(computerSymbol);
        if (checkWin(computerSymbol)) {
            QMessageBox::information(this, "Победа!", "Компьютер победил!");
            onClearButtonClicked();
        } else {
            changeTurn();
        }
    }
}

QPushButton* MainWindow::getRandomEmptyButton() {
    // Список пустых кнопок
    QList<QPushButton*> emptyButtons;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            if (buttons[i][j]->text().isEmpty()) {
                emptyButtons.append(buttons[i][j]);
            }
        }
    }

    // Выбор случайной пустой кнопки
    if (!emptyButtons.isEmpty()) {
        int randomIndex = QRandomGenerator::global()->bounded(emptyButtons.size());
        return emptyButtons.at(randomIndex);
    }
    return nullptr; // Если нет пустых кнопок
}
