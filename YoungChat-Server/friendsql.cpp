#include "friendsql.h"

Friendsql* Friendsql::sqlhand=nullptr;
Friendsql::Friendsql()
{

}

bool Friendsql:: opendatabase(QString &name){
   if(QSqlDatabase::contains("Frienddata.db")){
        database=QSqlDatabase::database("Frienddata.db");//注意这个引号里到底是啥意思
    }
   else{
        createdatabase();
    }
    if(database.open()){
        QStringList tablelist=database.tables();
        sqlquery=new QSqlQuery(database);
        if(!tablelist.contains(name)){
            QString create="CREATE TABLE "+name+ "(friend text primary key)";
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

bool Friendsql:: createdatabase(){
    if(!(QSqlDatabase::contains("Frienddata.db"))){
        database=QSqlDatabase::addDatabase("QSQLITE","Frienddata.db");
        database.setDatabaseName("Frienddata.db");
        database.setUserName("root");
        database.setPassword("123456");
    }
    if(QSqlDatabase::contains("Frienddata.db")){
        return 1;
    }
    else
    return 0;
}

bool Friendsql::insertdatabase(QString &name,QString &friendname){
    QString insert=QString("INSERT INTO "+name+"(friend) VALUES('%1')").arg(friendname);//值插入
    sqlquery=new QSqlQuery(database);
    sqlquery->prepare(insert);
    if( !sqlquery->exec() ){
        qDebug()<<sqlquery->lastError();
        return 0;
    }
    else
    return 1;
}



QHash<Message::MessageType, QHash<QString, QString>>  Friendsql:: list(QString &name){
    QString select="SELECT friend FROM "+name;
    QStringList qlist;
    int i=0;
    QHash<Message::MessageType, QHash<QString, QString>>rehash;
    QHash<QString, QString> keyValueHash;
    sqlquery=new QSqlQuery(database);
    sqlquery->prepare(select);
    if(sqlquery->exec()){
        while(sqlquery->next()){
            qlist.append(sqlquery->value(0).toString());
            i++;
        }
        keyValueHash.insert("UserName",name);
        for(int j=0;j<i;++j)
        keyValueHash.insert(QString::number(j+1),qlist.at(j));
    }

    else{
        qDebug()<<sqlquery->lastError();
    }
    rehash.insert(Message::MessageType::FRIEND_LIST_ANSWER,keyValueHash);
    return rehash;
}


bool Friendsql:: removedatabase(){
    if(!(QSqlDatabase::contains("Frienddata.db")))
        return 1;
    if(QFile::remove("Frienddata.db")){
        return 1;
    }
    else
        return 0;
}
