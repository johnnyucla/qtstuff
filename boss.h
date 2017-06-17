#ifndef BOSS_H
#define BOSS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Boss : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Boss(QGraphicsItem* parent = 0);
    double distanceTo(QGraphicsItem* item);
    void fire();
public slots:

    void aquire_target();
private:
    QGraphicsPolygonItem* attack_area;
    QPointF attack_dest;    //needs to connect, so add Q_OBJECT
    bool has_target;
};

#endif // BOSS_H
