#ifndef SQL_H
#define SQL_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QFile>

class Sql : public QObject
{
    Q_OBJECT
public:
    explicit Sql(QObject *parent = nullptr);
    virtual bool createdatabase()=0;
    virtual bool removedatabase()=0;


protected:
    QSqlDatabase database;
    QSqlQuery* sqlquery;
signals:

};

#endif // SQL_H
