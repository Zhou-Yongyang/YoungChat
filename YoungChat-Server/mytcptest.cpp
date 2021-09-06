#include "mytcptest.h"

MyTcpTest::MyTcpTest(QObject *parent) : QObject(parent)
{

}

void MyTcpTest::startLisen()
{
    tcpServer.listen(QHostAddress::Any, 5555);
}
