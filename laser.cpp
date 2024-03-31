#include "laser.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "enemy.h"


Laser::Laser(){
    setPixmap(QPixmap(":/images/resources/bullet.png"));

    QTimer * timer =new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);

}

void Laser::move()
{

    QList<QGraphicsItem *> colliding_items =collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i]))==typeid(Enemy)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            QAudioOutput* bulletOutPut = new QAudioOutput();
            bulletOutPut->setVolume(50);
            QMediaPlayer* bulletAudio = new QMediaPlayer();
            bulletAudio->setAudioOutput(bulletOutPut);
            bulletAudio->setSource(QUrl("qrc:/sound/resources/chicken.mp3"));
            bulletAudio->play();
            playerPtr->scorevalue++;
            return;
        }
    }

    setPos(x(),y()-10);
    if(pos().y()+30<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
