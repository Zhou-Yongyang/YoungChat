//2021/8/26
//用户基类，所有用户共有的基本信息操作 所有用户的最基本信息：用户名

#ifndef USER_BASE_H
#define USER_BASE_H

#include <QObject>
#include <QString>
class User_Base : public QObject
{
    Q_OBJECT
public:
    //注意构造函数
    explicit User_Base(QString userName ,QObject *parent = nullptr);
    QString getUserName();  //返回用户名
    void setUserName(QString newName);
protected:
    QString name;

signals:

};

#endif // USER_BASE_H
