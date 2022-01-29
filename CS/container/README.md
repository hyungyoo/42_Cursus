# Vertor
> dynamic size array, sequence container

```cpp

int main(void)
{
	int	*numPtr = new int[5];
	for (int = 0;i < 5;i++)
	{
		numPtr[i] = i;
	}
	delete numPtr;

	std::vector<int> nums(5);
	std::vector<int> nums{0, 1, 2, 3, 4};
	
	// nums.size() ==> 5;
	// nums.emplace_back(5); // 마지막공간을 하나더만들어 5를 삽입
	// nums.size() ==> 6;
	// num.pop_back() // 마지막공간을 삭제
	// nums.size() ==> 5;

	

	for (int = 0;i < 5;i++)
	{
		nums[i] = i;
	}
	// delete가 필요없음.


	std::vector<Cat> cats;
	cats.emplace_back(Cat(1));
	cats.emplace_back(Cat(2));
	cats.emplace_back(Cat(3));
	cats.emplace_back(Cat(4));
	cats.emplace_back(Cat(5));
	...

	return (0);
}


```
