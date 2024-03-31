#include "laser.h"
#include "enemy.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include "player.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include "gameover.h"





player::player(QWidget* w, QGraphicsView* view): w(w), view(view)
{
    score = new QGraphicsTextItem;
    score->setPlainText("Score: " + QString::number(scoreVal));
    setPos(550, 700);
    score->setPos(0,0);

    QTimer * timer =new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (systemUpdater()));
    timer->start(50);

}
void player::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Left){
        if(x() > 0) setPos(x() - 10 , y());
    }
    else if(event->key() == Qt::Key_Right){
        if(x() < 1100) setPos(x() + 10, y());
    }
    if(event->key() == Qt::Key_Up){
        if(x() > 0) setPos(x(), y()-10);
    }
    else if(event->key() == Qt::Key_Down){
        if(x() < 1100) setPos(x(), y()+10);
    }

    if(event->key() == Qt::Key_Space){
        Laser* bullet = new Laser();
        bullet->playerPtr = this;
        bullet->setPos(x() + pixmap().width()/2 - bullet->pixmap().width()/2, y());
        scene()->addItem(bullet);

        QAudioOutput* bulletOutPut = new QAudioOutput();
        bulletoutput->setVolume(50);
        QMediaPlayer* bulletAudio = new QMediaPlayer();
        bulletAudio->setAudioOutput(bulletoutput);
        bulletAudio->setSource(QUrl("qrc:/sound/resources/laser.mp3"));
        bulletAudio->play();
    }
}
void player::createEnemy()
{   Enemy * enemy = new Enemy();
    enemy->playerPtr = this;
    scene()->addItem(enemy);
}

void player::decreaseHealth(){
    if(health > 0){
        health--;
        score->setPlainText("Health: " + QString::number(health));
    }
}

int player::getHealth(){return health;}

void player::systemUpdater(){
    QList<QGraphicsItem *> colliding_items =collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i]))==typeid(Enemy)){
            scene()->removeItem(colliding_items[i]);
            decreaseHealth();
            if(health == 0){
                GameOver* gameover = new GameOver(NULL, QString::number(scoreVal), w);
                gameover->show();
                delete view;
                delete this;
                return;
            }

            delete colliding_items[i];


            return;
        }
    }
    if(health == 0){
        GameOver* gameover = new GameOver(NULL, QString::number(scoreVal), w);
        gameover->show();
        delete view;
        delete this;
        return;
    }
}

