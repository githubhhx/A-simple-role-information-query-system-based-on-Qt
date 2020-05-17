#include "mainwindow.h"
#include <QApplication>
#include <logging.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    logging log;
    if(log.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else {
        return 0;
    }
}
