# Template 

```cpp

#include <iostream>

float	arraySum(const float arr[], int size)
{
	float	sum(0);
	int	i(0);
	while (i < size)
	{
		sum += arr[i];
		i++;
	}
	return (sum);
}

int	arraySum(const int arr[], int size)
{
	int	sum(0);
	int	i(0);
	while (i < size)
	{
		sum += arr[i];
		i++;
	}
	return (sum);
}

// 이렇게 각 타입마다 새롭게 함수를 오버로딩하는것보다는, 템플릿을 쓸수있다.
template <typename T>
T	arraySum(const T arr[], int size)
{
	T sum(0);
	int	i(0);
	while (i < size)
	{
		sum += arr[i];
		i++;
	}
	return (sum);
}

int	main(void)
{
	int	arr[5] = {1, 2, 3, 4, 5};
	int	sum = arraySum(arr, 5);
	
	float	farr[5] = {1.2, 2.3 3.4, 4.5, 5.6};
	float	fsum = arraySum(farr, 5);
	
	//	int	sum = arrSum<int>(arr, 5);
	//	float	sum = arrSum<float>(farr, 5);
	return (0);
}


```

```cpp

#include <algorithm>
#include <iostream>

int	main(void)
{
	int	MaxI = std::max<int>(1, 5);
	float	MaxF = std::max<float>(1, 5);
	double	MaxD = std::max<double>(1, 5);
	return (0);
}
```
## ex00

