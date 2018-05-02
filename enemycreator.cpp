#include "enemycreator.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
EnemyCreator::EnemyCreator()
{
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(CreateEnemy()));
    //connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(1000);
}
void EnemyCreator::CreateEnemy(){
    Enemy * enemy =  new Enemy();
    scene()->addItem(enemy);
}
