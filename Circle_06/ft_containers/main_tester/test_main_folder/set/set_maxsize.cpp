// set::max_size
#include <iostream>
#include "../main.hpp"

int main ()
{
  int i;
  set<int> myset;

    std::cout << "set max_size(): " << myset.max_size() << std::endl;

  if (myset.max_size()>1000)
  {
    for (i=0; i<1000; i++) myset.insert(i);
    std::cout << "The set contains 1000 elements.\n";
  }
  else std::cout << "The set could not hold 1000 elements.\n";

  return 0;
}