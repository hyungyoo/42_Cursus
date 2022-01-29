#include "easyfind.hpp"

int	main(void)
{
	std::cout << "===============test for vector {1, 2, 3, 4, 5}================" << std::endl;
	{
		std::vector<int>	vector;
		vector.push_back(1);
		vector.push_back(2);
		vector.push_back(3);
		vector.push_back(4);
		vector.push_back(5);
		std::cout << "=====test for 1=====" << std::endl;
		try
		{
			std::vector<int>::iterator iter	= easyfind(vector, 1);
			std::cout << "found 1" << std::endl;
		}
		catch (std::exception	&e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "=====test for 6=====" << std::endl;
		try
		{
			std::vector<int>::iterator iter	= easyfind(vector, 6);
			std::cout << "found 6" << std::endl;
		}
		catch (std::exception	&e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "===============test for list {1, 2, 3, 4, 5}================" << std::endl;
	{
		std::list<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(4);
		list.push_back(5);
		std::cout << "=====test for 1=====" << std::endl;
		try
		{
			std::list<int>::iterator iter	= easyfind(list, 1);
			std::cout << "found 1" << std::endl;
		}
		catch (std::exception	&e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "=====test for 6=====" << std::endl;
		try
		{
			std::list<int>::iterator iter	= easyfind(list, 6);
			std::cout << "found 6" << std::endl;
		}
		catch (std::exception	&e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "===============test for deque {1, 2, 3, 4, 5}================" << std::endl;
	{
		std::deque<int> deque;
		deque.push_back(1);
		deque.push_back(2);
		deque.push_back(3);
		deque.push_back(4);
		deque.push_back(5);
		std::cout << "=====test for 1=====" << std::endl;
		try
		{
			std::deque<int>::iterator iter	= easyfind(deque, 1);
			std::cout << "found 1" << std::endl;
		}
		catch (std::exception	&e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "=====test for 6=====" << std::endl;
		try
		{
			std::deque<int>::iterator iter	= easyfind(deque, 6);
			std::cout << "found 6" << std::endl;
		}
		catch (std::exception	&e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << "===============test for set {1, 2, 3, 4, 5}================" << std::endl;
		std::set<int> set;
		set.insert(1);
		set.insert(2);
		set.insert(3);
		set.insert(4);
		set.insert(5);
		std::cout << "=====test for 1=====" << std::endl;
		try
		{
			std::set<int>::iterator iter	= easyfind(set, 1);
			std::cout << "found 1" << std::endl;
		}
		catch (std::exception	&e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "=====test for 6=====" << std::endl;
		try
		{
			std::set<int>::iterator iter	= easyfind(set, 6);
			std::cout << "found 6" << std::endl;
		}
		catch (std::exception	&e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
