/*
#include "boss.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include "bullet.h"
#include <QLineF>
#include "game.h"
#include <QTimer>
#include <QGraphicsRectItem>
//#include <QObject>
//#include <qmath.h>
#include "enemy.h"

extern Game* game;

Boss::Boss(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //Set the grahics.
    setPixmap(QPixmap(":/pics/tpic.png"));

    //Make the polygon.
    //Will use a vector of a polygon class.

    //Create a points vector.  #include <QPointF>.  F means it can handle floats
    QVector<QPointF> points;    //Has << overloaded as a push_back from console.
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1)
           << QPoint(3,2) << QPoint(2,3) << QPoint(1,3)
           << QPoint(0,2)<< QPoint(0,1);

    //By default, a polygon is small.  Make it bigger.
    //Scale the points.
    int SCALE_FACTOR = 50;
    for (int i = 0, n = points.size(); i < n; ++i)
    {
        points[i] *= SCALE_FACTOR;
    }

    //Create a poygon from these points.  #include <QPolygonF>.
    //QPolygonF polygon(points);

    //Create the QGraphicsPolygonItem.
    attack_area = new QGraphicsPolygonItem(QPolygonF(points), this);  //this is a parent
    attack_area->setPen(QPen(Qt::DotLine));

    //Polygon not centered.  Use dx, dy to fix.
    //Move the polygon.
    //Find the center of the polygon.
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x()+65, y()+65);   //Find out your pic size

    QLineF line(poly_center, tower_center);
    attack_area->setPos(x()+line.dx(), y()+line.dy());

    //Connect a timer to attack target.
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(100);

    attack_dest = QPointF(1066,0);
}

double Boss::distanceTo(QGraphicsItem *item)
{
    QLineF line(pos(), item->pos());
    return line.length();
}

void Boss::fire()
{
    //Create a bullet
    //Create a bullet.
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+65,y()+65);
    bullet->setScale(0.20); //Wow, I figured that out fast!
    QLineF ln(QPointF(x()+65,y()+65),attack_dest);
    int angle = (-1) * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
    //Now connect in tower construcoter
}

void Boss::aquire_target()
{   //Get a list of all items colliding with attack area
    QList<QGraphicsItem*> colliding_items = attack_area->collidingItems();

    if (colliding_items.size() == 1)
    {
        has_target = false;
        return;
    }

    double closest_dist = 300;
    QPointF closest_pt = QPointF(0,0);

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        //Convert the QGraphicsItem* to Enemy*.
        Enemy* enemy = dynamic_cast<Enemy*>(colliding_items[i]);
        if (enemy)
        {
            double this_dist = distanceTo(enemy);
            if (this_dist < closest_dist)
            {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
    }
    attack_dest = closest_pt;
    fire();
}
*/
