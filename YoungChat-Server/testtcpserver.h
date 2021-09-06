#ifndef TESTTCPSERVER_H
#define TESTTCPSERVER_H

#include <QObject>
#include <QTcpServer>
class TestTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TestTcpServer(QObject *parent = nullptr);
    virtual void incomingConnection(qintptr handle) override;
    void startListen()
    {
        qDebug() << tcpServer->listen(QHostAddress::Any,5555);
        qDebug() << tcpServer->isListening();
    }

    QTcpServer* tcpServer;
signals:

private slots:
    void slot_connection();
};

#endif // TESTTCPSERVER_H
