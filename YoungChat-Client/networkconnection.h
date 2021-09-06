#ifndef NETWORKCONNECTION_H
#define NETWORKCONNECTION_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class NetworkConnection;
}

class NetworkConnection : public QWidget
{
    Q_OBJECT

public:
    explicit NetworkConnection(QWidget *parent = nullptr);
    ~NetworkConnection();
    QString IPAddress, hostPort;
    bool IsIPaddress(QString ip);
    bool isDigitStr(QString src);

private slots:
    void on_pButtonOk_clicked();

    void on_pButtonCancel_clicked();

private:
    Ui::NetworkConnection *ui;
};

#endif // NETWORKCONNECTION_H
