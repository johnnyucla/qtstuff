/*
#include "bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "game.h"
#include <QGraphicsRectItem>

extern Game* game;

Bullet::Bullet()
{
    //Draw the rect.
    setRect(0,0,5,10); //(x,y,width,height)

    //Connect
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));

    timer->start(25);   //50 milli seconds
}

void Bullet::move()
{

    //Move at a straight angle
    double STEP_SIZE = 30; //Pixels
    double theta = rotation(); //Degress

    double dx = STEP_SIZE*qCos(qDegreesToRadians(theta));   //need qmath.h
    double dy = STEP_SIZE*qSin(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);


    setPos(x(),y()+10); //Don't forget, to go up, need to -10, not +10
    if (pos().y()+rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
       // qDebug() << "bullet deleted.";
    }
}
*/
