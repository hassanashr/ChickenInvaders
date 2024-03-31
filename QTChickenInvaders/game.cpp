#include "game.h"
#include <QImage>
#include <QMessageBox>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>
#include <QMediaPlayer>


extern Game* game;

Game::Game() {
    setFixedSize(800, 600);
    setBackgroundBrush(QBrush(QImage(":/images/img/bg_img.jpg")));

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0, 800, 600);

    player = new Player();
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    score = new Score();
    scene->addItem(score);

    int playerLength = 100;
    player->setPos(width()/2 - playerLength/2, height() - playerLength);

    health = new Health();
    health->setPos(0, 25);
    scene->addItem(health);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),player,SLOT(createEnemy()));
    timer->start(2000);
}

void Game::showGameOver() {
    int score = game->score->getScore();

    QMessageBox* msgBox = new QMessageBox();
    msgBox->setIcon(QMessageBox::Critical);
    msgBox->setWindowTitle("Game Over!");
    msgBox->setText("Score:" + QString::number(score));

    QFont font;
    font.setPointSize(12);
    msgBox->setFont(font);

    hide();
    msgBox->exec();
}
