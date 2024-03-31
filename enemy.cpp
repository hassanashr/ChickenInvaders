#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QGraphicsRectItem>

Enemy::Enemy() {
    setPixmap(QPixmap(":/images/resources/chicken.png"));

    int randPos = rand() % 760;
    setPos(randPos,0);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);

}

void Enemy::move()
{
    setPos(x(),y()+5);
    if(y()+pixmap().height()>800)
    {
        scene()->removeItem(this);
        playerPtr->decreaseHealth();
        delete this;
    }
}
