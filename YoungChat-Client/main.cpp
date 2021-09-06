#include "loginwindow.h"
#include "windowcontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WindowController::getInstance()->createConnectToServerWindow();
//    w.createLoginWindow();
//    w.
    return a.exec();
}
