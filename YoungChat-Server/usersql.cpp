#include "usersql.h"
Usersql* Usersql::sqlhand=nullptr;
Usersql::Usersql()
{

}


bool Usersql:: opendatabase(){
   if(QSqlDatabase::contains("Userdata.db")){
        database=QSqlDatabase::database("Userdata.db");//注意这个引号里到底是啥意思
    }
    else{
        createdatabase();
    }
    if(database.open()){
        QStringList tablelist=database.tables();
        sqlquery=new QSqlQuery(database);
        if(!tablelist.contains("usertable")){
            QString createusers="CREATE TABLE usertable (name text primary key,password text,question1 text,question2 text,answer1 text,answer2 text)";
            if(sqlquery->prepare(createusers)){
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

bool Usersql:: createdatabase(){
    if(!(QSqlDatabase::contains("Userdata.db"))){
        database=QSqlDatabase::addDatabase("QSQLITE","Userdata.db");
        database.setDatabaseName("Userdata.db");
        database.setUserName("root");
        database.setPassword("123456");
    }
    if(QSqlDatabase::contains("Userdata.db")){
        return 1;
    }
    else
    return 0;
}

QString Usersql::ciphertext(QString orgCode){
    int cipherKey = orgCode.length();
    QString ans;
    for(int i = 0; i < orgCode.length(); i++)
    {

        ans.append((orgCode.at(i).toLatin1() + cipherKey) % 100);
    }
    return ans;

}


bool Usersql::insertdatabase(QString &name,QString &password,QString &question1,QString &question2,QString &answer1,QString &answer2){

    QString ci_password;
    ci_password=ciphertext(password);
    QString insert=QString("INSERT INTO usertable(name,password,question1,question2,answer1,answer2) VALUES('%1','%2','%3','%4','%5','%6')").arg(name).arg(ci_password).arg(question1).arg(question2).arg(answer1).arg(answer2);
    sqlquery=new QSqlQuery(database);
    sqlquery->prepare(insert);
    if( !sqlquery->exec() ){
        qDebug()<<sqlquery->lastError();
        return 0;
    }
    else
     return 1;
}

bool Usersql::login(QString &name,QString &password){
    QString ci_password;
    ci_password=ciphertext(password);
    QString select=QString("SELECT name FROM usertable WHERE name='%1'AND password='%2'").arg(name).arg(ci_password);
    sqlquery=new QSqlQuery(database);
    sqlquery->prepare(select);
    sqlquery->exec();
    if(sqlquery->next())
        return 1;
    else
        return 0;
}


bool Usersql::alterpassword(QString &name,QString &password){
    QString ci_password;
    ci_password=ciphertext(password);
    QString alter=QString("UPDATE  usertable "
                           "SET password='%1' WHERE name='%2'").arg(ci_password).arg(name);
    sqlquery=new QSqlQuery(database);
    sqlquery->prepare(alter);
    if( !sqlquery->exec() ){
        qDebug()<<sqlquery->lastError();
        return 0;
    }
    else
     return 1;
}

QHash<Message::MessageType, QHash<QString, QString>> Usersql::findpassword(QString &name){//密保问题在哪比对
       QString ans=QString("SELECT question1,question2,answer1,answer2 FROM usertable WHERE name='%1'").arg(name);
       QHash<Message::MessageType, QHash<QString, QString>>rehash;
       QHash<QString, QString> keyValueHash;
       sqlquery=new QSqlQuery(database);
       sqlquery->prepare(ans);
       if(sqlquery->exec()){
           sqlquery->next();
           keyValueHash.insert("UserName",name);
           keyValueHash.insert("Question1",sqlquery->value(0).toString());
           keyValueHash.insert("Question2",sqlquery->value(1).toString());
           keyValueHash.insert("Answer1",sqlquery->value(2).toString());
           keyValueHash.insert("Answer2",sqlquery->value(3).toString());
       }
       else{
           qDebug()<<sqlquery->lastError();
       }
       rehash.insert(Message::MessageType::FIND_PASSWORD_ANSWER,keyValueHash);
       return rehash;
}

bool Usersql::finduser(QString &name){
    QString find=QString("SELECT name FROM usertable WHERE name='%1'").arg(name);
    sqlquery=new QSqlQuery(database);
    sqlquery->prepare(find);
    if( !sqlquery->exec() ){
        qDebug()<<sqlquery->lastError();
        return 0;
    }
    else{
        if(sqlquery->next())
            return 1;
        else return 0;
    }
}

void Usersql::Makegroup(){
    QString insert=QString("INSERT INTO usertable(name) VALUES('%1')").arg(Message::ServerName);
    sqlquery=new QSqlQuery(database);
    sqlquery->prepare(insert);
    if( !sqlquery->exec() ){
        qDebug()<<sqlquery->lastError();
    }
}

QStringList Usersql::getall(){
    opendatabase();
    QStringList alluser;
    QString select=QString("SELECT name FROM usertable");
    sqlquery=new QSqlQuery(database);
    sqlquery->prepare(select);
    if(sqlquery->exec()){
            while(sqlquery->next()){
                alluser.append(sqlquery->value(0).toString());
            }
    }
    else{
        qDebug()<<sqlquery->lastError();
    }
    return alluser;
}

bool Usersql:: removedatabase(){
    if(!(QSqlDatabase::contains("Userdata.db")))
        return 1;
    if(QFile::remove("Userdata.db")){
        return 1;
    }
    else
        return 0;
}
