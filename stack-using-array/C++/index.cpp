#include <cctype>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "stack.h"

int main()
{
  size_t userStackSize{0};
  std::string userChoice;

  std::cout << "What should be the size of your integer stack? ";
  std::cin >> userStackSize;
  std::cout << std::endl;

  Stack<int> intStack(userStackSize);

  do
  {
    try
    {

      std::cout << std::endl
                << std::endl;
      std::cout << "1. Press (D) to display all the elements." << std::endl;
      std::cout << "2. Press (I) to push a new element." << std::endl;
      std::cout << "3. Press (P) to pop an element." << std::endl;
      std::cout << "4. Press (C) to get the current size." << std::endl;
      std::cout << "5. Press (T) to get the top element." << std::endl;
      std::cout << "6. Press (E) to exit the program." << std::endl;
      std::cout << "Enter your choice: ";
      std::cin >> userChoice;
      std::cout << std::endl;

      std::transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);

      if (userChoice == "d")
      {
        intStack.display();
      }
      else if (userChoice == "i")
      {
        int value;
        std::cout << "Enter the value you want to push: ";
        std::cin >> value;
        intStack.push(value);
      }
      else if (userChoice == "p")
      {
        const int poppedElement = intStack.pop();
        std::cout << "Popped " << poppedElement << " from the stack.";
      }
      else if (userChoice == "c")
      {
        std::cout << "Current size of stack is " << intStack.currentSize() << " out of max size of " << userStackSize;
      }
      else if (userChoice == "t")
      {
        std::cout << "Top element of the stack is " << intStack.getTop();
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
  } while (userChoice != "exit" && userChoice != "e");

  std::cout << "Exiting the program..." << std::endl;

  return 0;
}