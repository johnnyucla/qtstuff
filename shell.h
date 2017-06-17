#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Shell : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

    public:
        Shell();

    //Anything that has slots needs a QObject.
    public slots:
        void move();
};

#endif // BULLET_H
