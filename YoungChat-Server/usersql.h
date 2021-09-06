#ifndef USERSQL_H
#define USERSQL_H
#include "sql.h"
#include "message.h"

class Usersql : public Sql
{
public:
    Usersql();

    static Usersql* gethand(){
        if(sqlhand==nullptr)
            sqlhand=new Usersql();
        return sqlhand;
    }


    virtual bool removedatabase();
    virtual bool createdatabase();
    bool opendatabase();
    bool insertdatabase(QString&,QString&,QString&,QString&,QString&,QString&);
    bool login(QString&,QString&);
    bool alterpassword(QString&,QString&);
    bool finduser(QString&);
    QHash<Message::MessageType, QHash<QString, QString>> findpassword(QString&);
    QStringList getall();
    void Makegroup();
    QString ciphertext(QString);

private:
    static Usersql* sqlhand;
};

#endif // USERSQL_H
