#include "start.h"
#include "ui_start.h"
#include <QTimer>
#include <QTime>
#include <time.h>
#include <QBrush>
#include <QImage>
#include <QPushButton>


start::start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);

    //play music at start page
    player = new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/BGM.mp3"));
    player->setVolume(50);
    player->play();
}

start::~start()
{
    delete ui;
}

void start::on_exitButton_clicked()
{
    close();
}

void start::on_startButton_clicked()
{
    //hide the start page/stop the music
    hide();
    player->stop();

    //create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 512, 381);
    scene->setBackgroundBrush(QBrush(QImage(":/gbg.png")));

    //add view to visialize scene
    view = new QGraphicsView(scene);
    view->setFixedSize(514, 386);
    view->show();

    //add label to record the score
    QLabel *score = new QLabel();
    score->setText("得分 : ");
    scene->addWidget(score);
    score->setGeometry(325,15,75,15);
    score->setAttribute(Qt::WA_TranslucentBackground);
    QFont font("", 14.5, QFont::Bold);
    score->setFont(font);




    //add label to record time
    QLabel *time = new QLabel();
    time->setText("time : ");
    scene->addWidget(time);
    time->setGeometry(325,40,75,15);
    time->setAttribute(Qt::WA_TranslucentBackground);
    time->setFont(font);

    timeLeft->setNum(t);
    scene->addWidget(timeLeft);
    timeLeft->setGeometry(385,40,75,15);
    timeLeft->setAttribute(Qt::WA_TranslucentBackground);
    timeLeft->setFont(font);

    //add start button;
    QPushButton *startButton = new QPushButton();
    startButton->setText("GO!");
    startButton->setGeometry(206,300,100,30);
    scene->addWidget(startButton);

    //connect startButton/startgame
    connect(startButton, SIGNAL(clicked()), this, SLOT(startgame()));

}

void start::startgame()
{

    //make timeLeft -1 every second
    timer2 = new QTimer();
    connect(timer2, SIGNAL(timeout()), this, SLOT(timeChange()));
    timer2->start(1000);

   /* timer3 = new QTimer();
    connect(timer3, SIGNAL(timeout()), this, SLOT(popupResult()));
    timer3->start(7000);*/

    //randomly generates drums
    QTimer *timer = new QTimer(this);
    Drum = new drum();
    scene->addItem(Drum);

    srand(time(NULL));
    connect(timer, SIGNAL(timeout()), Drum, SLOT(generate()));
    while(1){
        int time = rand()%700+700;
        timer->start(time);
        QTime mtime; // sleep minsec
        mtime.start();
        while(mtime.elapsed() < time + 100)
            QCoreApplication::processEvents();
                timer->stop();
    }
}

void start::timeChange()
{
    timeLeft->setNum(t--);
    if(t == -1)
    {
        timer2->stop();
        popupResult();
    }

}
void start::popupResult()
{
    scene->removeItem(Drum);
    delete Drum;
    dialog->setText("總分:");
    dialog->addButton("再玩一次",QMessageBox::YesRole);
    dialog->addButton("取消",QMessageBox::NoRole);
    dialog->showNormal();
}




