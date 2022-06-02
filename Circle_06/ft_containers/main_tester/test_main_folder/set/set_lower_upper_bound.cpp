// set::lower_bound/upper_bound
#include <iostream>
#include "../main.hpp"

void print(std::string const comment, set<int> const& container)
{
    size_t size = container.size();
    std::cout << comment << "{ ";
	for (set<int>::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << (--size ? ", " : " ");
    std::cout << "}\n";
}

int main ()
{
  set<int> myset;
  set<int>::iterator itlow,itup;

  for (int i=1; i<10; i++)
    myset.insert(i*10); // 10 20 30 40 50 60 70 80 90
print("myset = ", myset);

std::cout << "itlow = myset.lower_bound(30)" << std::endl;
std::cout << "itup = myset.upper_bound(60)" << std::endl;
  itlow=myset.lower_bound (30);                //       ^
  itup=myset.upper_bound (60);                 //                   ^

std::cout << "myset.erase(itlow, itup)" << std::endl;
  myset.erase(itlow,itup);                     // 10 20 70 80 90

  std::cout << "myset contains:";
  for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}