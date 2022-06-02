// constructing stacks
#include <iostream>       // std::cout

#include "../main.hpp"

int main ()
{
  vector<int> myvector (2,200);        // vector with 2 elements

  stack<int> first;                    // empty stack

  stack<int,vector<int> > third;  // empty stack using vector
  stack<int,vector<int> > fourth (myvector);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}