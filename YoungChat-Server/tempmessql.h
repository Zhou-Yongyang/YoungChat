#ifndef TEMPMESSQL_H
#define TEMPMESSQL_H
#include "sql.h"
#include "message.h"
#include "message.h"
#include "answermessage.h"

class TempMesSql : public Sql
{
public:
    TempMesSql();

    static TempMesSql* gethand(){
        if(sqlhand==nullptr)
            sqlhand=new TempMesSql();
        return sqlhand;
    }

    virtual bool createdatabase();
    virtual bool removedatabase();
    bool opendatabase(QString&);
    bool insertdatabase(QString&,QString&,QString&,QString&,QString&);
    QList<AnswerMessage*> selectdatabase(QString&);
    bool deletemes(QString&);

private:
    static TempMesSql* sqlhand;
};

#endif // TEMPMESSQL_H
