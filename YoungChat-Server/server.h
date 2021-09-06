#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include "tcpserver.h"

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    TcpServer* tcpServer;
    explicit Server(QWidget *parent = nullptr);
    ~Server();

private slots:

    void on_getIPAddressButton_clicked();

    void on_openServerButton_clicked();

    void on_closeServerButton_clicked();

    void slot_addIPlistToUI();
    void slot_addUserToList(QString userName);

private:
    Ui::Server *ui;
};

#endif // SERVER_H
