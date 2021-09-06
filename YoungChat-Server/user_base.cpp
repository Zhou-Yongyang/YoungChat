#include "user_base.h"
#include <QString>
#include <QtDebug>

User_Base::User_Base(QString userName, QObject *parent) : QObject(parent), name(userName)
{
}

QString User_Base::getUserName()
{
    return name;
}

void User_Base::setUserName(QString newName)
{
    name = newName;
}


