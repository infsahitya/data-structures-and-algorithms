#include <iostream>
#include <stdexcept>
#include "stack.h"

int main()
{
  size_t userStackSize{0};

  std::cout << "What should be the size of your integer stack?";
  std::cin >> userStackSize;
  std::cout << std::endl;

  Stack<int> stack1(userStackSize);

  try
  {
    std::cout << "Enter the " << userStackSize << " integer values for you stack..." << std::endl;

    for (int i{0}; i < userStackSize; ++i)
    {
      int tempStackValue;
      std::cin >> tempStackValue;
      stack1.push(tempStackValue);
    }
  }
  catch (const std::overflow_error &error)
  {
    std::cerr << "Exception: " << error.what() << std::endl;
  }
  catch (const std::underflow_error &error)
  {
    std::cerr << "Exception: " << error.what() << std::endl;
  }

  return 0;
}