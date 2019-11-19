#include <iostream>
#include <list>

void runOption2()
{
  std::list<int> list;

  int nextNum;

  while(std::cin >> nextNum)
  {
    if((nextNum < 1) || (nextNum > 20))
    {
      throw std::out_of_range("Value not in range");
    }

    list.push_back(nextNum);
  }

  if(std::cin.fail() && !std::cin.eof())
  {
    throw std::invalid_argument("incorrect input");
  }

  if (list.size() > 20)
  {
    throw std::invalid_argument("too many elements");
  }

  auto it_next = list.begin();
  auto it_prev = list.rbegin();

  for (size_t i = 0; i < list.size() / 2; ++i)
  {
    std::cout << *it_next << " " << *it_prev << " ";
    it_next++;
    it_prev++;
  }

  if (list.size() % 2 == 1)
  {
    std::cout << *it_next;
  }

  std::cout << std::endl;
}
