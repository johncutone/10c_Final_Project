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

const int GORDO_CODE = 1;
const int CASTLE_CODE = 2;
const int BELLA_CODE = 3;
const int STAIRS_CODE = 4;
const int IAODD_CODE = 5;
const int ETWANET_CODE = 6;
const int YAYAH_CODE = 7;
const int JUG_CODE = 8;

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

    // Don't allow buttons to be checked manually
    ui->solo_p1->setCheckable(false);
    ui->solo_p2->setCheckable(false);
    ui->solo_p3->setCheckable(false);
    ui->solo_p4->setCheckable(false);
    ui->solo_p5->setCheckable(false);
    ui->solo_p6->setCheckable(false);
    ui->duo_p1->setCheckable(false);
    ui->duo_p2->setCheckable(false);
    ui->duo_p3->setCheckable(false);
    ui->duo_p4->setCheckable(false);
    ui->duo_p5->setCheckable(false);
    ui->duo_p6->setCheckable(false);

    // connect buttons to move functions
    connect(ui->moveRight, SIGNAL (released()), this, SLOT (handleButton_r()));
    connect(ui->moveLeft, SIGNAL (released()), this, SLOT (handleButton_l()));
    connect(ui->moveDown, SIGNAL (released()), this, SLOT (handleButton_d()));
    connect(ui->moveUp, SIGNAL (released()), this, SLOT (handleButton_u()));
    connect(ui->solo_chal_button, SIGNAL (released()), this, SLOT (handleGenSoloChal()));

    // connect start turn button
    connect(ui->roll_button, SIGNAL (released()), this, SLOT (handleTakeTurn()));

    ui->view->setScene(scene);
   // ui->walks_num->text.toInt()

}

void MainWindow::handleTakeTurn()
{
    // generate number of walks
    int walks = (rand() % 10) + 1;
    ui->walks_num->setText(QString::number(walks));

    // generate chance of drinking
    int drink = (rand() % 2);
    if (drink == 1)
        ui->drink_lab->setText("Drink!!!");
    else ui->drink_lab->setText("Not this time...");

    // reset dislpay
    ui->duo_chal_comp->setChecked(false);
    ui->solo_chal_comp->setChecked(false);
    ui->text_output->setText("");
    ui->solo_chal_text->setText("");
    ui->duo_chal_text->setText("");
}

void MainWindow::handleGenSoloChal()
{
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

    // Iaodd challenge
    if(on_challenge(dummy->x(), dummy->y()) == 5) {
        int x = rand() % 4;
        switch(x) {
            case 0: ui->solo_chal_text->setText("Iaodd challenge 1");
                    dummy = nullptr;
                    return;
            case 1: ui->solo_chal_text->setText("Iaodd challenge 2");
                    dummy = nullptr;
                    return;
            case 2: ui->solo_chal_text->setText("Iaodd challenge 3");
                    dummy = nullptr;
                    return;
            case 3: ui->solo_chal_text->setText("Iaodd challenge 4");
                    dummy = nullptr;
                    return;
        }
    }
    // Etwanet challenge
    if(on_challenge(dummy->x(), dummy->y()) == 6) {
        int x = rand() % 4;
        switch(x) {
            case 0: ui->solo_chal_text->setText("Etwanet challenge 1");
                    dummy = nullptr;
                    return;
            case 1: ui->solo_chal_text->setText("Etwanet challenge 2");
                    dummy = nullptr;
                    return;
            case 2: ui->solo_chal_text->setText("Etwanet challenge 3");
                    dummy = nullptr;
                    return;
            case 3: ui->solo_chal_text->setText("Etwanet challenge 4");
                    dummy = nullptr;
                    return;
        }
    }
    // yayah challenge
    if(on_challenge(dummy->x(), dummy->y()) == 7) {
        int x = rand() % 4;
        switch(x) {
            case 0: ui->solo_chal_text->setText("YaYah challenge 1");
                    dummy = nullptr;
                    return;
            case 1: ui->solo_chal_text->setText("YaYah challenge 2");
                    dummy = nullptr;
                    return;
            case 2: ui->solo_chal_text->setText("YaYah challenge 3");
                    dummy = nullptr;
                    return;
            case 3: ui->solo_chal_text->setText("YaYah challenge 4");
                    dummy = nullptr;
                    return;
        }
    }
    // Jug challenge
    if(on_challenge(dummy->x(), dummy->y()) == 8) {
        int x = rand() % 4;
        switch(x) {
            case 0: ui->solo_chal_text->setText("Jug challenge 1");
                    dummy = nullptr;
                    return;
            case 1: ui->solo_chal_text->setText("Jug challenge 2");
                    dummy = nullptr;
                    return;
            case 2: ui->solo_chal_text->setText("Jug challenge 3");
                    dummy = nullptr;
                    return;
            case 3: ui->solo_chal_text->setText("Jug challenge 4");
                    dummy = nullptr;
                    return;
        }
    }
}

int MainWindow::on_challenge(int x, int y)
{
    // Gordo, Castle, Bellawella, Stairs, Ioadd, Etwanet, Yayao, Jug
    if ((x >= 40 && x <= 240) && (y == -420 || y == -440))
        return GORDO_CODE;
    else if ((x >= 420 && x <= 520) && (y == -440 || y == -460))
        return CASTLE_CODE;
    else if ((x >= 500 && x <= 620) && (y == -320 || y == -340))
        return BELLA_CODE;
    else if ((x >= 480 && x <= 620) && (y == -80 || y == -100))
        return STAIRS_CODE;
    else if ((x >= 240 && x <= 380) && (y == -320 || y == -340))
        return IAODD_CODE;
    else if ((x >= 160 && x <= 260) && (y == -40 || y == -60))
        return ETWANET_CODE;
    else if ((x >= 60 && x <=140) && (y == -260 || y == -280))
        return YAYAH_CODE;
    else if ((x >= 260 && x <= 400) && (y == -200 || y == -220))
        return JUG_CODE;
    else
        return 0;
}

void MainWindow::handleButton_r() {
    // don't allow movement if no walks left
    QString text_int = ui->walks_num->text();
    int x = text_int.toInt();
    //if (x == 0) return;

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

    // check for challenge
    int chal = on_challenge(dummy->x(), dummy->y());
    if (chal > 4) {
        ui->text_output->setText("You've made it to a solo challenge!");
    }
    else if (chal > 0) {
        ui->text_output->setText("You've made it to a duo challenge!");
    }
    else
        ui->text_output->setText("");

    dummy = nullptr;
}
void MainWindow::handleButton_l() {
    // don't allow movement if no walks left
    QString text_int = ui->walks_num->text();
    int x = text_int.toInt();
    //if (x == 0) return;

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

    // check for challenge
    int chal = on_challenge(dummy->x(), dummy->y());
    if (chal > 4) {
        ui->text_output->setText("You've made it to a solo challenge!");
    }
    else if (chal > 0) {
        ui->text_output->setText("You've made it to a duo challenge!");
    }
    else
        ui->text_output->setText("");

    dummy = nullptr;
}
void MainWindow::handleButton_d() {
    // don't allow movement if no walks left
    QString text_int = ui->walks_num->text();
    int x = text_int.toInt();
    //if (x == 0) return;

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

    // check for challenge
    int chal = on_challenge(dummy->x(), dummy->y());
    if (chal > 4) {
        ui->text_output->setText("You've made it to a solo challenge!");
    }
    else if (chal > 0) {
        ui->text_output->setText("You've made it to a duo challenge!");
    }
    else
        ui->text_output->setText("");

    dummy = nullptr;
}
void MainWindow::handleButton_u() {
    // don't allow movement if no walks left
    QString text_int = ui->walks_num->text();
    int x = text_int.toInt();
    //if (x == 0) return;

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

    // check for challenge
    int chal = on_challenge(dummy->x(), dummy->y());
    if (chal > 4) {
        ui->text_output->setText("You've made it to a solo challenge!");
    }
    else if (chal > 0) {
        ui->text_output->setText("You've made it to a duo challenge!");
    }
    else
        ui->text_output->setText("");

    dummy = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}
