# Templated containers, iterators, algorithms

## array 와 vector의 차이
> array stack에 vetor는 heap에 연속된 공간이 할당된다. 즉, array는 compile에 stack frame에서 할당이되며, vetor는 run time에 할당된다.
이때, vetor는 stack에 24bytes(8bytes pointer, 8bytes size and 8bytes capacity)를 할당한후에, heap에 메모리할당 (flexible size)

### array
1. fast
2. complie
3. fixed size
4. limited to stackframe

### vector
1. heap
2. run time
3. flexible size
4. huge memory size
5. The complexity (efficiency) of common operations on vectors is as follows:
> Random access - constant 𝓞(1) 
	Insertion or removal of elements at the end - amortized constant 𝓞(1) 
Insertion or removal of elements - linear in the distance to the end of the vector 𝓞(n)


## deque
1. o(1)의 random access를 지원한다. Double ended queue
2. The complexity (efficiency) of common operations on deques is as follows:
> Random access - constant O(1)
	Insertion or removal of elements at the end or beginning - constant O(1)
Insertion or removal of elements - linear O(n)

## set
1. red-black structure
2. sorted
