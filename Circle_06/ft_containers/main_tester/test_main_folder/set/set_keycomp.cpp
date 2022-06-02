// set::key_comp
#include <iostream>
#include "../main.hpp"

int main ()
{
  set<int> myset;
  int highest;

  set<int>::key_compare mycomp = myset.key_comp();

  for (int i=0; i<=5; i++)
    myset.insert(i);

  std::cout << "myset contains:";

  highest=*myset.rbegin(); //5
  set<int>::iterator it=myset.begin();
  do {
    std::cout << ' ' << *it;
  } while ( mycomp(*(++it),highest) ); //return 

  std::cout << '\n';

  return 0;
}