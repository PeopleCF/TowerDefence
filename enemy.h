#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <ctime>
class Enemy:public QObject,public QGraphicsPixmapItem
{
 Q_OBJECT
private:
    time_t CreationMoment;
public:
    Enemy();
public slots:
    void move();
    void shoot();
    void moveByX();
};

#endif // ENEMY_H
