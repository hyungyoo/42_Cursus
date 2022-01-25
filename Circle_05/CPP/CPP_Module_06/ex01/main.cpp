#include "Serialization.hpp"

int	main(void)
{
	Data	test_1("yoo", "hyungjun", 31);

	uintptr_t	ptrTest1 = serialize(&test_1);

	std::cout << "============profil test_1==============" << std::endl;
	std::cout << test_1;
	std::cout << "============uintptr of test_1==============" << std::endl;
	std::cout << ptrTest1 << std::endl;
	Data	*deserializeTest1 = deserialize(ptrTest1);
	std::cout << "============profil deserialization test_1==============" << std::endl;
	std::cout << *deserializeTest1;
	/*
	std::cout << std::endl;
	std::cout << "============copy test_1 to test_2==============" << std::endl;
	Data	test_2(test_1);
	uintptr_t	ptrTest2 = serialize(&test_2);
	std::cout << "============profil test_2==============" << std::endl;
	std::cout << test_2;
	std::cout << "============uintptr of test_2==============" << std::endl;
	std::cout << ptrTest2 << std::endl;
	Data	*deserializeTest2 = deserialize(ptrTest2);
	std::cout << "============profil deserialization test_2==============" << std::endl;
	std::cout << *deserializeTest2;
	*/
	return (0);
}
