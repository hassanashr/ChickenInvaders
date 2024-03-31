#include "gameover.h"
#include "ui_gameover.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QApplication>
#include <QTimer>
#include <QMessageBox>
#include <QGraphicsTextItem>
#include <QColor>
#include "mainwindow.h"


GameOver::GameOver(QWidget *parent, QString x, QWidget* y)
    : QDialog(parent)
    , ui(new Ui::GameOver)
{
    ui->setupUi(this);
    ui->ScoreText->setText(x);
    QWidget* w = y;
}

GameOver::~GameOver()
{
    delete ui;
}


void GameOver::on_exit_clicked()
{
    hide();
    delete this;
}

