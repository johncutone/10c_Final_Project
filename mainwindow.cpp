#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "Player.h"
//#include <QGraphicsView>
//#include <QGraphicsScene>
//#include <QImage>
//#include <QBrush>
//#include <QPixmap>
//#include <QPalette>
//#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), p1(new QGraphicsEllipseItem), p2(new QGraphicsEllipseItem),
    p3(new QGraphicsEllipseItem), p4(new QGraphicsEllipseItem), p5(new QGraphicsEllipseItem),
    p6(new QGraphicsEllipseItem), player_1(new Player)
{
    ui->setupUi(this);
    //p1 = new Player();
    QGraphicsScene *scene = new QGraphicsScene();

    // add background map
    QImage *image = new QImage("C:/Users/John/myGameFolder/myGame/gameMap.png");
    QBrush *brush = new QBrush(*image);
    brush->setTransform(brush->transform()*1.45);
    ui->view->setBackgroundBrush(*brush);

    // add player icons to map
    p1->setRect(50,560,25,25);
    p1->setBrush(Qt::black);
    scene->addItem(p1);
    p2->setRect(50,560,25,25);
    p2->setBrush(Qt::red);
    scene->addItem(p2);
    p3->setRect(50,560,25,25);
    p3->setBrush(Qt::cyan);
    scene->addItem(p3);
    p4->setRect(50,560,25,25);
    p4->setBrush(Qt::gray);
    scene->addItem(p4);
    p5->setRect(50,560,25,25);
    p5->setBrush(Qt::white);
    scene->addItem(p5);
    p6->setRect(50,560,25,25);
    p6->setBrush(Qt::yellow);
    scene->addItem(p6);

    // connect buttons to move functions
    connect(ui->moveRight, SIGNAL (released()), this, SLOT (handleButton_r()));
    connect(ui->moveLeft, SIGNAL (released()), this, SLOT (handleButton_l()));
    connect(ui->moveDown, SIGNAL (released()), this, SLOT (handleButton_d()));
    connect(ui->moveUp, SIGNAL (released()), this, SLOT (handleButton_u()));


    ui->view->setScene(scene);

}

void MainWindow::handleButton_r() {
    QGraphicsEllipseItem *dummy;
    if (ui->player1_turn->isChecked())
        dummy = p1;
    else if (ui->player2_turn->isChecked())
        dummy = p2;
    else if (ui->player3_turn->isChecked())
        dummy = p3;
    else if (ui->player4_turn->isChecked())
        dummy = p4;
    else if (ui->player5_turn->isChecked())
        dummy = p5;
    else if (ui->player6_turn->isChecked())
        dummy = p6;
    else return;

    if (dummy->x() + 20 <= 620)
        dummy->moveBy(20, 0);

    dummy = nullptr;
}
void MainWindow::handleButton_l() {
    QGraphicsEllipseItem *dummy;
    if (ui->player1_turn->isChecked())
        dummy = p1;
    else if (ui->player2_turn->isChecked())
        dummy = p2;
    else if (ui->player3_turn->isChecked())
        dummy = p3;
    else if (ui->player4_turn->isChecked())
        dummy = p4;
    else if (ui->player5_turn->isChecked())
        dummy = p5;
    else if (ui->player6_turn->isChecked())
        dummy = p6;
    else return;

    if (dummy->x() - 20 >= 0)
        dummy->moveBy(-20, 0);

    dummy = nullptr;
}
void MainWindow::handleButton_d() {
    QGraphicsEllipseItem *dummy;
    if (ui->player1_turn->isChecked())
        dummy = p1;
    else if (ui->player2_turn->isChecked())
        dummy = p2;
    else if (ui->player3_turn->isChecked())
        dummy = p3;
    else if (ui->player4_turn->isChecked())
        dummy = p4;
    else if (ui->player5_turn->isChecked())
        dummy = p5;
    else if (ui->player6_turn->isChecked())
        dummy = p6;
    else return;

    if (dummy->y() + 20 <= 0)
        dummy->moveBy(0, 20);

    dummy = nullptr;
}
void MainWindow::handleButton_u() {
    QGraphicsEllipseItem *dummy;
    if (ui->player1_turn->isChecked())
        dummy = p1;
    else if (ui->player2_turn->isChecked())
        dummy = p2;
    else if (ui->player3_turn->isChecked())
        dummy = p3;
    else if (ui->player4_turn->isChecked())
        dummy = p4;
    else if (ui->player5_turn->isChecked())
        dummy = p5;
    else if (ui->player6_turn->isChecked())
        dummy = p6;
    else return;

    if (dummy->y() - 20 >= -460)
        dummy->moveBy(0, -20);

    dummy = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}
