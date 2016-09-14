#ifndef MYSNAKE_H
#define MYSNAKE_H

#include <QObject>
#include<QPoint>
#include<QTimer>
#include<QRectF>
class mysnake : public QObject
{
public:
    mysnake();
    QRectF food;
    QList<QRectF>m_posList;
    bool snake_update(int index);
    int control();
    void drawfood();
    void init_snake();

};

#endif // MYSNAKE_H
