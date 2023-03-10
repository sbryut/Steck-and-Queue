#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include "Stack.h"
#include "StackExceptions.h"
#include <iostream>

template <typename T>
class StackArray : public Stack<T>
{
private:
	T* array_;
	size_t top_;
	size_t size_;
	void swap(StackArray<T>& src)
	{
		std::swap(this->array_, src.array_);
		std::swap(this->top_, src.top_);
		std::swap(this->size_, src.size_);
	}
public:

	StackArray(size_t size = 100) : size_(size), top_(0)
	{
		if (size < 1 || size > INT_MAX)  throw WrongStackSize();
		this->array_ = new T[size + 1];
	}

	StackArray(StackArray<T>&& src) : //конструктор перемещения
		size_(src.size_), top_(src.top_)
	{
		if (this->size_ < 1 || this->size_ > INT_MAX)  throw WrongStackSize();
		this->array_ = new T[size_ + 1];

		for (size_t i = 1; i <= src.top_; i++) { this->push(src.pop()); }
		delete src;
	}

	StackArray& operator= (StackArray<T>&& src) noexcept //оператор перемещающего присваивания
	{
		if (this != &src)  swap(src);
		return *this;
	}

	StackArray(const StackArray<T>& src) = delete; //конструктор копирования

	StackArray& operator= (const StackArray<T>& src) = delete; //оператор присваивания

	~StackArray() { delete this->array_; }

	void push(const T& e)
	{
		if (this->top_ == this->size_) throw StackOverflow();
		this->array_[++top_] = e;
	}

	const T& pop()
	{
		if (this->isEmpty()) throw StackUnderflow(); 
		return this->array_[top_--];
	}

	bool isEmpty() { return !((bool)this->top_); }
};

#endif