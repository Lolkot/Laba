#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <QRegularExpression>

class Person
{
public:
    Person() = delete;
    Person(QString last_name, QString first_name, QString patronymic):
        _last_name(last_name),
        _first_name(first_name),
        _patronymic(patronymic){ };

    Person(QString full_name);

    void Set_last_name(const QString &last_name);
    void Set_first_name(const QString &first_name);
    void Set_patronymic(const QString &patronymic);

    const QString &Get_last_name() const { return _last_name; }  //получение фамилии
    const QString &Get_first_name() const { return _first_name; }//получение имени
    const QString &Get_patronymic() const { return _patronymic; }//полученеи отчества

private:
    QString _last_name; ///< Фамилия
    QString _first_name; ///< Имя
    QString _patronymic; ///< Отчество

};
#endif // PERSON_H
