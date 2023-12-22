#include <new>
#include <stdexcept>
#include "stack.h"

template <class T>
Stack<T>::Stack(){};

template <class T>
Stack<T>::Stack(const Stack<T> &copyStack)
{
  this->stack = copyStack.stack;
}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &copyStack)
{
  if (this != &copyStack)
  {
    this->stack = copyStack.stack;
  }

  return *this;
}

template <class T>
Stack<T>::~Stack() {}

template <class T>
T Stack<T>::pop()
{
  return this->stack.popBack();
}

template <class T>
T &Stack<T>::getTop()
{
  try
  {
    return this->stack[this->stack.getSize() - 1];
  }
  catch (const std::out_of_range &error)
  {
    throw std::out_of_range("Stack is empty");
  }
}

template <class T>
bool Stack<T>::isEmpty()
{
  if (this->stack.getSize() == 0)
    return true;

  return false;
}

template <class T>
void Stack<T>::display()
{
  size_t traverseSize{this->currentSize() - 1};
  for (int i{static_cast<int>(traverseSize)}; i >= 0; --i)
  {
    std::cout << this->stack[i];
    if (i == traverseSize)
    {
      std::cout << "  <--- Top" << std::endl;
    }
    else if (i == 0)
    {
      std::cout << "  <--- Bottom" << std::endl;
    }
    else
    {
      std::cout << std::endl;
    }
  }
}

template <class T>
size_t Stack<T>::currentSize()
{
  return this->stack.getSize();
}

template <class T>
void Stack<T>::push(const T &value)
{
  try
  {
    this->stack.pushBack(value);
  }
  catch (const std::bad_alloc &error)
  {
    throw error;
  }
}