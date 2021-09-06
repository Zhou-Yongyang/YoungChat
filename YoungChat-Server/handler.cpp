#include "handler.h"
#include "message.h"
#include "answermessage.h"

Handler* Handler::sqlhand=nullptr;
Usersql* Handler::userhand=nullptr;
Friendsql* Handler::frihand=nullptr;
TempMesSql* Handler::meshand=nullptr;
Handler::Handler(QObject *parent) : QObject(parent)
{

}

QList<AnswerMessage*> Handler::serverToClientMessageList(QString &userName)
{
    Handler* hand=Handler::gethand();
    TempMesSql* mes;
    mes=hand->getmes();
    mes->opendatabase(userName);
   return mes->selectdatabase(userName);
}


QHash<Message::MessageType, QHash<QString, QString>> Handler::Meshandle(QHash<Message::MessageType, QHash<QString, QString>> temphash)
{
        Handler* hand=Handler::gethand();
        QList<Message::MessageType>qtype=temphash.keys();
        Message::MessageType type=qtype.at(0);
        QHash<Message::MessageType, QHash<QString, QString>>rehash;
        QHash<QString, QString> keyValueHash;
        QHash<QString, QString> qhash;
        Usersql* user;
        user=hand->getuser();
        Friendsql* fri;
        fri=hand->getfri();
        TempMesSql* mes;
        mes=hand->getmes();

        QString groupname=Message::ServerName;
        user->opendatabase();
        if(!user->finduser(groupname)){
            user->Makegroup();
        }


        if(type == Message::MessageType::LOGIN_REQUEST)
        {
            user->opendatabase();
            qhash=temphash[type];
            QString name=qhash["UserName"];
            QString password=qhash["Password"];
            keyValueHash.insert("UserName",name);
            if(user->login(name,password)){
                keyValueHash.insert("Output","1");
                rehash.insert(Message::MessageType::LOGIN_ANSWER,keyValueHash);
            }
            else{
                keyValueHash.insert("Output","0");
                rehash.insert(Message::MessageType::LOGIN_ANSWER,keyValueHash);
            }
            return rehash;
        }

        if(type == Message::MessageType::SIGNUP_REQUEST)
        {
            user->opendatabase();
            qhash=temphash[type];
            QString name=qhash["UserName"];
            QString password=qhash["Password"];
            QString q1=qhash["Question1"];
            QString q2=qhash["Question2"];
            QString ans1=qhash["Answer1"];
            QString ans2=qhash["Answer2"];
            keyValueHash.insert("UserName",name);
            if(user->insertdatabase(name,password,q1,q2,ans1,ans2)){
                keyValueHash.insert("Output","1");
                QString group= Message::ServerName;
                fri->opendatabase(name);
                fri->insertdatabase(name,group);
                fri->opendatabase(group);
                fri->insertdatabase(group,name);
            }
            else{
                keyValueHash.insert("Output","0");
            }
            rehash.insert(Message::MessageType::SIGNUP_ANSWER,keyValueHash);
            return rehash;
        }

        if(type == Message::MessageType::MAKE_FRIEND_REQUEST)
        {
            qhash=temphash[type];
            QString name=qhash["Recevier"];
            QString sender=qhash["Sender"];
            QString date=qhash["Time"];
            QString type="request";
            user->opendatabase();
            if(user->finduser(name))
            {
                mes->opendatabase(name);
                mes->insertdatabase(name,sender,type,type,date);
                rehash.insert(Message::MessageType::NONE,qhash);
            }
            else
            {
                rehash.insert(Message::MessageType::NOUSER,qhash);
            }
            return rehash;
        }

        if(type == Message::MessageType::MAKE_FRIEND_ANSWER)
        {
            qhash=temphash[type];
            QString name=qhash["Recevier"];
            QString sender=qhash["Sender"];
            QString date=qhash["Time"];
            AnswerMessage::AnswerType type= (AnswerMessage::AnswerType)qhash["AnswerType"].toInt();
            QString state=qhash["State"];
            QString texttype="answer";
            mes->opendatabase(name);

            if(type== AnswerMessage::AnswerType::TRUE){
              fri->opendatabase(name);
              fri->insertdatabase(name,sender);
              fri->opendatabase(sender);
              fri->insertdatabase(sender,name);
            }

            if(state!="TRUE")
            {
                QString typeString = QString::number(type);
                mes->insertdatabase(name,sender,typeString,texttype,date);
            }
            rehash.insert(Message::MessageType::NONE,qhash);
            return rehash;
        }

        if(type == Message::MessageType::FRIENDS_LIST_REQUEST)
        {
             qhash=temphash[type];
             QString name=qhash["UserName"];
             fri->opendatabase(name);
             return fri->list(name);
        }

        if(type == Message::MessageType::FIND_PASSWORD_REQUEST)
        {
            user->opendatabase();
            qhash=temphash[type];
            QString name=qhash["UserName"];
            return user->findpassword(name);
        }

        if(type == Message::MessageType::RESET_PASSWORD_REQUEST)
        {
            user->opendatabase();
            qhash=temphash[type];
            QString name=qhash["UserName"];
            QString password=qhash["Password"];
            keyValueHash.insert("UserName",name);
            if(user->alterpassword(name,password)){
                  keyValueHash.insert("Output","1");
            }
            else{
                keyValueHash.insert("Output","0");
            }
            rehash.insert(Message::MessageType::RESET_PASSWORD_ANSWER,keyValueHash);
            return rehash;
        }

        if(type == Message::MessageType::CLIENT_TO_CLIENT_REQUEST){
            qhash=temphash[type];
            QString name=qhash["Recevier"];
            QString sender=qhash["Sender"];
            QString date=qhash["Time"];
            QString message=qhash["Text"];
            QString texttype="text";
            mes->opendatabase(name);
            mes->insertdatabase(name,sender,message,texttype,date);
            rehash.insert(Message::MessageType::NONE,qhash);
            return rehash;
        }

        if(type == Message::MessageType::GROUP_TO_CLIENT_ANSWER){
            qhash=temphash[type];
            QString name=qhash["Recevier"];
            QString sender=qhash["Sender"];
            QString date=qhash["Time"];
            QString message=qhash["Text"];
            QString texttype="group";
            mes->opendatabase(name);
            mes->insertdatabase(name,sender,message,texttype,date);
            rehash.insert(Message::MessageType::NONE,qhash);
            return rehash;
        }
}
