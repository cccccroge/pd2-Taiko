#ifndef DRUM_H
#define DRUM_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QLabel>
#include "scores.h"



class drum : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    drum();


private slots:
    void generate();
    void move();
    void keyPressEvent(QKeyEvent *event);

private:
    int drumtype;
    //0 represent red / 1 represent blue
    scores *sc = new scores();



};

#endif // DRUM_H
