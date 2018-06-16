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
    void handleGenSoloChal();
    void handleGenDuoChal();
    void handleSoloComp();
    void handleDuoComp();
    void handleIcon1selected();
    void handleIcon2selected();
    void handleIcon3selected();
    void handleIcon4selected();
    void handleIcon5selected();
    void handleIcon6selected();
    void handleFinalChallenge();
private:
    Ui::MainWindow *ui;
    int on_challenge(int x, int y);
    void easyReset();
};

#endif // MAINWINDOW_H
