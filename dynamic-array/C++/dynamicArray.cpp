#include "dynamicArray.h"

template <class T>
void DynamicArray<T>::shrink()
{
  size_t shrinkedSize = this->size - 1;
  T *shrinkedArray{new T[shrinkedSize]};

  for (size_t i{0}; i < shrinkedSize; ++i)
  {
    shrinkedArray[i] = this->array[i];
  }

  delete[] this->array;
  this->size = shrinkedSize;
  this->array = shrinkedArray;
}

template <class T>
void DynamicArray<T>::expand()
{
  size_t expandedSize = this->size + 1;
  T *expandedArray{new T[expandedSize]};

  for (size_t i{0}; i < this->size; ++i)
  {
    expandedArray[i] = this->array[i];
  }

  delete[] this->array;
  this->size = expandedSize;
  this->array = expandedArray;
}

template <class T>
DynamicArray<T>::DynamicArray() : array{nullptr}, size{0} {};

template <class T>
DynamicArray<T>::~DynamicArray()
{
  delete[] this->array;
}

template <class T>
T &DynamicArray<T>::operator[](const size_t index)
{
  if (index > 0 && index < this->size)
    return this->array[index];

  throw std::out_of_range("Index of out bounds");
}

template <class T>
const T &DynamicArray<T>::operator[](const size_t index) const
{
  if (index > 0 && index < this->size)
    return this->array[index];

  throw std::out_of_range("Index of out bounds");
}

template <class T>
void DynamicArray<T>::pushBack(const T &value)
{
  this->expand();
  this->array[this->size - 1] = value;
}

template <class T>
T &DynamicArray<T>::popBack() const
{
  const poppedElement = this->array[this->size - 1];
  this->shrink();
  return poppedElement;
}

template <class T>
void DynamicArray<T>::pushFront(const T &value)
{
  const DynamicArray<T> tempArray = this->array;
  this->expand();
  this->array[0] = value;
  for (size_t i{1}; i < this->size; ++i)
  {
    this->array[i] = tempArray[i - 1];
  }
}

template <class T>
T &DynamicArray<T>::popFront() const
{
  const poppedElement = this->array[0];
  const DynamicArray<T> tempArray = this->array;
  this->shrink();
  for (size_t i{0}; i < this->size; ++i)
  {
    this->array[i] = tempArray[i + 1];
  }
  return poppedElement;
}

template <class T>
bool DynamicArray<T>::isEmpty()
{
  return this->size == 0;
}

template <class T>
size_t DynamicArray<T>::getSize() const
{
  return this->size;
}