#ifndef STACK_H
#define STACK_H

#include <functional>
#include <iostream>
#include "exception.h"
#include "estackempty.h"

template <class T>
class Stack
{
public:
    ~Stack(); ///< деструктор
    void push(const T &k); ///< помещение объекта в стек
    const T pop(); ///< извлечение объекта из стека
    int size(); ///< вернуть размер стека
    void clear(); ///< очистить весь стек
    void enumeration(std::function<void(const T &k)> f) const; ///< функция перебора значений

private:
    struct Node
    {
        Node() = default;
        explicit Node (T k, Node *t) : value(k), prev(t) {};
        const T value; ///< храним константное значение

        Node *prev = nullptr; ///< указатель на предпоследний узел стека
    };

    Node *lastElement { nullptr }; ///< последний элемент стека

    int _sizeOfStack { 0 }; ///< размер стека
};

template <class T>
Stack<T>::~Stack()
{
    clear();
}

template <class T>
int Stack<T>::size()
{
    return _sizeOfStack;
}

template <class T>
const T Stack<T>::pop()
{

    // если стек пуст, возвращаем исключение
    try {
        if (lastElement == nullptr)
        {
            throw EStackEmpty().what();
        }
    }  catch (const char* mes) {
        std::cout << mes << std::endl;
        return {};
    }

    // сохраняем значение узла в k
    const T k = lastElement->value;

    // сохраняем последнией узел в tmp
    Node *tmp = lastElement;

    // перемещаем на предпоследний узел
    lastElement = lastElement->prev;

    // удаляем последний узел
    delete tmp;

    // уменьшаем размер стека
    _sizeOfStack--;

    // возвращаем сохраненое значение
    return k;
}

template <class T>
void Stack<T>::clear()
{
    // пока стек не пуст
    while (lastElement != nullptr)
    {
        // сохраняем последний элемент
        Node *last = lastElement;

        // переопределяем последний элемент
        lastElement = lastElement->prev;

        // удаляем последний элемент который сохраняли в last
        delete last;
    }
    _sizeOfStack = 0;
}

template <class T>
void Stack<T>::push(const T &k)
{
    // создаем новый узел
    Node *node = new Node{ k, lastElement };

    try {
        // память не выделелась
        if (node == nullptr)
        {
            throw EStackException("Error: memory is not allocated").what();
        }
    }  catch (const char* mes) {
        std::cout << mes << std::endl;
        return ;
    }

    // переопределяем созданный узел
    lastElement = node;

    // увеличиваем размер стека
    _sizeOfStack++;
}

template <class T>
void Stack<T>::enumeration(std::function<void(const T &k)> f) const
{
    // перебор начинаем с последнего
    Node *last = lastElement;

    // пока не дойдем до первого
    while (last != nullptr)
    {
        // вызов функции обратной связи
        f(last->value);
        last = last->prev;
    }
}
#endif // STACK_H
