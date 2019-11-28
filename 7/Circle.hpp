#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"
#include <iostream>

class Circle : public Shape
{
public:
  Circle(int setX, int setY);

  virtual void draw(std::ostream &stream) const;
};

#endif
