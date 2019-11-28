#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <vector>
#include <locale>

enum type
{
  letter, numDigit, other
};

void refine(std::vector<char> &buffer, const std::locale& cloc);

type determineType(char symbol, const std::locale& cloc);

#endif // OPTIONS_HPP

