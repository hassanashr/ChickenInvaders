#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "mainwindow.h"
#include "player.h"
namespace Ui {
class GameOver;
}

class GameOver : public QDialog
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = nullptr, QString = "", QWidget * w = NULL);
    ~GameOver();
    QString score;
    QWidget* w;

private slots:
    void on_TryAgain_clicked();

    void on_exit_clicked();

private:
    Ui::GameOver* ui;
    QGraphicsView* view;
    QGraphicsScene* scene;
    QPixmap* playerImg;
    player* ship;
};

#endif // GAMEOVER_H
