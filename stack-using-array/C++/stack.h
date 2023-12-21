#ifndef STACK_USING_ARRAY
#define STACK_USING_ARRAY

#include <iostream>
#include <stdexcept>

template <class T>
class Stack
{
private:
  T *stack;
  int top;
  size_t maxSize;

public:
  Stack(size_t stackSize = 999);
  Stack(const Stack<T> &copyStack);
  Stack<T> &operator=(const Stack<T> &copyStack);
  ~Stack();
  T &getTop();
  T &pop();
  void push(const T &element);
  bool isEmpty();
  bool isFull();
  size_t currentSize();
};

#include "stack.cpp"

#endif