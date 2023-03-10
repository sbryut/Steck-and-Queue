#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{
public:
	virtual void enQueue(const T& e) = 0; 
	virtual const T& deQueue() = 0;
	virtual bool isEmpty() = 0; 
};
#endif

