#include "serverwindow.h"
#include "ui_serverwindow.h"
#include "user_tcpconnect.h"


ServerWindow::ServerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

