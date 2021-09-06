#ifndef ANSWERMESSAGE_H
#define ANSWERMESSAGE_H

#include <QObject>
#include "message.h"

class AnswerMessage : public Message
{
    Q_OBJECT
public:
explicit AnswerMessage(QString senderName, QString recevierName, MessageType type, AnswerType ansType ,QObject *parent = nullptr);
explicit AnswerMessage(QString formatText);   //根据标准字符串转换为消息对象

public:
    virtual AnswerType getAnswerType() override;
    AnswerType ansType;
    virtual void stringToMessage(QString formatText) override;
    QString msgToString() override;

signals:

};

#endif // ANSWERMESSAGE_H
