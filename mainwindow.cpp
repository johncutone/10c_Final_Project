#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    p6(new QGraphicsEllipseItem)
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
    connect(ui->duo_chal_button, SIGNAL (released()), this, SLOT (handleGenDuoChal()));
    connect(ui->solo_chal_comp, SIGNAL (clicked()), this , SLOT (handleSoloComp()));
    connect(ui->duo_chal_comp, SIGNAL (clicked()), this , SLOT (handleDuoComp()));
    connect(ui->player1_turn, SIGNAL (clicked()), this, SLOT (handleIcon1selected()));
    connect(ui->player2_turn, SIGNAL (clicked()), this, SLOT (handleIcon2selected()));
    connect(ui->player3_turn, SIGNAL (clicked()), this, SLOT (handleIcon3selected()));
    connect(ui->player4_turn, SIGNAL (clicked()), this, SLOT (handleIcon4selected()));
    connect(ui->player5_turn, SIGNAL (clicked()), this, SLOT (handleIcon5selected()));
    connect(ui->player6_turn, SIGNAL (clicked()), this, SLOT (handleIcon6selected()));
    connect(ui->fin_chal_button, SIGNAL (released()), this, SLOT (handleFinalChallenge()));

    // connect start turn button
    connect(ui->roll_button, SIGNAL (released()), this, SLOT (handleTakeTurn()));

    ui->view->setScene(scene);
   // ui->walks_num->text.toInt()

}

// handles the start of a turn feature
void MainWindow::handleTakeTurn()
{
    // generate number of walks
    int walks = (rand() % 12) + 1;
    ui->walks_num->setText(QString::number(walks));

    // generate chance of drinking
    int drink = (rand() % 2);
    if (drink == 1)
        ui->drink_lab->setText("Drink!!!");
    else ui->drink_lab->setText("Not this time...");

    // reset board
    easyReset();
}
// generate solo challenge button
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
            case 0: ui->solo_chal_text->setText("Iaodd River challenge 1");
                    dummy = nullptr;
                    return;
            case 1: ui->solo_chal_text->setText("Iaodd River challenge 2");
                    dummy = nullptr;
                    return;
            case 2: ui->solo_chal_text->setText("Iaodd River challenge 3");
                    dummy = nullptr;
                    return;
            case 3: ui->solo_chal_text->setText("Iaodd River challenge 4");
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
            case 0: ui->solo_chal_text->setText("Jug Town challenge 1");
                    dummy = nullptr;
                    return;
            case 1: ui->solo_chal_text->setText("Jug Town challenge 2");
                    dummy = nullptr;
                    return;
            case 2: ui->solo_chal_text->setText("Jug Town challenge 3");
                    dummy = nullptr;
                    return;
            case 3: ui->solo_chal_text->setText("Jug Town challenge 4");
                    dummy = nullptr;
                    return;
        }
    }
    dummy = nullptr;
}
// generate duo challenge button
void MainWindow::handleGenDuoChal()
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
    if(on_challenge(dummy->x(), dummy->y()) == 1) {
        int x = rand() % 4;
        switch(x) {
            case 0: ui->duo_chal_text->setText("Gordo Ridge challenge 1");
                    dummy = nullptr;
                    return;
            case 1: ui->duo_chal_text->setText("Gordo Ridge challenge 2");
                    dummy = nullptr;
                    return;
            case 2: ui->duo_chal_text->setText("Gordo Ridge challenge 3");
                    dummy = nullptr;
                    return;
            case 3: ui->duo_chal_text->setText("Gordo Ridge challenge 4");
                    dummy = nullptr;
                    return;
        }
    }
    // Etwanet challenge
    if(on_challenge(dummy->x(), dummy->y()) == 2) {
        int x = rand() % 4;
        switch(x) {
            case 0: ui->duo_chal_text->setText("Castle challenge 1");
                    dummy = nullptr;
                    return;
            case 1: ui->duo_chal_text->setText("Castle challenge 2");
                    dummy = nullptr;
                    return;
            case 2: ui->duo_chal_text->setText("Castle challenge 3");
                    dummy = nullptr;
                    return;
            case 3: ui->duo_chal_text->setText("Castle challenge 4");
                    dummy = nullptr;
                    return;
        }
    }
    // yayah challenge
    if(on_challenge(dummy->x(), dummy->y()) == 3) {
        int x = rand() % 4;
        switch(x) {
            case 0: ui->duo_chal_text->setText("Bellawella challenge 1");
                    dummy = nullptr;
                    return;
            case 1: ui->duo_chal_text->setText("Bellawella challenge 2");
                    dummy = nullptr;
                    return;
            case 2: ui->duo_chal_text->setText("Bellawella challenge 3");
                    dummy = nullptr;
                    return;
            case 3: ui->duo_chal_text->setText("Bellawella challenge 4");
                    dummy = nullptr;
                    return;
        }
    }
    // Jug challenge
    if(on_challenge(dummy->x(), dummy->y()) == 4) {
        int x = rand() % 4;
        switch(x) {
            case 0: ui->duo_chal_text->setText("Stairs Beach challenge 1");
                    dummy = nullptr;
                    return;
            case 1: ui->duo_chal_text->setText("Stairs Beach challenge 2");
                    dummy = nullptr;
                    return;
            case 2: ui->duo_chal_text->setText("Stairs Beach challenge 3");
                    dummy = nullptr;
                    return;
            case 3: ui->duo_chal_text->setText("Stairs Beach challenge 4");
                    dummy = nullptr;
                    return;
        }
    }
    dummy = nullptr;
}
// completed solo challenge check
void MainWindow::handleSoloComp()
{
    // check appropriate players box
    if (ui->player1_turn->isChecked()) {
        // greater than 4 implies solo, othwerwise duo
        if (on_challenge(p1->x(), p1->y()) > 4) {
            ui->solo_p1->setCheckable(true);
            ui->solo_p1->setChecked(true);
        }
        return;
    }
    else if (ui->player2_turn->isChecked()) {
        // greater than 4 implies solo, othwerwise duo
        if (on_challenge(p2->x(), p2->y()) > 4) {
            ui->solo_p2->setCheckable(true);
            ui->solo_p2->setChecked(true);
        }
        return;
    }
    else if (ui->player3_turn->isChecked()) {
        // greater than 4 implies solo, othwerwise duo
        if (on_challenge(p3->x(), p3->y()) > 4) {
            ui->solo_p3->setCheckable(true);
            ui->solo_p3->setChecked(true);
        }
        return;
    }
    else if (ui->player4_turn->isChecked()) {
        // greater than 4 implies solo, othwerwise duo
        if (on_challenge(p4->x(), p4->y()) > 4) {
            ui->solo_p4->setCheckable(true);
            ui->solo_p4->setChecked(true);
        }
        else {
            ui->duo_p4->setCheckable(true);
            ui->duo_p4->setChecked(true);
        }
        return;
    }
    else if (ui->player5_turn->isChecked()) {
        // greater than 4 implies solo, othwerwise duo
        if (on_challenge(p5->x(), p5->y()) > 4) {
            ui->solo_p5->setCheckable(true);
            ui->solo_p5->setChecked(true);
        }
        return;
    }
    else if (ui->player6_turn->isChecked()) {
        // greater than 4 implies solo, othwerwise duo
        if (on_challenge(p6->x(), p6->y()) > 4) {
            ui->solo_p6->setCheckable(true);
            ui->solo_p6->setChecked(true);
        }
        return;
    }
    else return;
}
// completed duo challenge check
void MainWindow::handleDuoComp()
{
    // check appropriate players box
    if (ui->player1_turn->isChecked()) {
        // duo is 1-4
        if (on_challenge(p1->x(), p1->y()) < 5 && on_challenge(p1->x(), p1->y()) > 0) {
            ui->duo_p1->setCheckable(true);
            ui->duo_p1->setChecked(true);
        }
        return;
    }
    else if (ui->player2_turn->isChecked()) {
        // duo is 1-4
        if (on_challenge(p2->x(), p2->y()) < 5 && on_challenge(p2->x(), p2->y()) > 0) {
            ui->duo_p2->setCheckable(true);
            ui->duo_p2->setChecked(true);
        }
        return;
    }
    else if (ui->player3_turn->isChecked()) {
        // duo is 1-4
        if (on_challenge(p3->x(), p3->y()) < 5 && on_challenge(p3->x(), p3->y()) > 0) {
            ui->duo_p3->setCheckable(true);
            ui->duo_p3->setChecked(true);
        }
        return;
    }
    else if (ui->player4_turn->isChecked()) {
        // duo is 1-4
        if (on_challenge(p4->x(), p4->y()) < 5 && on_challenge(p4->x(), p4->y()) > 0) {
            ui->duo_p4->setCheckable(true);
            ui->duo_p4->setChecked(true);
        }
        return;
    }
    else if (ui->player5_turn->isChecked()) {
        // duo is 1-4
        if (on_challenge(p5->x(), p5->y()) < 5 && on_challenge(p5->x(), p5->y()) > 0) {
            ui->duo_p5->setCheckable(true);
            ui->duo_p5->setChecked(true);
        }
        return;
    }
    else if (ui->player6_turn->isChecked()) {
        // duo is 1-4
        if (on_challenge(p6->x(), p6->y()) < 5 && on_challenge(p6->x(), p6->y()) > 0) {
            ui->duo_p6->setCheckable(true);
            ui->duo_p6->setChecked(true);
        }
        return;
    }
    else return;
}
// returns the integer code of the challenge a player is on
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
// resets all features not on board or status board
void MainWindow::easyReset()
{
    ui->duo_chal_comp->setChecked(false);
    ui->solo_chal_comp->setChecked(false);
    ui->text_output->setText("");
    ui->solo_chal_text->setText("");
    ui->duo_chal_text->setText("");
    ui->final_chal_text->setText("");
}
// these handle the movement of a player and what happens when they
// move to specific places on the board
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

// these are just to reset board when switching players
void MainWindow::handleIcon1selected()
{
    easyReset();
}
void MainWindow::handleIcon2selected()
{
    easyReset();
}
void MainWindow::handleIcon3selected()
{
    easyReset();
}
void MainWindow::handleIcon4selected()
{
    easyReset();
}
void MainWindow::handleIcon5selected()
{
    easyReset();
}
void MainWindow::handleIcon6selected()
{
    easyReset();
}

// generates final challenge
// because this is a drinking game, sometimes everyone is
// ready to skip to the end. So this can be clicked accessed at any time
// or state of the board.
void MainWindow::handleFinalChallenge()
{
    int x = rand() % 10;
    switch(x) {
        case 0: ui->final_chal_text->setText("Final Challenge 1"); break;
        case 1: ui->final_chal_text->setText("Final Challenge 2"); break;
        case 2: ui->final_chal_text->setText("Final Challenge 3"); break;
        case 3: ui->final_chal_text->setText("Final Challenge 4"); break;
        case 4: ui->final_chal_text->setText("Final Challenge 5"); break;
        case 5: ui->final_chal_text->setText("Final Challenge 6"); break;
        case 6: ui->final_chal_text->setText("Final Challenge 7"); break;
        case 7: ui->final_chal_text->setText("Final Challenge 8"); break;
        case 8: ui->final_chal_text->setText("Final Challenge 9"); break;
        case 9: ui->final_chal_text->setText("Final Challenge 10"); break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
