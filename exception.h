#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <cstring>
#include <algorithm>

class Exception
{
public:
    // конструктор
    Exception(const char* arg_message)
    {
        // выделяем память под сообщение об ошибке
        _errorMessage = new char[strlen(arg_message) + 1];

        // сообщение об ошибке
        std::memcpy(_errorMessage, arg_message, strlen(arg_message));
    }

    // конструктор копирования
    Exception(const Exception& exception)
    {
        // выделяем память под копию сообщения
        _errorMessage = new char[strlen(exception._errorMessage) + 1];

        // копируем сообщение об ошибке
        std::memcpy(_errorMessage, exception._errorMessage, strlen(exception._errorMessage));

    }

    // деструктор
    ~Exception()
    {
        // освобождаем память
        delete _errorMessage;
    }
    const char* what() const { return _errorMessage; }

private:

    char* _errorMessage;

};
#endif // EXCEPTION_H
