#include "mainpage.h"
#include <QApplication>
#include <stdlib.h>
#include "globals.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand((unsigned)time(NULL));
    w=new MainPage;
    w->show();

    return a.exec();
}
