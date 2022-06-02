// erasing from set
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
  set<int>::iterator it;

  // insert some values:
  for (int i=1; i<10; i++) 
    myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90
print("myset = ", myset);  

std::cout << "put myset.begin() on iterator and do ++it" << std::endl;

  it = myset.begin();
  ++it;                                         // "it" points now to 20

std::cout << "erase it" << std::endl;
  myset.erase (it);

std::cout << "erase '40'" << std::endl;
  myset.erase (40);

std::cout << "myset.find(60) and put it on iterator it and myset.erase(it, myset.end()" << std::endl;
  it = myset.find (60);
  myset.erase (it, myset.end());

  std::cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}