#ifndef GAMELOGIC
#define GAMELOGIC

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QPainter>
#include <QColor>

class GameLogic : public QWidget{
public:
    GameLogic();

protected:

    void timerEvent(QTimerEvent*) override;
    void keyPressEvent(QKeyEvent*) override;
    void paintEvent(QPaintEvent*) override;

private:
    static const int SNAKE_WIDTH = 20;
    static const int SNAKE_HEIGHT = 20;
    static const int FIELD_WIDTH = 40;
    static const int FIELD_HEIGHT = 40;

    int DELAY = 130;

    int TIMER_ID;

    enum Dirs{left, right, up, down};


    Dirs m_dir_1;
    Dirs m_dir_2;

    bool m_inGame;

    QVector<QPoint> m_dots_1;
    QVector<QPoint> m_dots_2;
    QVector<QColor> m_colors {Qt::red, Qt::yellow, Qt::blue, Qt::white, Qt::gray, Qt::green};

    QPoint m_apple;

    void _INIT_GAME();
    void _DRAWING();
    void _DRAW_APPLE();
    void _SNAKE_1_MOVE();
    void _SNAKE_2_MOVE();
    void _CHECK_FIELD_EXIT();
    void _GAME_OVER();
    void _CHECK_APPLE();
};

#endif // GAMELOGIC
