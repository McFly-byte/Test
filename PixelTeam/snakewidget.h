#ifndef SNAKEWIDGET_H
#define SNAKEWIDGET_H

#include"snake.h"
#include <QWidget>
#include"food.h"

class SnakeWidget : public QWidget
{
    Q_OBJECT

public:
    SnakeWidget(QWidget *parent = 0);
    ~SnakeWidget();
    void paintEvent(QPaintEvent *e);
    Food food;                          //食物
    Snake * snake1;                     //蛇头
    QTimer *time;                       //计时器
    void keyPressEvent(QKeyEvent *ev);  //键盘事件
    bool EatFood();                     //判断蛇是否吃到了食物
    void start();                       //贪吃蛇游戏开始
    void stop();                        //贪吃蛇游戏结束
};

#endif //
