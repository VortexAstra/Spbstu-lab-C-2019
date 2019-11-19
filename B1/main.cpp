#include <iostream>
#include <stdexcept>
#include <string>
#include "source.hpp"

int main(int argc, char *argv[])
{
  try
  {
    if ((argc < 2) || (argc >= 5))
    {
      std::cerr << "number parameters argc incorrect! \n";
      return 1;
    }

    auto variant = std::stoi(argv[1]); //int

    switch (variant)
    {
      case 1:
        if (argc != 3)
        {
          std::cerr << "Incorrect amount of parameters for task #1." << std::endl;
          return 1;
        }
        part1(argv);
        break;

      case 2:
        if (argc != 3)
        {
          std::cerr << "Incorrect number of arguments.\n";
          return 1;
        }
        part2(argv);
        break;

      case 3:
        if (argc != 2)
        {
          std::cerr << "Incorrect number of arguments.\n";
          return 1;
        }
        part3(argv);
        break;

      case 4:
        if (argc != 4)
        {
          std::cerr << "Incorrect number of arguments.\n";
          return 1;
        }

        srand(time(nullptr));
        part4(argv);
        break;

      default:
        std::cerr << "Wrong task number." << std::endl;
        return 1;
    }
  }

  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
