#include "enemy.h"
#include <QTimer>
#include <ctime>
#include <QDebug>
#include <stdlib.h>
Enemy::Enemy()
{
    setPos(rand()%800,0);
    setPixmap(QPixmap(":/Images/Enemy.jpg"));
    QTimer *timer = new QTimer();
    QTimer *timer1 = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
    connect(timer1,SIGNAL(timeout()),this,SLOT(moveByX()));
    timer1->start(500);
}
void Enemy::moveByX(){
    int offset = rand()%20;
    int sign = rand();
    if (sign %2 == 0) sign = 1;else sign = -1;
    setPos(x()+offset*sign,y());
}
void Enemy::move()
{
    setPos(x(),y()+10);
    if (y()>800) delete this;
}

void Enemy::shoot()
{

}
