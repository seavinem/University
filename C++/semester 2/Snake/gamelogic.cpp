#include "gamelogic.h"

#include <QKeyEvent>
#include <QTime>
#include <QMessageBox>
#include <cstdlib>

GameLogic::GameLogic() {
    this->resize(SNAKE_WIDTH*FIELD_WIDTH, SNAKE_HEIGHT*FIELD_HEIGHT);

    this->setWindowTitle("Змейка");

    _INIT_GAME();
}

void GameLogic::timerEvent(QTimerEvent * e)
{
    Q_UNUSED(e);

    if(this->m_inGame){
        _CHECK_APPLE();
        _SNAKE_1_MOVE();
        _SNAKE_2_MOVE();
        _CHECK_FIELD_EXIT();
    }

    this->repaint();
}

void GameLogic::keyPressEvent(QKeyEvent *event)
{
    int PRESSED_KEY = event->key();

    if(PRESSED_KEY == Qt::Key_Left && m_dir_2 != Dirs::right){
        m_dir_2 = Dirs::left;
    }
    else if(PRESSED_KEY == Qt::Key_Right && m_dir_2 != Dirs::left){
        m_dir_2 = Dirs::right;
    }
    else if(PRESSED_KEY == Qt::Key_Up && m_dir_2 != Dirs::down){
        m_dir_2 = Dirs::up;
    }
    else if(PRESSED_KEY == Qt::Key_Down && m_dir_2 != Dirs::up){
        m_dir_2 = Dirs::down;
    }
    else if(PRESSED_KEY == Qt::Key_A && m_dir_1 != Dirs::right){
        m_dir_1 = Dirs::left;
    }
    else if(PRESSED_KEY == Qt::Key_D && m_dir_1 != Dirs::left){
        m_dir_1 = Dirs::right;
    }
    else if(PRESSED_KEY == Qt::Key_W && m_dir_1 != Dirs::down){
        m_dir_1 = Dirs::up;
    }
    else if(PRESSED_KEY == Qt::Key_S && m_dir_1 != Dirs::up){
        m_dir_1 = Dirs::down;
    }

}

void GameLogic::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    _DRAWING();

}


void GameLogic::_INIT_GAME(){
    this->m_inGame = true;
    this->m_dir_1 = right;
    this->m_dir_2 = left;

    m_dots_1.resize(1);

    for(int i = 0; i<m_dots_1.size(); i++){
        m_dots_1[i].setX(0);
        m_dots_1[i].setY(0);
    }

    m_dots_2.resize(1);

    for(int i = 0; i<m_dots_2.size(); i++){
        m_dots_2[i].setX(SNAKE_WIDTH);
        m_dots_2[i].setY(SNAKE_HEIGHT);
    }

    _DRAW_APPLE();

    this->DELAY = 130;
    this->TIMER_ID = startTimer(this->DELAY);
}

void GameLogic::_DRAWING()
{
    QPainter painter(this);

    if(this->m_inGame){
        painter.setBrush(this->m_colors[0]);
        painter.drawEllipse(m_apple.x() * SNAKE_WIDTH, m_apple.y() * SNAKE_HEIGHT, SNAKE_WIDTH, SNAKE_HEIGHT);

        size_t len_1 = m_dots_1.size();
        for(int i = 0; i<len_1;i++){
            if(i==0){
                painter.setBrush(this->m_colors[1]);
                painter.drawEllipse(m_dots_1[i].x() * SNAKE_WIDTH, m_dots_1[i].y() * SNAKE_HEIGHT, SNAKE_WIDTH, SNAKE_HEIGHT);
            }
            else{
                painter.setBrush(this->m_colors[2]);
                painter.drawEllipse(m_dots_1[i].x() * SNAKE_WIDTH, m_dots_1[i].y() * SNAKE_HEIGHT, SNAKE_WIDTH, SNAKE_HEIGHT);
            }
        }

        size_t len_2 = m_dots_2.size();
        for(int i = 0; i<len_2;i++){
            if(i==0){
                painter.setBrush(this->m_colors[4]);
                painter.drawEllipse(m_dots_2[i].x() * SNAKE_WIDTH, m_dots_2[i].y() * SNAKE_HEIGHT, SNAKE_WIDTH, SNAKE_HEIGHT);
            }
            else{
                painter.setBrush(this->m_colors[5]);
                painter.drawEllipse(m_dots_2[i].x() * SNAKE_WIDTH, m_dots_2[i].y() * SNAKE_HEIGHT, SNAKE_WIDTH, SNAKE_HEIGHT);
            }
        }
    }
    else{
        _GAME_OVER();
    }
}

void GameLogic::_DRAW_APPLE()
{
    QTime time = QTime::currentTime();
    srand((uint) time.msec());

    m_apple.setX(rand() % this->SNAKE_WIDTH);
    m_apple.setY(rand() % this->SNAKE_HEIGHT);

    bool isValid;

    do {
        int len = m_dots_2.size();
        for(int i = 0; i<len; i++){
            if(m_apple.x() == m_dots_2[i].x() && m_apple.y() == m_dots_2[i].y()){
                isValid = false;
                break;
            }
            else {
                isValid = true;
            }
        }

        len = m_dots_1.size();
        for(int i = 0; i<len; i++){
            if(m_apple.x() == m_dots_1[i].x() && m_apple.y() == m_dots_1[i].y()) {
                isValid = false;
                break;
            }
            else {
                isValid = true;
            }
        }

        if(!isValid) {
            m_apple.setX(rand() % this->SNAKE_WIDTH);
            m_apple.setY(rand() % this->SNAKE_HEIGHT);
        }
    }
    while(!isValid);

}

void GameLogic::_SNAKE_1_MOVE()
{
    for(int i = m_dots_1.size() - 1; i > 0; i--){
        m_dots_1[i] = m_dots_1[i-1];
    }

    switch(this->m_dir_1){
    case left:
        m_dots_1[0].rx() -= 1;
        break;
    case right:
        m_dots_1[0].rx() += 1;
        break;
    case up:
        m_dots_1[0].ry() -= 1;
        break;
    case down:
        m_dots_1[0].ry() += 1;
        break;
    }
}

void GameLogic::_SNAKE_2_MOVE()
{
    for(int i = m_dots_2.size() - 1; i > 0; i--){
        m_dots_2[i] = m_dots_2[i-1];
    }

    switch(this->m_dir_2){
    case left:
        m_dots_2[0].rx() -= 1;
        break;
    case right:
        m_dots_2[0].rx() += 1;
        break;
    case up:
        m_dots_2[0].ry() -= 1;
        break;
    case down:
        m_dots_2[0].ry() += 1;
        break;
    }
}

void GameLogic::_CHECK_FIELD_EXIT()
{
    int len_1 = m_dots_1.size();
    if(len_1>4){
        for(int i = 1; i<len_1; i++){
            if(m_dots_1[0]==m_dots_1[i]){
                this->m_inGame = false;
            }
        }
    }

    int len_2 = m_dots_2.size();
    if(len_2>4){
        for(int i = 1; i<len_2; i++){
            if(m_dots_2[0]==m_dots_2[i]){
                this->m_inGame = false;
            }
        }
    }


    if(m_dots_1[0].x() >= this->FIELD_WIDTH){
        m_dots_1[0].setX(0);
    }
    else if(m_dots_1[0].x() < 0){
        m_dots_1[0].setX(FIELD_WIDTH-1);
    }
    else if(m_dots_1[0].y() >= this->FIELD_HEIGHT){
        m_dots_1[0].setY(0);
    }
    else if(m_dots_1[0].y() < 0){
        m_dots_1[0].setY(FIELD_HEIGHT-1);
    }



    if(m_dots_2[0].x() >= this->FIELD_WIDTH){
        m_dots_2[0].setX(0);
    }
    else if(m_dots_2[0].x() < 0){
        m_dots_2[0].setX(FIELD_WIDTH-1);
    }
    else if(m_dots_2[0].y() >= this->FIELD_HEIGHT){
        m_dots_2[0].setY(0);
    }
    else if(m_dots_2[0].y() < 0){
        m_dots_2[0].setY(FIELD_HEIGHT-1);
    }


    for(int i = 0; i<len_2; i++){
        if(m_dots_1[0]==m_dots_2[i]){
            this->m_inGame = false;
        }
    }

    for(int i = 0; i<len_1; i++){
        if(m_dots_2[0]==m_dots_1[i]){
            this->m_inGame = false;
        }
    }


    if(!this->m_inGame){
        killTimer(this->TIMER_ID);
    }
}

void GameLogic::_GAME_OVER()
{
    QMessageBox msgb;
    msgb.setText("Вы проиграли!");
    msgb.exec();

    _INIT_GAME();
}

void GameLogic::_CHECK_APPLE()
{
    if(m_apple == m_dots_1[0]){
        m_dots_1.push_back(QPoint(0, 0));
        _DRAW_APPLE();
        this->DELAY -= 5;
    }
    else if(m_apple == m_dots_2[0]){
        m_dots_2.push_back(QPoint(0, 0));
        _DRAW_APPLE();
        this->DELAY -= 5;
    }
}
