#include "mysnake.h"
extern int score;
mysnake::mysnake()
{
}
bool mysnake::snake_update(int index)
{
    QRectF pos;
    pos=m_posList.at(0);
    int ret=control();
    if(ret==0)
        m_posList.removeLast();
    if(ret==1)
        drawfood();
    if(ret==2)
        return false;
    switch(index)
    {
    case 1: pos.setRect(pos.x(),pos.y()-20,18,18);
                break;
    case 2: pos.setRect(pos.x(),pos.y()+20,18,18);
                break;
    case 3: pos.setRect(pos.x()-20,pos.y(),18,18);
                break;
    case 4: pos.setRect(pos.x()+20,pos.y(),18,18);
                break;
    }
    m_posList.insert(0,pos);
    return true;
}
int mysnake::control()
{
    QRectF pos=m_posList.at(0);
    if(food==pos)
      {
        score+=10;
        return 1;
    }
    if(pos.x()<30 || pos.x()>630 ||pos.y()<30 || pos.y()>310)
        return 2;
    for(int i=1;i<m_posList.size();i++)
    {
        if(pos==m_posList.at(i))
            return 2;
    }
    return 0;
}
void mysnake::drawfood()
{
    int i=qrand()%32;
    int j=qrand()%16;

        int x=640-20*i;   int y =320-20*j;
        if(x<=20) x=20;
          if(y<=20)   y=40;
    food.setRect(x,y,18,18);
}
void mysnake::init_snake()
{
    QRectF pos;
score=0;
for(int i=0;i<3;i++)
    {
        pos.setRect(60.0-i*20,40,18,18);
        m_posList.append(pos);
    }
}
