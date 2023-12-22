#include "dynamicArray.h"

template <class T>
void DynamicArray<T>::shrink()
{
  size_t shrinkedSize = this->size - 1;
  if (shrinkedSize > 0)
  {
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
    this->size = 0;
    delete[] this->array;
  }
}

template <class T>
void DynamicArray<T>::expand()
{
  size_t expandedSize = this->size + 1;
  T *expandedArray{new T[expandedSize]};

  if (expandedArray != nullptr)
  {
    for (size_t i{0}; i < this->size; ++i)
    {
      expandedArray[i] = this->array[i];
    }

    delete[] this->array;
    this->size = expandedSize;
    this->array = expandedArray;
  }
  else
  {
    throw std::bad_alloc("Memory allocation failed.");
  }
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
const T &DynamicArray<T>::popBack()
{
  const size_t lastIndex = this->size - 1;
  if (lastIndex > -1)
  {
    const poppedElement = this->array[lastIndex];
    this->shrink();
    return poppedElement;
  }

  throw std::underflow_error("Array in underflow state");
}

template <class T>
void DynamicArray<T>::pushFront(const T &value)
{
  const DynamicArray<T> tempArray = *this;
  this->expand();
  this->array[0] = value;
  for (size_t i{1}; i < this->size; ++i)
  {
    this->array[i] = tempArray->array[i - 1];
  }
  delete tempArray;
}

template <class T>
const T &DynamicArray<T>::popFront()
{
  if (this->size > 0)
  {
    const poppedElement = this->array[0];
    const DynamicArray<T> tempArray = *this;
    this->shrink();
    for (size_t i{0}; i < this->size; ++i)
    {
      this->array[i] = tempArray->array[i + 1];
    }

    delete tempArray;
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