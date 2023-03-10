#include "QueueExceptions.h"

QueueOverflow::QueueOverflow() : reason_("Queue Overflow!") {}
const char* QueueOverflow::what() const { return this->reason_.c_str(); }

QueueUnderflow::QueueUnderflow() : reason_("Queue Underflow!") {}
const char* QueueUnderflow::what() const { return this->reason_.c_str(); }

WrongQueueSize::WrongQueueSize() : reason_("Wrong size of the queue!") {}
const char* WrongQueueSize::what() const { return this->reason_.c_str(); }
