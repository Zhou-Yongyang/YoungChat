#include "message.h"
#include <QString>
#include <QtDebug>

//服务端用户名标记
QString Message::ServerName = QString("Administrator");
QString Message::ZeroDivideStr = QString("!&");
QString Message::FirstDivideStr = QString("$%");
QString Message::SecondDivideStr = QString("&*");
QString Message::ThirdDivideStr = QString("#@");
QString Message::ForthDivideStr = QString("@$");

//常规构造函数
Message::Message(QString senderName, QString recevierName, QString text,  MessageType type, QObject *parent) : QObject(parent), sender(senderName), recevier(recevierName)
{
    this->time = QDateTime::currentDateTime();
    this->text = text;
    this->type = type;
}

Message::Message(QString formatText):sender("aaa"),recevier("bbb")
{
    stringToMessage(formatText);
}

QString Message::getText()
{
    return text;
}
QString Message::getSenderName()
{
    return sender.getUserName();
}

QString Message::getRecevierName()
{
    return recevier.getUserName();
}
Message::MessageType Message::getMessageType()
{
    return type;
}

QString Message::getTimeString()
{
    return time.toString("yyyy##MM##dd##hh##mm##ss");
}

QString Message::msgToString()
{
    //通过分隔符号分开
    QString str;
    str.append(ZeroDivideStr);
    str.append("TYPE");
    str.append(FirstDivideStr);
    str.append(QString::number(type));
    str.append(SecondDivideStr);

    str.append("TIME");
    str.append(FirstDivideStr);
    str.append(time.toString("yyyy##MM##dd##hh##mm##ss"));
    str.append(SecondDivideStr);

    str.append("SENDER");
    str.append(FirstDivideStr);
    str.append(sender.getUserName());
    str.append(SecondDivideStr);

    str.append("RECEVIER");
    str.append(FirstDivideStr);
    str.append(recevier.getUserName());
    str.append(SecondDivideStr);

    str.append("TEXT");
    str.append(FirstDivideStr);
    str.append(text);
    str.append(ZeroDivideStr);

    return str;
}

void Message::stringToMessage(QString formatText)
{
    //将标准格式的各部分分离出来，复制到Message的各个成员中
    QStringList wordsList = formatText.split(SecondDivideStr);
    QHash<QString, QString> tmpHash;
    for(int i = 0; i < wordsList.count(); i++)
    {
        QStringList tmp = wordsList.at(i).split(FirstDivideStr);
        tmpHash.insert(tmp.at(0),tmp.at(1));
    }
    type = strTypeTointType(tmpHash.value("TYPE"));
    time = time.fromString(tmpHash.value("TIME"),"yyyy##MM##dd##hh##mm##ss");
    sender.setUserName(tmpHash.value("SENDER"));
    recevier.setUserName(tmpHash.value("RECEVIER"));
    text = tmpHash.value("TEXT");
}

Message::MessageType Message::strTypeTointType(QString str)
{
    return (MessageType)str.toInt();
}

Message::AnswerType Message::getAnswerType()
{
    return AnswerType::EMPTY;
}

void Message::setStrToTime(QString str)
{
    time = time.fromString(str, "yyyy##MM##dd##hh##mm##ss");
}
