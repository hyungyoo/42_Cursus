#include <iostream>
#include "mutantstack.hpp"

int main()
{
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;

        mstack.pop();

        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << "-----------" << std::endl;
    {
        MutantStack<double> mstack;
        mstack.push(1.1);
        mstack.push(2.1);
        mstack.push(3.1);
        mstack.push(4.1);
        mstack.push(5.1);
        const MutantStack<double> cmstack(mstack);

        {
            MutantStack<double>::const_iterator it = cmstack.begin();
            MutantStack<double>::const_iterator ite = cmstack.end();

            while (it != ite)
            {
                std::cout << *it << std::endl;
                ++it;
            }
        }
        std::cout << "-----------" << std::endl;
        {
            MutantStack<double>::reverse_iterator it = mstack.rbegin();
            MutantStack<double>::reverse_iterator ite = mstack.rend();

            while (it != ite)
            {
                std::cout << *it << std::endl;
                ++it;
            }
        }
    }
}
