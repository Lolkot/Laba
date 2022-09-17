#include <iostream>
#include <QString>
#include <QDebug>

#include "person.h"
#include "estackempty.h"

Person::Person(QString fullName)
{
    //Разбивает строку на подстроки
    QStringList stroka = fullName.split(QRegularExpression("\\s+"), QString::SkipEmptyParts);

    // если не правильное количество слов, то сообщаем об ошибке
    try {
        if (stroka.size() < 3)
        {
            throw Exception("Error: Person(): String is invalid").what();
        }
    }  catch (const char* mes) {
        qDebug() << mes;
        return ;
    }

    _fullName = fullName;
    _lastName = stroka[0];
    _firstName = stroka[1];

    if (stroka.size() == 3)
    {
        _patronymic = stroka[2];
    }
}

void Person::setLastName(const QString &last_name)
{
    this->_lastName = last_name;
}

void Person::setFirstName(const QString &first_name)
{
    this->_firstName = first_name;
}

void Person::setPatronymic(const QString &patronymic)
{
    this->_patronymic = patronymic;
}
