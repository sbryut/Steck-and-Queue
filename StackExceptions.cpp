#include "StackExceptions.h"

StackOverflow::StackOverflow() : reason_("Stack Overflow!") {}
const char* StackOverflow::what() const { return this->reason_.c_str(); }

StackUnderflow::StackUnderflow() : reason_("Stack Underflow!") {}
const char* StackUnderflow::what() const { return this->reason_.c_str(); }

WrongStackSize::WrongStackSize() : reason_("Wrong size of the stack!") {}
const char* WrongStackSize::what() const { return this->reason_.c_str(); }
