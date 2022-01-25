#include "Base.hpp"

Base::~Base(void)
{
}

A::~A(void)
{
}

B::~B(void)
{
}

C::~C(void)
{
}

Base	*generate(void)
{
	srand(time(NULL));
	int	randomNum(rand() % 3);
	//std::cout << "num = " << randomNum << std::endl;
	switch (randomNum)
	{
		case 0:
			std::cout << "new A()" << std::endl;
			return (new A());
		case 1:
			std::cout << "new B()" << std::endl;
			return (new B());
		case 2:
			std::cout << "new C()" << std::endl;
			return (new C());
		default:
			return (NULL);
	}
}

void	identify(Base* p)
{
	// dynamic_cast 는 실패시 NULL 반환
	if (dynamic_cast<A*>(p))
		std::cout << "A type [ptr]" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B type [ptr]" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C type [ptr]" << std::endl;
}

void	tryDynamic(Base &p, const std::string type)
{
	try
	{
		if (!(type.compare("A")))
			(void)dynamic_cast<A&>(p);
		else if (!(type.compare("B")))
			(void)dynamic_cast<B&>(p);
		else if (!(type.compare("C")))
			(void)dynamic_cast<C&>(p);
		std::cout << type << " type [ref]" << std::endl;
	}
	catch (const std::exception &e) {}
}

void	identify(Base& p)
{
	tryDynamic(p, "A");
	tryDynamic(p, "B");
	tryDynamic(p, "C");
}


