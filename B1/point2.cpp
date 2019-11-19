#include <fstream>
#include <memory>

#include "source.hpp"


int part2(char *argv[])
{
  std::ifstream input(argv[2]);

  if(!input.is_open())
  {
    throw std::invalid_argument("Incorrect filename");
  }

  //size_T
  auto size = 0;
  auto contentCapacity = 16;

  std::unique_ptr<char[], decltype(&free)> contents(static_cast<char *>(malloc(contentCapacity)), free);

  while (input)
  {
    input.read(&contents[size], contentCapacity - size);
    size += input.gcount();

    if (size == contentCapacity)
    {
      contentCapacity *= 2;
      auto temp_content = contents.release();

      contents.reset(static_cast<char *>(std::realloc(temp_content, contentCapacity)));

      if (!contents)
      {
        throw std::runtime_error("Allocate memory error");
      }
    }
  }

  input.close();

  if(input.is_open())
  {
    throw std::ios_base::failure("File closure failed");
  }

  if(input.eof())
    throw std::runtime_error("reading failed");

  std::vector<char> vector(&contents[0], &contents[size]);

  for (const auto &it : vector) //char
  {
    std::cout << it;
  }

  return 0;
}
