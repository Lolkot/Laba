#include "person.h"
#include "empty.h"
#include <iostream>

Person::Person(QString full_name)
{
    QStringList str = full_name.split(QRegularExpression("\\s+"), QString::SkipEmptyParts); //Разбивает строку на подстроки

    // если не правильное количество слов, то сообщаем об ошибке
    try {
        if (str.size() != 2 && str.size() != 3)
        {
            throw Exception("Error: Person(): String is invalid").what();
        }
    }  catch (const char* mes) {
        std::cout << mes << std::endl;
        return ;
    }

    _last_name = str[0];
    _first_name = str[1];
    if (str.size() == 3)
    {
        _patronymic = str[2];
    }
}

void Person::Set_last_name(const QString &last_name)
{
    this->_last_name = last_name;
}
void Person::Set_first_name(const QString &first_name)
{
    this->_first_name = first_name;
}
void Person::Set_patronymic(const QString &patronymic)
{
    this->_patronymic = patronymic;
}
