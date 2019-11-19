#include "factorialContainer.hpp"

const unsigned int firstValue = 1;
const unsigned int firstIndex = 1;

const unsigned int lastValue = 39916800;
const unsigned int lastIndex = 11;

FactorialContainer::iterator FactorialContainer::begin()
{
  return FactorialContainer::iterator(firstValue, firstIndex);
}

FactorialContainer::iterator FactorialContainer::end()
{
  return FactorialContainer::iterator(lastValue, lastIndex);
}

FactorialContainer::iterator::iterator(unsigned int value, unsigned int index) :
value_(value), index_(index)
{}

FactorialContainer::iterator& FactorialContainer::iterator::operator++()
{
  if (index_ < 11)
  {
    index_ ++;
    value_ *= index_;
  }

  return *this;
}

const FactorialContainer::iterator FactorialContainer::iterator::operator++(int)
{
  iterator old = *this;

  if(index_ < 11)
  {
    index_++;
    value_ *= index_;
  }

  return old;
}

FactorialContainer::iterator& FactorialContainer::iterator::operator--()
{
  if(index_ > 1)
  {
    value_ /= index_;
    index_--;
  }

  return *this;
}

const FactorialContainer::iterator FactorialContainer::iterator::operator--(int)
{
  iterator old = *this;

  if(index_ > 1)
  {
    value_ /= index_;
    index_--;
  }

  return old;
}

bool FactorialContainer::iterator::operator==(const iterator &other) const
{
  return (index_ == other.index_);
}

bool FactorialContainer::iterator::operator!=(const iterator &other) const
{
  return (index_ != other.index_);
}

const unsigned int& FactorialContainer::iterator::operator*() const
{
  return value_;
}

const unsigned int* FactorialContainer::iterator::operator->() const
{
  return &value_;
}

