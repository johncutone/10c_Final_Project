#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QImage>
#include <QBrush>
#include "Player.h"
#include <QGraphicsEllipseItem>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //QGraphicsView *view;
    //QGraphicsScene *scene;
    Player *player_1;
    QGraphicsEllipseItem *p1;
    QGraphicsEllipseItem *p2;
    QGraphicsEllipseItem *p3;
    QGraphicsEllipseItem *p4;
    QGraphicsEllipseItem *p5;
    QGraphicsEllipseItem *p6;

private slots:
    void handleButton_r();
    void handleButton_l();
    void handleButton_u();
    void handleButton_d();
    void handleTakeTurn();
private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
