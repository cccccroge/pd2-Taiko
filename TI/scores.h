#ifndef SCORES_H
#define SCORES_H
#include <QLabel>


class scores
{
public:
    void addScore();
    QLabel *scorePoint = new QLabel();
    int p = 0;

private:

};

#endif // SCORES_H
