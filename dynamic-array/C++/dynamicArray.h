#include <iostream>

#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

template <class T>
class DynamicArray
{
private:
  T *array;
  size_t size;
  void shrink();
  void expand();

public:
  DynamicArray();
  DynamicArray(const DynamicArray<T> &copyDynamicArray);
  ~DynamicArray();
  DynamicArray<T> &operator=(const DynamicArray<T> &copyDynamicArray);
  T &operator[](const size_t index);
  const T &operator[](const size_t index) const;
  void pushBack(const T &value);
  T &popBack();
  void pushFront(const T &value);
  T &popFront();
  bool isEmpty();
  size_t getSize() const;
};

#include "dynamicArray.cpp"

#endif