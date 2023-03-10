#ifndef QUEUE_EXCEPTIONS_H
#define QUEUE_EXCEPTIONS_H

#include <exception>
#include <string>

class QueueOverflow : public std::exception
{
private:
	const std::string reason_;
public:
	QueueOverflow();
	const char* what() const;
};

class QueueUnderflow : public std::exception
{
private:
	const std::string reason_;
public:
	QueueUnderflow();
	const char* what() const;
};

class WrongQueueSize : public std::exception
{
private:
	const std::string reason_;
public:
	WrongQueueSize();
	const char* what() const;
};

#endif

