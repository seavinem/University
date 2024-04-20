#ifndef MENU_H
#define MENU_H

#include "gamelogic.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_QuitButton_clicked();

    void on_PlayButton_clicked();

private:
    Ui::Menu *ui;
    GameLogic* game;
};
#endif // MENU_H
