#include "drum.h"
#include <QGraphicsScene>
#include <QTimer>
#include <time.h>

drum::drum()
{
    drumtype = 0;

    /*sc->scorePoint->setNum(sc->p);
    scene()->addWidget(sc->scorePoint);
    sc->scorePoint->setGeometry(385,15,50,15);
    sc->scorePoint->setAttribute((Qt::WA_TranslucentBackground));
    QFont font("", 14.5, QFont::Bold);
    sc->scorePoint->setFont(font);*/
}

void drum::generate()
{
    //create drum
    drum *ko = new drum();
    scene()->addItem(ko);
    srand(time(NULL));
    ko->drumtype = rand()%2;
    if(ko->drumtype == 0) ko->setPixmap(QPixmap(":/red.png"));
    if(ko->drumtype == 1) ko->setPixmap(QPixmap(":/blue.png"));
    ko->setPos(490, 97);

    //make Drum focusable
    ko->setFlag(QGraphicsItem::ItemIsFocusable);

    //make drum move left per 0.01 sec
    QTimer *timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), ko, SLOT(move()));
    timer2->start(10);

}

void drum::move()
{
    //move left 1 pixel
    setPos(x()-1,y());

    //set the drum which is at checkpoint focus
    if(pos().x() < 153 && pos().x() > 114)
    {
        setFocus();
    }

    //delete drum if out of border
    if(pos().x() < 92)
    {
        scene()->removeItem(this);
        delete this;
    }

}
void drum::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_J && drumtype == 0)
    {
        /*sc->addScore();*/
        scene()->removeItem(this);
        delete this;
    }

    if(event->key() == Qt::Key_K && drumtype == 1)
    {
        scene()->removeItem(this);
        delete this;
    }

}
