#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack: public std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack()
{

}

template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
size_t Stack<T>::size() const
{
	return this->std::vector<T>::size();
}

template <typename T>
bool Stack<T>::empty() const
{
    return this->std::vector<T>::empty();
}

template <typename T>
void Stack<T>::push(const T& item)
{
    this->std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop()
{
	if (empty())
	{
		throw std::underflow_error("the stack is empty");
	}
  this->pop_back();
}

template <typename T>
T const & Stack<T>::top() const
{
	if (empty())
	{
		throw std::underflow_error("the stack is empty");
	}
    return this->back();
}

#endif