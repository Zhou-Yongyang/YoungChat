#include "tempmessql.h"
#include "message.h"
#include "answermessage.h"

TempMesSql* TempMesSql::sqlhand=nullptr;
TempMesSql::TempMesSql()
{

}

bool TempMesSql:: opendatabase(QString &reciever){
    if(QSqlDatabase::contains("Messagedata.db")){
        database=QSqlDatabase::database("Messagedata.db");//注意这个引号里到底是啥意思
    }
    else{
        createdatabase();
    }
    if(database.open()){
        QStringList tablelist=database.tables();
        sqlquery=new QSqlQuery(database);
        if(!tablelist.contains(reciever)){
            QString create="CREATE TABLE " +reciever+" (sender text ,type text,message text,mdate text)";
            if(sqlquery->prepare(create)){
                if(sqlquery->exec())
                {
                    return 1;
                }
            }
            else{
                qDebug()<<sqlquery->lastError();
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
    return 1;
}

bool TempMesSql:: createdatabase(){
    if(!(QSqlDatabase::contains("Messagedata.db"))){
        database=QSqlDatabase::addDatabase("QSQLITE","Messagedata.db");
        database.setDatabaseName("Messagedata.db");
        database.setUserName("root");
        database.setPassword("123456");
    }
    if(QSqlDatabase::contains("Messagedata.db")){
        return 1;
    }
    else
    return 0;
}

bool TempMesSql::insertdatabase(QString &reciever,QString &sender,QString &message,QString &type,QString &date){//时间这里生成还是发送过来
    QString insert=QString("INSERT INTO %1(sender,type,message,mdate) VALUES('%2','%3','%4','%5')").arg(reciever).arg(sender).arg(type).arg(message).arg(date);
    sqlquery=new QSqlQuery(database);
    sqlquery->prepare(insert);
    if( !sqlquery->exec() ){
        qDebug()<<sqlquery->lastError();
        return 0;
    }
    else
     return 1;
}

QList<AnswerMessage*> TempMesSql:: selectdatabase(QString &reciever){
    QString select="SELECT * FROM "+reciever;
    QList<AnswerMessage*> msgList;
    Message* tmp;
    AnswerMessage* atmp;
    sqlquery=new QSqlQuery(database);
    sqlquery->prepare(select);
    if(sqlquery->exec()){
        while(sqlquery->next()){
            if(sqlquery->value(1).toString()=="text"){
                tmp =new Message(sqlquery->value(0).toString(), reciever, sqlquery->value(2).toString(), Message::MessageType::CLIENT_TO_SERVER_ANSWER);
                msgList.append((AnswerMessage*)tmp);
            }
            else if(sqlquery->value(1).toString()=="request"){
                 tmp =new Message(sqlquery->value(0).toString(), reciever, "", Message::MessageType::MAKE_FRIEND_REQUEST);
                 msgList.append((AnswerMessage*)tmp);
            }
            else if(sqlquery->value(1).toString()=="answer"&&sqlquery->value(2).toString()=="1"){
                 atmp =new AnswerMessage(sqlquery->value(0).toString(), reciever, Message::MessageType::MAKE_FRIEND_ANSWER, Message::AnswerType::TRUE);
                msgList.append(atmp);
            }
            else if(sqlquery->value(1).toString()=="answer"&&sqlquery->value(2).toString()=="0"){
                 atmp =new AnswerMessage(sqlquery->value(0).toString(), reciever, Message::MessageType::MAKE_FRIEND_ANSWER, Message::AnswerType::FALSE);
                msgList.append(atmp);
            }
            if(sqlquery->value(1).toString()=="group"){
                tmp =new Message(sqlquery->value(0).toString(), reciever, sqlquery->value(2).toString(), Message::MessageType::GROUP_TO_CLIENT_ANSWER);
                msgList.append((AnswerMessage*)tmp);
            }
        }
        deletemes(reciever);
    }

    else{
        qDebug()<<sqlquery->lastError();
    }

    return msgList;

}


bool TempMesSql:: deletemes(QString &reciever){
    QString mdelete=QString("DROP TABLE %1").arg(reciever);
    sqlquery=new QSqlQuery(database);
    sqlquery->prepare(mdelete);
    if( !sqlquery->exec() ){
        qDebug()<<sqlquery->lastError();
        return 0;
    }
    else
     return 1;
}


bool TempMesSql:: removedatabase(){
    if(!(QSqlDatabase::contains("Messagedata.db")))
        return 1;
    if(QFile::remove("Messagedata.db")){
        return 1;
    }
    else
        return 0;
}
