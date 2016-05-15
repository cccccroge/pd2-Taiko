#ifndef START_H
#define START_H

#include "drum.h"
#include <QWidget>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QMessageBox>




namespace Ui {
class start;
}

class start : public QWidget
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();


private slots:
    void on_exitButton_clicked();

    void on_startButton_clicked();

    void startgame();

    void timeChange();

    void popupResult();


private:
    Ui::start *ui;
    QMediaPlayer *player;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QMessageBox *dialog = new QMessageBox();
    drum *Drum = new drum();
    QLabel *timeLeft = new QLabel();
    int t = 7;
    QTimer *timer3;
    QTimer *timer2;


};

#endif // START_H
