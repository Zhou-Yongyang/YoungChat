#ifndef MYTCPTEST_H
#define MYTCPTEST_H

#include <QObject>
#include <QTcpServer>

class MyTcpTest : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpTest(QObject *parent = nullptr);
    QTcpServer tcpServer;

    void startLisen();

signals:

};

#endif // MYTCPTEST_H
