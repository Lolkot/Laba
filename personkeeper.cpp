#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "personkeeper.h"
#include "estackempty.h"

int PersonKeeper::size()
{
    return stackOfPerson.size();
}

void PersonKeeper::clear()
{
    return stackOfPerson.clear();
}

PersonKeeper &PersonKeeper::Instance()
{
    static PersonKeeper inst;
    return inst;
}

void PersonKeeper::readPersons(QString path)
{
    QFile file(path);

    // Генерация исключения при не открытом или не существующем файле
    try {
        // существует ли файл
        if (!file.exists())
            throw EStackException("Error: File doesn't exists").what();

        // открытие файла на чтение
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            throw EStackException("Error: Not open file").what();

    }  catch (const char* mes) {
        std::cout << mes << std::endl;
        return ;
    }

    // поток текстовых данных файла
    QTextStream stream(&file);

    // буфер для записи строк
    QString buffLine;

    // считытваем, пока не конец файла
    while (stream.readLineInto(&buffLine))
    {
        // добавляем в стек ФИО
        stackOfPerson.push(Person(buffLine));
    }

    // закрываем для чтения файл
    file.close();

}

void PersonKeeper::writePersons(QString path) const
{
    QFile file(path);

    // Генерация исключения при не открытом или не существующем файле
    try {
        // существует ли файл
        if (!file.exists())
            throw EStackException("Error: File doesn't exists").what();

        // открытие файла на чтение
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            throw EStackException("Error: Not open file").what();

    }  catch (const char* mes) {
        std::cout << mes << std::endl;
        return ;
    }

    QTextStream stream(&file);

    // проходимся по всем значеним для записи
    stackOfPerson.enumeration([&](const Person &person) { stream << person.getFullName() << "\n"; });

    // закрываем файл для записи
    file.close();
}
