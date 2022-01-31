#include "MutantStack.hpp"

int main()
{
	std::cout << "=============test <int>================" << std::endl;
	{
		MutantStack<int> mstack;
		std::cout << "mstack.push() 5, 17" << std::endl;
		mstack.push(5);
		mstack.push(17);
		std::cout << "mstack.top()" << std::endl;
		std::cout << mstack.top() << std::endl;
		std::cout << "mstack.pop()" << std::endl;
		mstack.pop();
		std::cout << mstack.top() << std::endl;
		std::cout << "mstack.size()" << std::endl;
		std::cout << mstack.size() << std::endl;
		std::cout << "mstack.push() 3, 4, 737, 0" << std::endl;
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
	std::cout << "=============test <char>================" << std::endl;
	{
		MutantStack<char> mstack;
		std::cout << "mstack.push() a, b" << std::endl;
		mstack.push('a');
		mstack.push('b');
		std::cout << "mstack.top()" << std::endl;
		std::cout << mstack.top() << std::endl;
		std::cout << "mstack.pop()" << std::endl;
		mstack.pop();
		std::cout << mstack.top() << std::endl;
		std::cout << "mstack.size()" << std::endl;
		std::cout << mstack.size() << std::endl;
		std::cout << "mstack.push() c, d, e, f" << std::endl;
		mstack.push('c');
		mstack.push('d');
		mstack.push('e');
		//[...]
		mstack.push('f');
		MutantStack<char>::iterator it = mstack.begin();
		MutantStack<char>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<char> s(mstack);
	}
	std::cout << "=============test <float>================" << std::endl;
	{
		MutantStack<float> mstack;
		std::cout << "mstack.push() 5.5, 17.17" << std::endl;
		mstack.push(5.5f);
		mstack.push(17.17f);
		std::cout << "mstack.top()" << std::endl;
		std::cout << mstack.top() << std::endl;
		std::cout << "mstack.pop()" << std::endl;
		mstack.pop();
		std::cout << mstack.top() << std::endl;
		std::cout << "mstack.size()" << std::endl;
		std::cout << mstack.size() << std::endl;
		std::cout << "mstack.push() 3.3, 4.4, 737.737, 0.0" << std::endl;
		mstack.push(3.3f);
		mstack.push(5.5f);
		mstack.push(737.737f);
		//[...]
		mstack.push(0.0f);
		MutantStack<float>::iterator it = mstack.begin();
		MutantStack<float>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<float> s(mstack);
	}
	std::cout << "=============test <string>================" << std::endl;
	{
		MutantStack<std::string> mstack;
		std::cout << "mstack.push() my, name" << std::endl;
		mstack.push("my");
		mstack.push("name");
		std::cout << "mstack.top()" << std::endl;
		std::cout << mstack.top() << std::endl;
		std::cout << "mstack.pop()" << std::endl;
		mstack.pop();
		std::cout << mstack.top() << std::endl;
		std::cout << "mstack.size()" << std::endl;
		std::cout << mstack.size() << std::endl;
		std::cout << "mstack.push() is, hyung, jun, yoo" << std::endl;
		mstack.push("is");
		mstack.push("hyung");
		mstack.push("jun");
		//[...]
		mstack.push("yoo");
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<std::string> s(mstack);
	}
	return 0;
}
