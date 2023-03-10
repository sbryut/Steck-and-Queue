#ifndef STACK_EXCEPTIONS_H
#define  STACK_EXCEPTIONS_H

#include <exception>
#include <string>

class StackOverflow : public std::exception
{
private:
	const std::string reason_;
public:
	StackOverflow();
	const char* what() const;
};

class StackUnderflow : public std::exception
{
private:
	const std::string reason_;
public:
	StackUnderflow();
	const char* what() const;
};

class WrongStackSize : public std::exception
{
private:
	const std::string reason_;
public:
	WrongStackSize();
	const char* what() const;
};

#endif

