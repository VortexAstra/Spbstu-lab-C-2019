#include <forward_list>

#include "source.hpp"

int part1(char *argv[])
{

  if ( strcmp(argv[2],"ascending") != 0 && strcmp(argv[2],"descending") != 0)
  {
    throw std::invalid_argument("Not correct type sort \n");
  }

  std::vector<int> coll_1;
  int value;

  while(std::cin >> value)
  {
    coll_1.push_back(value);
  }

  if(std::cin.fail() && !std::cin.eof())
  {
    throw std::invalid_argument("Incorrect input number");
  }

  if(coll_1.empty())
  {
    return 0;
  }


  std::vector<int> coll_2(coll_1.begin(), coll_1.end());
  std::forward_list<int> coll_3(coll_1.begin(), coll_1.end());

  minutely::sort_<minutely::AccessByOperator>(coll_1, argv[2]);
  minutely::sort_<minutely::AccessByAt>(coll_2, argv[2]);
  minutely::sort_<minutely::AccessByIterator>(coll_3, argv[2]);

  minutely::printContainer(coll_1);
  minutely::printContainer(coll_2);
  minutely::printContainer(coll_3);

  return 0;
}
