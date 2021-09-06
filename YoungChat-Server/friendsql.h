#ifndef FRIENDSQL_H
#define FRIENDSQL_H
#include "sql.h"
#include "message.h"


class Friendsql : public Sql
{
public:
    Friendsql();

    static Friendsql* gethand(){
        if(sqlhand==nullptr)
            sqlhand=new Friendsql();
        return sqlhand;
    }

    virtual bool createdatabase();
    virtual bool removedatabase();
    bool opendatabase(QString&);
    bool insertdatabase(QString&,QString&);
    QHash<Message::MessageType, QHash<QString, QString>> list(QString&);
private:
    static Friendsql* sqlhand;
};

#endif // FRIENDSQL_H
