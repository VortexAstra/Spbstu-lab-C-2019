#ifndef MINUTELY_HPP
#define MINUTELY_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>


int part1(char *argv[]);
int part2(char *argv[]);
int part3(char *argv[]);
int part4(char *argv[]);


namespace minutely
{
  template<typename C>
  struct AccessByOperator
  {
    typedef std::size_t index_type;

    inline static typename C::value_type& getElement(C &cont, size_t index)
    {
      return cont[index];
    }

    inline static index_type getBegin(const C &)
    {
      return 0;
    }

    inline static index_type getEnd(const C &cont)
    {
      return cont.size();
    }
  };

  template<typename C>
  struct AccessByAt
  {
    typedef std::size_t index_type;

    inline static typename C::value_type& getElement(C &cont, size_t index)
    {
      return cont.at(index);
    }
    inline static index_type getBegin(const C &)
    {
      return 0;
    }
    inline static index_type getEnd(const C &cont)
    {
      return cont.size();
    }
  };

  template<typename C>
  struct AccessByIterator
  {
    typedef typename C::iterator index_type;
    inline static typename C::value_type& getElement(C &, typename C::iterator &it)
    {
      return *it;
    }
    inline static index_type getBegin(C &cont)
    {
      return cont.begin();
    }
    inline static index_type getEnd(C &cont)
    {
      return cont.end();
    }
  };

  template<typename T>
  bool more(const T a, const T b)
  {
    return a > b;
  };

  template<typename T>
  bool less(const T a, const T b)
  {
    return a < b;
  };
  template<typename T>
  using TypeCmp = bool (*)(const T, const T);


  template<template<class C> class Access, typename C>
  void sort_(C &container, char* typeSort)
  {
    typedef typename C::value_type ref;

    TypeCmp<ref> comp = !strcmp(typeSort,"ascending") ? more<ref> : less<ref>;

    typedef typename Access<C>::index_type typeIndex;
    for(typeIndex i = Access<C>::getBegin(container); i != Access<C>::getEnd(container); i++)
    {
      for(typeIndex j = i; j != Access<C>::getEnd(container); j++)
      {
        if(comp(Access<C>::getElement(container, i), Access<C>::getElement(container, j)))
        {
          std::swap(Access<C>::getElement(container, i), Access<C>::getElement(container, j));
        }
      }
    }
  };

  template<typename C>
  void printContainer(C &cl)
  {
    for(auto it = cl.begin(); it != cl.end(); it++)
    {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  };
}

#endif
