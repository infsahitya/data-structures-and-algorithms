#include <iostream>

#ifndef STACK_USING_ARRAY
#define STACK_USING_ARRAY

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
  T &pop();
  T &getTop();
  bool isFull();
  bool isEmpty();
  void display();
  size_t currentSize();
  void push(const T &element);
};

#include "stack.cpp"

#endif