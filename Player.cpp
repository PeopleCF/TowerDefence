#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "enemy.h"

#include <QDebug>

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/BulletFire.mp3"));
    setPixmap(QPixmap(":/Images/Player.jpg"));
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
            Bullet * bullet = new Bullet();
            scene()->addItem(bullet);
            bullet->setPos(x()+50,y());
            bulletsound->setPosition(0);
            bulletsound->play();
            qDebug() <<"xx";
}
}
