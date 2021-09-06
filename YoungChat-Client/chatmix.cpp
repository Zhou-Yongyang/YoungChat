#include "chatmix.h"
#include "ui_chatmix.h"

chatmix::chatmix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chatmix)
{
    ui->setupUi(this);
}

chatmix::~chatmix()
{
    delete ui;
}
