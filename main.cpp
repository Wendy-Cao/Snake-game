#include <QtGui/QApplication>
#include "dialog.h"
#include<QTime>

int score;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QTime::currentTime().msec());
    Dialog w;
    w.show();
    return a.exec();
}
