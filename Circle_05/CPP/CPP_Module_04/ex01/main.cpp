#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

void	setBrainIdeas(Cat &cat)
{
	int	i(0);

	while (i < NUM_IDEAS)
	{
		if (i % 2 == 0)
			cat.setIdeas(i, "blabla");
		else
			cat.setIdeas(i, "lol");
		i++;
	}
}

int	main(void)
{
	std::cout << "======================= constructor and destructor ===========================" << std::endl;
	std::cout << "=====Dog contructor=====" << std::endl;
	Animal *i = new Dog();
	std::cout << "=====Cat contructor=====" << std::endl;
	Animal *j = new Cat();
	std::cout << "=====Dog destructor=====" << std::endl;
	delete i;
	std::cout << "=====Cat destructor=====" << std::endl;
	delete j;
	std::cout << std::endl << std::endl;
	std::cout << "======================= deep copy and check address ===========================" << std::endl;
	std::cout << "=====Cat_1 constructor=====" << std::endl;
	Cat cat_1;
	// cat_1 set idea
	setBrainIdeas(cat_1);
	std::cout << "=====Cat_2 constructor=====" << std::endl;
	Cat cat_2;
	std::cout << "=====Cat_2 copy=====" << std::endl;
	cat_2 = cat_1;
	std::cout << "=====Cat_1 and Cat_2 has same idea=====" << std::endl;
	std::cout << "Cat_1 brain idea with index 0 is " << cat_1.getIdeas(0) << std::endl;
	std::cout << "Cat_2 brain idea with index 0 is " << cat_2.getIdeas(0) << std::endl;
	std::cout << "=====Cat_1 and Cat_2 has same idea but different address=====" << std::endl;
	std::cout << "Cat_1 brain idea with index 0 address is " << &(cat_1.getIdeas(0)) << std::endl;
	std::cout << "Cat_2 brain idea with index 0 address is " << &(cat_2.getIdeas(0)) << std::endl;
	std::cout << "=====Cat_3 copy 'Cat cat_3(cat_1);'=====" << std::endl;
	Cat cat_3(cat_1);
	std::cout << "=====Cat_1 and Cat_3 has same idea=====" << std::endl;
	std::cout << "Cat_1 brain idea with index 1 is " << cat_1.getIdeas(1) << std::endl;
	std::cout << "Cat_3 brain idea with index 1 is " << cat_3.getIdeas(1) << std::endl;
	std::cout << "=====Cat_1 and Cat_3 has same idea but different address=====" << std::endl;
	std::cout << "Cat_1 brain idea with index 1 address is " << &(cat_1.getIdeas(1)) << std::endl;
	std::cout << "Cat_3 brain idea with index 1 address is " << &(cat_3.getIdeas(1)) << std::endl;
	std::cout << "=====Cat destructor=====" << std::endl;
	return (0);
}
