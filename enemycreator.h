#ifndef ENEMYCREATOR_H
#define ENEMYCREATOR_H
#include <QGraphicsItem>
#include <QObject>
class EnemyCreator:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    EnemyCreator();
public slots:
    void CreateEnemy();
};

#endif // ENEMYCREATOR_H
