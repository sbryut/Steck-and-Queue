#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
public:
	virtual void push(const T& e) = 0; //добавление элемента в стек
	virtual const T& pop() = 0; //удаление и возвращение верхнего элемента
	virtual bool isEmpty() = 0;//проверка стека на пустоту
};

#endif
