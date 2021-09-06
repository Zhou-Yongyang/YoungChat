#include "answermessage.h"

AnswerMessage::AnswerMessage(QString senderName, QString recevierName, MessageType type,AnswerType ansType, QObject *parent):Message(senderName,recevierName,"",type)
{
    this->ansType = ansType;
}
AnswerMessage::AnswerMessage(QString formatText):Message(formatText)   //根据标准字符串转换为消息对象
{
    stringToMessage(formatText);
}

AnswerMessage::AnswerType AnswerMessage::getAnswerType()
{
    return ansType;
}

void AnswerMessage::stringToMessage(QString formatText)
{
    //将标准格式的各部分分离出来，复制到Message的各个成员中
    QStringList wordsList = formatText.split(SecondDivideStr);
    QHash<QString, QString> tmpHash;
    for(int i = 0; i < wordsList.count(); i++)
    {
        QStringList tmp = wordsList.at(i).split(FirstDivideStr);
        tmpHash.insert(tmp.at(0),tmp.at(1));
    }
    strTypeTointType(tmpHash.value("TYPE"));
    time = time.fromString(tmpHash.value("TIME"),"yyyy##MM##dd##hh##mm##ss");
    sender.setUserName(tmpHash.value("SENDER"));
    recevier.setUserName(tmpHash.value("RECEVIER"));
    text = tmpHash.value("TEXT");
    if(tmpHash.contains("ATYPE"))
    {
        ansType = (AnswerMessage::AnswerType)tmpHash.value("ATYPE").toInt();
    }
    else
        ansType = AnswerMessage::AnswerType::EMPTY;

}


QString AnswerMessage::msgToString()
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
    str.append(SecondDivideStr);

    str.append("ATYPE");
    str.append(FirstDivideStr);
    str.append(QString::number(ansType));
    str.append(ZeroDivideStr);

    return str;
}
