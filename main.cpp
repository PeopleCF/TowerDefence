#include <QApplication>
#include "Player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <enemycreator.h>
#include <QMediaPlayer>
/*
Tutorial Topics:
-events (keyPressEvent() and QKeyEvent)
-event propogation system
-QDebug
*/
    bool isRunning = true;
int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to add to the scene
    Player * player = new Player();


    // add the item to the scene
    scene->addItem(player);
    EnemyCreator *EC1 = new EnemyCreator;
    scene->addItem(EC1);
    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // show the view
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    player->setPos(view->width()/2,view->height() - 100);
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/BG.mp3"));
    music->play();
    view->show();
    return a.exec();
}
