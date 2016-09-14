#include "dialog.h"
#include "ui_dialog.h"
#include<QDebug>
#include<QtGlobal>

extern int score;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    direction=2;
    ui->setupUi(this);

}
Dialog::~Dialog()
{
    delete ui;
}
void Dialog::paintEvent(QPaintEvent *event)
{

QPainter p(this);
p.fillRect(20,20,640,320,Qt::color0);
p.fillRect(10,10,10,340,Qt::color1);
p.fillRect(660,20,10,330,Qt::color1);
p.fillRect(20,340,650,10,Qt::color1);
p.fillRect(20,10,650,10,Qt::color1);

for(int i=0;i<snake.m_posList.size();i++)
    {
    if(i==0)
       p.setBrush(Qt::red);
    else
            p.setBrush(Qt::green);
                 p.drawRect(snake.m_posList.at(i));
}
p.setBrush(Qt::yellow);
p.drawRect(snake.food);
}
void Dialog::keyPressEvent(QKeyEvent *event)
{
    QKeyEvent *key=(QKeyEvent *)event;
    switch(key->key())
    {
    case Qt::Key_Up:
    {
        direction=1;
        break;
    }
    case Qt::Key_Down:
    {
        direction=2;
        break;
    }
    case Qt::Key_Left:
    {
        direction=3;
        break;
    }
    case Qt::Key_Right:
    {
        direction=4;
        break;
    }
    }
}
void Dialog::showsnake()
{


    if(snake.snake_update(direction)==false)
    {
        QMessageBox::information(NULL,"tip","game over","yes");
        m_pTimer->stop();
        ui->pushButton->setEnabled(true);
        score=0;
        ui->pushButton_2->setEnabled(true);
        return ;
    }
    ui->lcdNumber->display(score);
   if(score>=50)
    m_pTimer->start(500);
   if(score>=100)
    m_pTimer->start(200);
    repaint();
}
void Dialog::on_pushButton_clicked()
{
 snake.init_snake();
 snake.drawfood();
 score=0;
 m_pTimer=new QTimer;//首先创建一个定时器
 connect(m_pTimer,SIGNAL(timeout()),
               this,SLOT(showsnake()));//关联信号和槽函数,自定义的普通类不能使用
 m_pTimer->start(1000);
  ui->pushButton->setEnabled(false);
  ui->pushButton_2->setEnabled(false);

}


