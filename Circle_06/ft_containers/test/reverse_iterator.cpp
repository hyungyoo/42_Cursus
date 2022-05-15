#include <iostream>
#include "../inc/reverse_iterator.hpp"
#include "../inc/utils.hpp"
#include "../inc/iterator_traits.hpp"
#include <vector>
#include <iterator>

void	reverse_iterator(void)
{
	std::cout << "=====Constructor=====" << std::endl;;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
		iter_type from (myvector.begin());                     //   ^
		iter_type until (myvector.end());                      //                       ^
		std::reverse_iterator<iter_type> rev_until (from);     // ^
		std::reverse_iterator<iter_type> rev_from (until);     //                     ^
		std::cout << "stdRverse_iterator:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
                                                         // ? 0 1 2 3 4 5 6 7 8 9 ?
		iter_type from (myvector.begin());                     //   ^
                                                         //         ------>
		iter_type until (myvector.end());                      //                       ^
                                                         //
		ft::reverse_iterator<iter_type> rev_until (from);     // ^
                                                         //         <------
		ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

		 std::cout << "myReverse_iterator:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}
}

void	base(void)
{
	std::cout << "===== base =====" << std::endl;
	{
		  std::vector<int> myvector;
		 for (int i=0; i<10; i++) myvector.push_back(i);
	
		  typedef std::vector<int>::iterator iter_type;

		  std::reverse_iterator<iter_type> rev_end (myvector.begin());
		  std::reverse_iterator<iter_type> rev_begin (myvector.end());

		  std::cout << "std base:";
		for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
			std::cout << ' ' << *it;
		 std::cout << '\n';

	}
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_end (myvector.begin());
		ft::reverse_iterator<iter_type> rev_begin (myvector.end());

		std::cout << "ft base:";
		 for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

	}
}

void	printName(std::string const str)
{
	std::cout << "=====" << str << "=====" << std::endl;
}

void	operator_etoile(std::string const str)
{
	printName(str);
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) 
			myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
                                                         // ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     //   ^
                                                         //         ------>
		iter_type until (myvector.end());                      //                       ^
                                                         //
		std::reverse_iterator<iter_type> rev_until (from);     // ^
                                                         //         <------
		std::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "std_vector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		 std::cout << '\n';
	}

	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
                                                         // ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     //   ^
                                                         //         ------>
		iter_type until (myvector.end());                      //                       ^
                                                         //
		ft::reverse_iterator<iter_type> rev_until (from);     // ^
                                                         //         <------
		ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "ft_vector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		 std::cout << '\n';
	}
}

void	operator_plus(std::string str)
{
	printName(str);
	{
		std::vector<int> myvector;

		for (int i = 0;i < 10; i++)
			myvector.push_back(i);
		typedef std::vector<int>::iterator iter_type;
		std::reverse_iterator<iter_type> rev_it;
		rev_it = myvector.rbegin() + 3;
		std::cout << "std 4th element from the end is: " << *rev_it << std::endl;
	}
	{
		std::vector<int> myvector;

		for (int i = 0;i < 10; i++)
			myvector.push_back(i);
		typedef std::vector<int>::iterator iter_type;
		ft::reverse_iterator<iter_type> rev_it(myvector.end());
		rev_it += 3;
		std::cout << "ft 4th element from the end is: " << *rev_it << std::endl;
	}
}

void	test_reverse_iterator(void)
{
	std::cout << "========== reverse_iterator ==========" << std::endl;
	reverse_iterator();
	base();
	operator_etoile("operator *");
	operator_plus("opeator +");
}
