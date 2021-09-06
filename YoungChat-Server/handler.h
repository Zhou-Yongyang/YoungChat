#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <usersql.h>
#include <friendsql.h>
#include <tempmessql.h>
#include "message.h"
#include "answermessage.h"

class Handler : public QObject
{
    Q_OBJECT
public:
    static Handler* gethand(){
        if(sqlhand==nullptr)
            sqlhand=new Handler();
        userhand=Usersql::gethand();
        frihand=Friendsql::gethand();
        meshand=TempMesSql::gethand();
        return sqlhand;
    }

    static Usersql* getuser(){
        return userhand;
    }
    static Friendsql* getfri(){
        return frihand;
    }
    static TempMesSql* getmes(){
        return meshand;
    }

    QHash<Message::MessageType, QHash<QString, QString>> Meshandle(QHash<Message::MessageType, QHash<QString, QString>> temphash);
    QList<AnswerMessage*> serverToClientMessageList(QString &);

private:
    explicit Handler(QObject *parent = nullptr);
    static Usersql* userhand;
    static Friendsql* frihand;
    static TempMesSql* meshand;
    static Handler* sqlhand;

signals:

};

#endif // HANDLER_H
