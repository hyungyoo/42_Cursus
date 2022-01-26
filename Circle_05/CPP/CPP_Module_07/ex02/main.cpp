#include <iostream>
#include "Array.hpp"

//#define MAX_VAL 750
#define MAX_VAL 10
int main(int, char**)
{
	std::cout << " test form intra 42" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
	std::cout << std::endl;
	std::cout << "=====copy=====" << std::endl;
   {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		std::cout << "numbers profil" << std::endl;
		for (int i = 0; i < numbers.size(); i++)
		{
			std::cout << numbers[i] << std::endl;
			i++;
		}
		std::cout << "tmp profil" << std::endl;
		for (int i = 0; i < tmp.size(); i++)
		{
			std::cout << tmp[i] << std::endl;
			i++;
		}
		std::cout << "test profil" << std::endl;
		for (int i = 0; i < test.size(); i++)
		{
			std::cout << test[i] << std::endl;
			i++;
		}
   }
	std::cout << "=====comparer=====" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {

        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	std::cout << "=====out of bound : 'number[-2] = 0'=====" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << "=====out of bound : 'number[MAX_VAL] = 0'=====" << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << "=====number[2] = 0' : =====" << std::endl;
    try
    {
        numbers[2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << "numbers[2] = " << numbers[2] << std::endl;
	std::cout << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	std::cout << " test form intra 42" << std::endl;

    return 0;
}

