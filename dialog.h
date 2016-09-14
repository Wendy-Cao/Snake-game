#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QPaintEvent>
#include<QPainter>
#include "mysnake.h"
#include<QMessageBox>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    int direction;

    ~Dialog();
    protected:
  virtual  void paintEvent(QPaintEvent *event);
private:
    Ui::Dialog *ui;
    QTimer *m_pTimer;//首先创建一个定时器
    mysnake snake;
private slots:
    void on_pushButton_clicked();

public slots:
    void showsnake();
};

#endif // DIALOG_H
