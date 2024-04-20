#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    game = new GameLogic();
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_QuitButton_clicked()
{
    this->close();
}

void Menu::on_PlayButton_clicked()
{
    game->show();
    this->close();
}

