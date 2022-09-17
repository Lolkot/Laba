#ifndef EMPTY_H
#define EMPTY_H
#include "exception.h"

class EStackEmpty : public Exception
{
public:
    // конструктор по умолчанию
    EStackEmpty()
        : Exception("Stack is empty") ///< Инициализация сообщения по умолчанию об ошибки в базовом классе
    {
    }

    // конструктор копирования
    EStackEmpty(const EStackEmpty &t)
        : Exception(t) ///< Инициализация переданного сообщения об ошибке в базовом классе
    {
    }
};
#endif // EMPTY_H
