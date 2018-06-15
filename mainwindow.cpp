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
#include <random>


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

    // connect start turn button
    connect(ui->roll_button, SIGNAL (released()), this, SLOT (handleStartTurn()));


    ui->view->setScene(scene);
   // ui->walks_num->text.toInt()

}

void MainWindow::handleStartTurn()
{
    // only start turn when player is selected
    if (!ui->player1_turn->isChecked()) return;
    // generate number of walks
    int walks = (rand() % 10) + 1;
    ui->walks_num->setText(QString::number(walks));

    // generate chance of drinking
    int drink = (rand() % 2);
    if (drink == 1)
        ui->drink_lab->setText("Drink!!!");
    else ui->drink_lab->setText("Not this time...");
}

void MainWindow::handleButton_r() {
    // don't allow movement if no walks left
    QString text_int = ui->walks_num->text();
    int x = text_int.toInt();
    if (x == 0) return;

    // set dummy to pointer of player whos turn it is
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

    qDebug() << "old position: (" << dummy->x() << ", " << dummy->y() << ") \n";

    // move icon
    if (dummy->x() + 20 <= 620) {
        dummy->moveBy(20, 0);
        // subtract one from walks
        text_int = ui->walks_num->text();
        x = text_int.toInt() - 1;
        if (x >= 0) ui->walks_num->setText(QString::number(x));
    }

    qDebug() << "new position: (" << dummy->x() << ", " << dummy->y() << ") \n";

    dummy = nullptr;
}
void MainWindow::handleButton_l() {
    // don't allow movement if no walks left
    QString text_int = ui->walks_num->text();
    int x = text_int.toInt();
    if (x == 0) return;

    // set dummy to correct player icon
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

    qDebug() << "old position: (" << dummy->x() << ", " << dummy->y() << ") \n";

    // move player icon
    if (dummy->x() - 20 >= 0) {
        dummy->moveBy(-20, 0);
        // subtract one from walks
        text_int = ui->walks_num->text();
        x = text_int.toInt() - 1;
        if (x >= 0) ui->walks_num->setText(QString::number(x));
    }

    qDebug() << "new position: (" << dummy->x() << ", " << dummy->y() << ") \n";

    dummy = nullptr;
}
void MainWindow::handleButton_d() {
    // don't allow movement if no walks left
    QString text_int = ui->walks_num->text();
    int x = text_int.toInt();
    if (x == 0) return;

    // set dummy to correct player icon
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

    qDebug() << "old position: (" << dummy->x() << ", " << dummy->y() << ") \n";

    // move player icon
    if (dummy->y() + 20 <= 0) {
        dummy->moveBy(0, 20);
        // subtract one from walks
        text_int = ui->walks_num->text();
        x = text_int.toInt() - 1;
        if (x >= 0) ui->walks_num->setText(QString::number(x));
    }

    qDebug() << "new position: (" << dummy->x() << ", " << dummy->y() << ") \n";

    dummy = nullptr;
}
void MainWindow::handleButton_u() {
    // don't allow movement if no walks left
    QString text_int = ui->walks_num->text();
    int x = text_int.toInt();
    if (x == 0) return;

    // set dummy to correct player icon
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

    qDebug() << "old position: (" << dummy->x() << ", " << dummy->y() << ") \n";

    // move player icon
    if (dummy->y() - 20 >= -460) {
        dummy->moveBy(0, -20);
        // subtract one from walks
        text_int = ui->walks_num->text();
        x = text_int.toInt() - 1;
        if (x >= 0) ui->walks_num->setText(QString::number(x));
    }

    qDebug() << "new position: (" << dummy->x() << ", " << dummy->y() << ") \n";

    dummy = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}
