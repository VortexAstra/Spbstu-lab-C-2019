#include <string>

#include "source.hpp"

void fillRandom(double * array, int size)
{
  for(int i = 0; i < size; i++)
    array[i]= (static_cast<double> (rand())/RAND_MAX ) * 2 - 1.0;
}

int part4(char *argv[])
{
  if ( strcmp(argv[2],"ascending") != 0 && strcmp(argv[2],"descending") != 0)
  {
    throw std::invalid_argument("Not correct type sort \n");
  }

  std::vector<double> coll(std::stoi(argv[3]));

  fillRandom(&coll[0], coll.size());
  minutely::printContainer(coll);

  minutely::sort_<minutely::AccessByIterator>(coll, argv[2]);
  minutely::printContainer(coll);

  return 0;
}
