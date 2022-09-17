#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include <QFile>
#include <QString>

#include "Stack.h"
#include "person.h"

//Singleton
class PersonKeeper
{
public:
    static PersonKeeper &Instance(); ///< хранится единственный экземпляр класса
    void readPersons(QString path); ///< считать ФИО из файла
    void writePersons(QString path) const; ///< записать ФИО в файл
    int size(); ///< количество ФИО
    void clear(); ///< очистить список ФИО

private:
    PersonKeeper(){} ///< конструкторы по умолчанию
    PersonKeeper(const PersonKeeper &); ///< конструктор копирования
    ~PersonKeeper(){} ///< деструктор
    PersonKeeper &operator=(const PersonKeeper &); ///< оператор присовения
    Stack<Person> stackOfPerson; ///< ФИО
};

#endif // PERSONKEEPER_H
