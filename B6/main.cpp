#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include "getStats.hpp"

int main()
{
  GetStats getStats;
  std::for_each(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::ref(getStats));

  if (!std::cin.eof())
  {
    std::cerr << "Invalid input";
    return 1;
  }

  getStats.printStats(std::cout);

  return 0;
}
