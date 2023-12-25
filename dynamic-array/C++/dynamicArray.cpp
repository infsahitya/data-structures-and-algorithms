#include <new>
#include <stdexcept>
#include "dynamicArray.h"

template <class T>
void DynamicArray<T>::shrink()
{
  size_t currentSize = this->getSize();

  if (currentSize > 0)
  {
    size_t shrinkedSize = currentSize - 1;
    T *shrinkedArray{new T[shrinkedSize]};

    for (size_t i{0}; i < shrinkedSize; ++i)
    {
      shrinkedArray[i] = this->array[i];
    }

    delete[] this->array;
    this->size = shrinkedSize;
    this->array = shrinkedArray;
  }
  else
  {
    throw std::underflow_error("Array in underflow state");
  }
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
DynamicArray<T>::DynamicArray(const DynamicArray<T> &copyDynamicArray) : size{copyDynamicArray.getSize()}
{
  this->size = copyDynamicArray.getSize();
  this->array = new T[this->size];
  std::copy(copyDynamicArray.array, copyDynamicArray.array + this->size, this->array);
}

template <class T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray<T> &copyDynamicArray)
{
  if (this != &copyDynamicArray)
  {
    this->size = copyDynamicArray.getSize();
    this->array = new T[this->size];
    std::copy(copyDynamicArray.array, copyDynamicArray.array + this->size, this->array);
  }

  return *this;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
  delete[] this->array;
}

template <class T>
T &DynamicArray<T>::operator[](const size_t index)
{
  if (index < this->size)
    return this->array[index];

  throw std::out_of_range("Index of out bounds");
}

template <class T>
const T &DynamicArray<T>::operator[](const size_t index) const
{
  if (index < this->size)
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
T DynamicArray<T>::popBack()
{
  T poppedElement = this->array[this->getSize() - 1];
  this->shrink();
  return poppedElement;
}

template <class T>
void DynamicArray<T>::pushFront(const T &value)
{
  const DynamicArray<T> tempArray = *this;
  this->expand();
  this->array[0] = value;
  for (size_t i{1}; i < this->size; ++i)
  {
    this->array[i] = tempArray[i-1];
  }
}

template <class T>
T DynamicArray<T>::popFront()
{
  if (this->size > 0)
  {
    T poppedElement = this->array[0];
    const DynamicArray<T> tempArray = *this;
    this->shrink();
    for (size_t i{0}; i < this->size; ++i)
    {
      this->array[i] = tempArray[i + 1];
    }
    return poppedElement;
  }

  throw std::underflow_error("Array in underflow state");
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