// set::count
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

  // set some initial values:
  for (int i=1; i<5; ++i)
    myset.insert(i*3);    // set: 3 6 9 12
print("myset = ", myset);
std::cout << std::endl;

  for (int i=0; i<10; ++i)
  {
    std::cout << i;
    if (myset.count(i)!=0) // if there's val i, it returns number of it, otherwise 0
    {
      std::cout << " is an element of myset.\n";
      std::cout << "number of " << i << " in myset: " << myset.count(i) << std::endl; 
    }
    else
      std::cout << " is not an element of myset.\n";
  }

  return 0;
}