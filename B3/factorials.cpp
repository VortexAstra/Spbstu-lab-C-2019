
#include <iostream>
#include <algorithm>

#include "factorialContainer.hpp"

void calculateFactorials(std::ostream &out)
{
  FactorialContainer cont;

  std::copy(cont.begin(), cont.end(), std::ostream_iterator<unsigned int>(out, " "));
  out << std::endl;

  std::reverse_copy(cont.begin(), cont.end(), std::ostream_iterator<unsigned int>(out, " "));
  out << std::endl;

}
