#include <iostream>
#include "dynamicArray.h"

#ifndef STACK_USING_DYNAMIC_ARRAY
#define STACK_USING_DYNAMIC_ARRAY

template <class T>
class Stack
{
private:
  DynamicArray<T> stack;

public:
  Stack();
  Stack(const Stack<T> &copyStack);
  Stack<T> &operator=(const Stack<T> &copyStack);
  ~Stack();
  
  T pop();
  T &getTop();
  bool isEmpty();
  void display();
  size_t currentSize();
  void push(const T &value);
};

#include "stack.cpp"

#endif