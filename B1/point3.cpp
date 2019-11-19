#include "source.hpp"

int part3(char *[])
{
  std::vector<int> coll;
  int value;

  while(std::cin >> value)
  {
    if (value == 0 )
    {
      coll.push_back(value);
      break;
    }
    coll.push_back(value);
  }

  if(std::cin.fail() && !std::cin.eof())
  {
    throw std::invalid_argument("Incorrect input \n");
  }
  if(coll.empty())
  {
    return 0;
  }

  if(!coll.empty())
  {
    if(coll.back() != 0)
    {
      throw std::invalid_argument("Error: expected zero before end of input");
    }
    else
    {
      coll.pop_back();
    }
  }

  if(coll.empty())
  {
    return 0;
  }

  int lastNum = coll.back();
  switch(lastNum)
  {
    case 1:
    {
      auto tmp = coll.begin(); //std::vector<int>::iterator
      while(tmp != coll.end())
      {
        if(*tmp % 2 == 0)
        {
          tmp = coll.erase(tmp);
        }
        else
        {
          tmp++;
        }
      }
    }
      break;
    case 2:
    {
      auto tmp = coll.begin(); //std::vector<int>::iterator
      while(tmp != coll.end())
      {
        if(*tmp % 3 == 0)
        {
          tmp = coll.insert(tmp +1, 3, 1) +3;
        }
        else
        {
          tmp++;
        }
      }
    }
      break;

    default:
      break;
  }

  minutely::printContainer(coll);

  return 0;
}
