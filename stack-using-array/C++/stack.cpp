#include "stack.h"

template <class T>
Stack<T>::Stack(size_t stackSize) : maxSize{stackSize}
{
  this->stack = new T[maxSize];
  top = -1;
}

template <class T>
Stack<T>::Stack(const Stack<T> &copyStack) : maxSize{copyStack.maxSize}, top{copyStack.top}
{
  this->stack = new T[maxSize];
  std::copy(copyStack.stack, copyStack.stack + this->maxSize, this->stack);
}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &copyStack)
{
  if (this != &copyStack)
  {
    delete[] stack;
    this->maxSize = copyStack.maxSize;
    this->top = copyStack.top;
    this->stack = new T[this->maxSize];
    std::copy(copyStack.stack, copyStack.stack + this->maxSize, this->stack);
  }

  return *this;
}

template <class T>
Stack<T>::~Stack()
{
  delete[] stack;
}

template <class T>
bool Stack<T>::isEmpty()
{
  return (top == -1);
}

template <class T>
bool Stack<T>::isFull()
{
  return (top == maxSize - 1);
}

template <class T>
T &Stack<T>::getTop()
{
  if (!isEmpty())
    return (stack[top]);

  std::cout << "Stack is empty" << std::endl;
}

template <class T>
void Stack<T>::push(const T &element)
{
  if (!isFull())
  {
    stack[++top] = element;
    return;
  }
  throw std::overflow_error("Stack Overflow");
}

template <class T>
T &Stack<T>::pop()
{
  if (!isEmpty())
    return (stack[top--]);
  throw std::underflow_error("Stack Underflow");
}

template <class T>
size_t Stack<T>::currentSize()
{
  return (top + 1);
}

template <class T>
void Stack<T>::display()
{
  size_t traverseSize{this->currentSize() - 1};
  for (int i{traverseSize}; i >= 0; --i)
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