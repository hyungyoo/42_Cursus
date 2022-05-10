#include <iostream>

 
template <class T>
void Swap(T &a, T &b)
{
	std::cout << "template" << std::endl;
     T t;
     t=a;a=b;b=t;
}

template<typename T = int>
void	a(T a)
{
	std::cout << a << std::endl;
}

template <> 
void Swap<double>(double &a, double &b)
{

	std::cout << "double" << std::endl;
     int i,j;
     i=(int)a;
     j=(int)b;
     a=a-i+j;
     b=b-j+i;

}

 

int main()
{

     double a=1.2,b=3.4;

	 int c= 2, d = 4;
     printf("before a=%g, b=%g\n",a,b);
     printf("before c=%d, d=%d\n",c,d);

     Swap(a,b);
     Swap(c,d);

     printf("after a=%g, b=%g\n",a,b);
     printf("after c=%d, d=%d\n",c,d);

}
