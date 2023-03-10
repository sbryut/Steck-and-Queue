#include <iostream>
#include "StackArray.h"
#include "QueueArray.h"


int getBracketType(char bracket);
bool checkBalanceBrackets(const std::string& text, const int maxDepth);

int main() 
{
    //==================STACK==================//
    try 
    {
        StackArray<int> stack(6);

        //std::cout << stack.pop() << ' '; //stack is empty
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(6);
        //stack.push(7); // stack is full

        std::cout << "Stack of int elements: ";
        while (!(stack.isEmpty()))
        {
            std::cout << stack.pop() << ' ';
        }
    }
    catch (std::exception const& e) 
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
    std::cout << '\n' << '\n';
    //=================BRACKETS=================//
    try {
        bool result = checkBalanceBrackets("{([])}([{}{()}])", 4); // {([])}([{}{()}]) ([]}) [()k]
        if (result) std::cout << "The brackets are correct!";
        else std::cout << "The brackets are wrong!";
    }
    catch (std::exception const& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
    std::cout << '\n' << '\n';
    //==================QUEUE==================//
    try
    {
        QueueArray<char> queue(5);
        //std::cout << queue.deQueue() << ' '; //queue is empty
        queue.enQueue('a');
        queue.enQueue('b');
        queue.enQueue('c');
        queue.enQueue('d');
        queue.enQueue('e');

        std::cout << "Queue of char elements:\n";
        std::cout << queue.deQueue() << ' ';
        std::cout << queue.deQueue() << '\n';

        queue.enQueue('3');
        queue.enQueue('5');

        while (!(queue.isEmpty()))
        {
            std::cout << queue.deQueue() << ' ';
        }
    }
    catch (std::exception const& e) 
    {
        std::cout << "Error: " << e.what() << "\n";
    }
    std::cout << '\n';
	return 0;
}


int getBracketType(char bracket) {
    if (bracket == '(') return 0;
    else if (bracket == ')') return 1;
    else if (bracket == '[') return 2;
    else if (bracket == ']') return 3;
    else if (bracket == '{') return 4;
    else if (bracket == '}') return 5;
    std::string helper(1, bracket);
    throw std::invalid_argument("'" + helper + "' is not a bracket");
}

bool checkBalanceBrackets(const std::string& text, const int maxDepth)
{
    StackArray<char> stack(maxDepth);
   
    for (auto i : text) {
        int type = getBracketType(i);
        if (type % 2 == 0) {
            try {
                stack.push(i);
            }
            catch (StackOverflow& e) {
                std::cerr << e.what() << '\n';
                return false;
            }
        }
        else {
            type /= 2;
            try {
                char removed = stack.pop();
                if (getBracketType(removed) / 2 != type) {
                    return false;
                }
            }
            catch (StackUnderflow& e) {
                std::cerr << e.what() << '\n';
                return false;
            }
        }
    }
    return true;
}