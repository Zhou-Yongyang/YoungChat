#include "testtcpserver.h"

TestTcpServer::TestTcpServer(QObject *parent) : QTcpServer(parent)
{
    tcpServer = new QTcpServer();
    connect(tcpServer, &QTcpServer::newConnection, this, &TestTcpServer::slot_connection);
}

void TestTcpServer::incomingConnection(qintptr handle)
{
    qDebug() << "newConnection";
    qDebug() << handle;
}

void TestTcpServer::slot_connection()
{
    qDebug() << "newConnection By Slot";
}
