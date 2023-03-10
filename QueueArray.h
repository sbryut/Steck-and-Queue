#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include "Queue.h"
#include "QueueExceptions.h"
#include <iostream> 

template <typename T>
class QueueArray : public Queue<T>
{
private:
	T* array_;
	size_t head_;
	size_t tail_;
	size_t size_;

	void swap(QueueArray<T>& src)
	{
		std::swap(this->array_, src.array_);
		std::swap(this->top_, src.top_);
		std::swap(this->size_, src.size_);
	}
public:

	QueueArray(size_t size = 100) : size_(size), head_(1), tail_(1)
	{
		if (size_ < 1 || size_ > INT_MAX)  throw WrongQueueSize();
		this->array_ = new T[size_ + 1];
		this->array_[head_] = NULL;
	}

	QueueArray(QueueArray<T>&& src) : //конструктор перемещения
		size_(src.size_), head_(src.head_), tail_(src.tail_)
	{
		if (this->size_ < 1 || this->size_ > INT_MAX)  throw WrongQueueSize();
		this->array_ = new T[size_ + 1];

		for (size_t i = 1; i <= src.size_; i++) 
		{
			this->array_[i](src->array_[i]()); 
			//src.deQueue();
		}
		delete src;
	}

	QueueArray& operator= (QueueArray<T>&& src) noexcept //оператор перемещающего присваивания
	{
		if (this != &src)  swap(src);
		return *this;
	}

	QueueArray(const QueueArray<T>& src) = delete; //конструктор копирования

	QueueArray& operator= (const QueueArray<T>& src) = delete; //оператор присваивания

	~QueueArray() { delete this->array_; }

	void enQueue(const T& e)
	{
		if ((this->head_ == this->tail_ + 1) || (this->head_ == 1 && this->tail_ == size_)) throw QueueOverflow();
		if (this->tail_ == this->size_ && this->head_ != 1) this->tail_ = 1;
		else if (this->isEmpty()) this->tail_ = 1;
		else ++this->tail_;
		this->array_[tail_] = e;
	}

	const T& deQueue()
	{
		if (this->isEmpty()) throw QueueUnderflow();
		T helper = this->array_[head_];
		this->array_[head_] = NULL;
		if (this->head_ == this->size_) this->head_ = 1;
		else ++this->head_;
		return helper;
	}

	bool isEmpty() { return ((bool)(this->head_ == this->tail_) && this->array_[head_] == NULL); }
};

#endif
