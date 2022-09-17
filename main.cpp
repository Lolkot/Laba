#include <iostream>
#include <cstring>
#include <string>
#include <QString>
#include <QFile>
#include <QDebug>

#include "personkeeper.h"
#include "Stack.h"

int main()
{
    QString inputFile = "input.txt";
    QString outputFile = "output.txt";
    PersonKeeper &persorKeep(PersonKeeper::Instance());

    qDebug() << "Creat 2 files in the folder where the project is exist: input.txt and output.txt";
    // считываем имена из файла
    qDebug() << "Read data from input.txt";
    persorKeep.readPersons(inputFile);
    qDebug() << "Write data from input.txt into ouput.txt";
    // записываем имена в файл
    persorKeep.writePersons(outputFile);
    qDebug() << "Now you can open files to compare data";

    qDebug() << "---------------------------------";

    srand (time(NULL));
    Stack<int> stackOfInteger;
    Stack<float> stackOffloat;
    Stack<QString> stackOfString;

    qDebug() << "Add 10 randoms values of integer into stackOfInteger";
    for(int i = 0; i < 10; ++i) {
        int val = rand() % 10  + 1;
        stackOfInteger.push(val);
        qDebug() << val;
    }

    qDebug() << "Output the stackOfInteger: ";
    stackOfInteger.enumeration([&](const int &value){
       qDebug() << value;
    });

    qDebug() << "---------------------------------";

    qDebug() << "Add 10 values of float into stackOfFloat";
    for(int i = 0; i < 10; ++i) {
        float val = static_cast<float>(i / (i + 2.5));
        stackOffloat.push(val);
        qDebug() << val;
    }

    qDebug() << "Output the stackOfFloat: ";
    stackOffloat.enumeration([&](const float &value){
        qDebug() << value;
    });

    qDebug() << "---------------------------------";

    qDebug() << "Add 5 values of string into stackOfString";
    stackOfString.push("Alexander Pushkin");
    stackOfString.push("Eugene Onegin");
    stackOfString.push("Vladislav Kovalev");
    stackOfString.push("Olga Kovaleva");
    stackOfString.push("Rastilav Dupkin");


    qDebug() << "Output the stackOfString: ";
    stackOfString.enumeration([&](const QString &val){
        qDebug() << val;
    });

    qDebug() << "---------------------------------";

    qDebug() << "Try to throw an exception";
    Stack<int> stack;
    stack.pop();
}
