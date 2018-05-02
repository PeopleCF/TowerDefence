#include "bullet.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <enemy.h>
Bullet::Bullet()
{
             setPixmap(QPixmap(":/Images/Bullet.jpg"));
      QTimer *timer = new QTimer();
      connect(timer,SIGNAL(timeout()),this,SLOT(move()));
      timer->start(50);
}

void Bullet::move()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0 ; i < colliding_items.size() ; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            //return;
        }
    }
    setPos(x(),y()-10);

    if (y()<-50) {
        scene()->removeItem(this);
        delete this;
                 }

    }
