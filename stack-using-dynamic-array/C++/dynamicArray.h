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

  T popBack();
  T popFront();
  bool isEmpty();
  size_t getSize() const;
  void pushBack(const T &value);
  void pushFront(const T &value);
  T &operator[](const size_t index);
  const T &operator[](const size_t index) const;
  DynamicArray<T> &operator=(const DynamicArray<T> &copyDynamicArray);
};

#include "dynamicArray.cpp"

#endif