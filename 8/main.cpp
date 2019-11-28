#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <locale>
#include <cstdio>
#include "options.hpp"

std::locale cloc;


int main(int argc, char *argv[])
{
  cloc = std::cout.getloc();

  size_t lineWidthMax = 0;
  switch (argc)
  {
    case 1:
    {
      lineWidthMax = 40;
    }
      break;
    case 3:
    {
      if (std::string(argv[1]) != "--line-width")
      {
        std::cerr << "Use --line-width";
        return 1;
      }
      try
      {
        lineWidthMax = std::stoi(argv[2]);
      }
      catch (std::invalid_argument)
      {
        std::cerr << "Bad line width";
        return 1;
      }
    }
      break;
    default:
    {
      std::cerr << "Bad arguments";
      return 1;
    }
  }

  if (lineWidthMax < 25)
  {
    std::cerr << "Bad line width";
    return 1;
  }


  char decimal_separator = std::use_facet<std::numpunct<char> >(cloc).decimal_point();
  bool nextIsDigit = false;

  std::vector<char> vec;
  std::vector<char> buffer;

  std::cin >> std::ws;

  size_t counter = 0;
  char ch = std::cin.get();

  if (ch == EOF)
  {
    return 0;
  }

  type prev = determineType(ch, cloc);
  if (prev != other)
  {
    vec.push_back(ch);
    ++counter;
  } else
  {
    char chp = std::cin.peek();
    if ((ch == '-') && (determineType(chp, cloc) == numDigit) && (chp != '+'))
    {
      vec.push_back(ch);
      ++counter;
      prev = numDigit;
    } else
    {
      std::cerr << "First - punctuation prohibited";
      return 1;
    }
  }


  size_t lineStart = 0;
  size_t possibleLineEnd = 0;
  std::vector<size_t> bordArray;


  while ((ch = std::cin.get()) != EOF)
  {
    type st{ determineType(ch, cloc) };

    if ((st == letter) || (st == numDigit))
    {
      vec.push_back(ch);
      if (prev == st)
      {
        ++counter;
      } else
      {
        if (prev != other)
        {
          std::cerr << "Bad input";
          return 1;
        }
        prev = st;
        counter = 1;
      }
    } else
    {
      if (((ch == decimal_separator) && (prev == numDigit) && (determineType(std::cin.peek(), cloc) == numDigit)) ||
          ((ch == '-') && (prev == letter) && (std::cin.peek() != '-')))
      {
        vec.push_back(ch);
        ++counter;
        continue;
      }

      if (prev != other)
      {
        if (counter > 20)
        {
          std::cerr << "Too long word/number";
          return 1;
        } else
        {
          counter = 0;
        }
        buffer.clear();
        buffer.push_back(ch);

        while (determineType(std::cin.peek(), cloc) == other && (std::cin.peek() != EOF))
        {
          ch = std::cin.get();
          buffer.push_back(ch);
        }

        char chp = std::cin.peek();
        if ((ch == '-') && (buffer[buffer.size() - 2] != '-') && (determineType(chp, cloc) == numDigit) && (chp != '+'))
        {
          nextIsDigit = true;
          buffer.pop_back();
        }

        refine(buffer, cloc);
        if (buffer.empty())
        {
          std::cerr << "Bad input";
          return 1;
        }

        vec.insert(vec.end(), buffer.begin(), buffer.end());


        size_t currentWidth = vec.size() - lineStart;
        if (currentWidth < lineWidthMax)
        {
          possibleLineEnd = vec.size() - 1;
        } else
        {
          size_t lineEnd = 0;
          if ((currentWidth == lineWidthMax) || (currentWidth == lineWidthMax + 1))
          {
            lineEnd = vec.size() - 1;
          } else
          {
            lineEnd = possibleLineEnd;
          }
          bordArray.push_back(lineEnd);
          lineStart = lineEnd + 1;
          possibleLineEnd = vec.size() - 1;
        }


        if (!nextIsDigit)
        {
          prev = other;
        } else
        {
          nextIsDigit = false;
          vec.push_back('-');
          counter = 1;
          prev = numDigit;
        }
      }
    }
  }

  if (counter > 20)
  {
    std::cerr << "Too long word/number";
    return 1;
  }

  if ((vec.size() - lineStart) > lineWidthMax)
  {
    bordArray.push_back(possibleLineEnd);
  }

  std::vector<char *> strVec;
  auto it = vec.begin();
  strVec.push_back(&(*it));

  for (size_t i = 0; i != bordArray.size(); i++)
  {
    vec[bordArray[i]] = '\0';
    strVec.push_back(&(vec[bordArray[i] + 1]));
  }

  if (*(vec.end() - 1) == ' ')
  {
    *(vec.end() - 1) = '\0';
  } else
  {
    vec.push_back('\0');
  }

  for (auto &it : strVec)
  {
    std::printf("%s", it);
    std::cout << std::endl;
  }

  return 0;
}

