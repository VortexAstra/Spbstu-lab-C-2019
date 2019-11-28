#include <utility>
#include <locale>
#include "options.hpp"

type determineType(char symbol, const std::locale &cloc)
{
  if (std::isalpha(symbol, cloc))
  {
    return letter;
  }
  if (std::isdigit(symbol, cloc) || symbol == '+')
  {
    return numDigit;
  }
  return other;
}


void refine(std::vector<char> &buffer, const std::locale &cloc)
{

  bool commaFlag = false, dashFlag = false, otherFlag = false;
  char puncMark = ' ';
  std::size_t i = 0, end = buffer.size();
  while (i != end)
  {
    if (std::isspace(buffer[i], cloc))
    {
      i++;
      continue;
    }

    if (dashFlag || otherFlag)
    {
      buffer.clear();
      return;
    }

    switch (buffer[i])
    {
      case ',':
      {
        if (commaFlag)
        {
          buffer.clear();
          return;
        }
        commaFlag = true;
        puncMark = ',';
      }
        break;
      case '-':
      {
        if (i + 2 < end && buffer[i + 2] == '-' && buffer[i + 1] == '-')
        {
          dashFlag = true;
          i += 3;
          continue;
        } else
        {
          buffer.clear();
          return;
        }
      }
        break;
      default:
      {
        if (commaFlag)
        {
          buffer.clear();
          return;
        }
        puncMark = buffer[i];
        otherFlag = true;
      }
        break;
    }
    i++;
  }

  buffer.clear();

  if (otherFlag || commaFlag)
  {
    buffer.push_back(puncMark);
  }

  if (dashFlag)
  {
    buffer.push_back(' ');
    buffer.insert(buffer.end(), 3, '-');
  }

  buffer.push_back(' ');
}
