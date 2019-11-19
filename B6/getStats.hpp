#ifndef INC_6_GETSTATS_HPP
#define INC_6_GETSTATS_HPP

#include "iostream"

class GetStats
{
public:
  GetStats();
  void operator()(int val);
  void printStats(std::ostream &out);

private:
  int max_{}, min_{}, positive_{}, negative_{}, first_{}, last_{}, numElements_{};
  long long oddSum_{}, evenSum_{};
};
#endif //INC_6_GETSTATS_HPP

