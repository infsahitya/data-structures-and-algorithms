#include <new>
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "dynamicArray.h"

int main()
{
  char userChoice;
  DynamicArray<int> intArray;

  do
  {
    try
    {

      std::cout << std::endl
                << std::endl;
      std::cout << "1. Press (D or d) to display all the elements." << std::endl;
      std::cout << "2. Press (F or f) to push a new element in front." << std::endl;
      std::cout << "3. Press (B or b) to push a new element in back." << std::endl;
      std::cout << "4. Press (P or p) to pop an element from front." << std::endl;
      std::cout << "5. Press (Q or q) to pop an element from back." << std::endl;
      std::cout << "6. Press (S or s) to get the current size." << std::endl;
      std::cout << "7. Press (C or c) to get an element from index." << std::endl;
      std::cout << "8. Press (U or u) to edit an element on index." << std::endl;
      std::cout << "9. Press (E or e) to exit the program." << std::endl;
      std::cout << "Enter your choice: ";
      std::cin >> userChoice;
      std::cout << std::endl;

      userChoice = std::tolower(static_cast<unsigned char>(userChoice));

      if (userChoice == 'd')
      {
        std::cout << std::endl;
        for (size_t i{0}; i < intArray.getSize(); ++i)
        {
          std::cout << intArray[i] << "\t";
        }
        std::cout << std::endl;
      }
      else if (userChoice == 'f')
      {
        int value;
        std::cout << "Enter the value you want to push in front: ";
        std::cin >> value;
        intArray.pushFront(value);
      }
      else if (userChoice == 'b')
      {
        int value;
        std::cout << "Enter the value you want to push in back: ";
        std::cin >> value;
        intArray.pushBack(value);
      }
      else if (userChoice == 'p')
      {
        const int poppedElement = intArray.popFront();
        std::cout << "Popped " << poppedElement << " from the front of the array.";
      }
      else if (userChoice == 'q')
      {
        const int poppedElement = intArray.popBack();
        std::cout << "Popped " << poppedElement << " from the back of the array.";
      }
      else if (userChoice == 's')
      {
        std::cout << "Current size of the array is " << intArray.getSize();
      }
      else if (userChoice == 'c')
      {
        size_t index{};
        std::cout << "Enter the index you want to access: ";
        std::cin >> index;
        std::cout << std::endl
                  << "Array[" << index << "] = " << intArray[index] << std::endl;
      }
      else if (userChoice == 'u')
      {
        size_t index{};
        std::cout << "Enter the index you want to edit: ";
        std::cin >> index;
        std::cout << "Enter the value you want to update: ";
        std::cin >> intArray[index];
        std::cout << std::endl;
      }
    }
    catch (const std::bad_alloc &error)
    {
      std::cerr << "Exception: " << error.what() << std::endl;
    }
    catch (const std::underflow_error &error)
    {
      std::cerr << "Exception: " << error.what() << std::endl;
    }
    catch (const std::out_of_range &error)
    {
      std::cerr << "Exception: " << error.what() << std::endl;
    }
  } while (userChoice != 'e');

  std::cout << "Exiting the program..." << std::endl;

  return 0;
}