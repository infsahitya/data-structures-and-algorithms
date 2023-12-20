#include <iostream>

template <class T>
class Stack
{
private:
  T *stack;
  int top;
  size_t maxSize;

public:
  Stack(size_t stackSize = 999);
  ~Stack();
  T &getTop();
  T &pop();
  void push(const T &element);
  bool isEmpty();
  bool isFull();
  size_t currentSize();
};

template <class T>
Stack<T>::Stack(size_t stackSize) : maxSize{stackSize}
{
  stack = new T[maxSize];
  top{-1};
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

  std::cout << "Stack overflow" << std::endl;
}

template <class T>
T &Stack<T>::pop()
{
  if (!isEmpty())
    return (stack[top--]);

  std::cout << "Stack underflow" << std::endl;
}

template <class T>
size_t Stack<T>::currentSize()
{
  return (top + 1);
}