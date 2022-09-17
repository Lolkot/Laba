#ifndef ESTACKEMPTY_H
#define ESTACKEMPTY_H
#include "exception.h"

class EStackEmpty : public EStackException
{
public:
    // конструктор по умолчанию
    EStackEmpty()
        : EStackException("Error: Stack is empty") ///< Инициализация сообщения по умолчанию об ошибки в базовом классе
    {
    }

    // конструктор копирования
    EStackEmpty(const EStackEmpty &t)
        : EStackException(t) ///< Инициализация переданного сообщения об ошибке в базовом классе
    {
    }
};
#endif // ESTACKEMPTY_H
