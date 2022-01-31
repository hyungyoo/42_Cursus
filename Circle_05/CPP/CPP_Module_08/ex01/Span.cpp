#include "Span.hpp"

Span::ErrorMessage::ErrorMessage(void) : _message("defalut error message")	{}

Span::ErrorMessage::ErrorMessage(const char *message) : _message(message) {}

const char 	*Span::ErrorMessage::what() const throw() { return (this->_message); }

Span::Span(void) : _size(0) { _vector.reserve(0); }	// capacity

Span::Span(int size) : _size(size) { _vector.reserve(size); }	// capacity

Span::~Span(void) {}

Span::Span(Span	const &copy)
{
	this->_size = copy._size;
	/* https://en.cppreference.com/w/cpp/algorithm/copy 
	std::vector<int> to_vector;
    std::copy(from_vector.begin(), from_vector.end(), std::back_inserter(to_vector)); 
	*/
	this->_vector.reserve((copy._vector).capacity());
	std::copy((copy._vector).begin(), (copy._vector).end(), std::back_inserter(this->_vector));
}

Span	&Span::operator=(Span const &rhs)
{
	if ((this->_size) < rhs._size)
		throw (Span::ErrorMessage("size error"));
	if ((this->_vector).empty())
		_vector.clear();
	_vector.reserve((rhs._vector).capacity());
	std::copy((rhs._vector).begin(), (rhs._vector).end(), std::back_inserter(this->_vector));
	return (*this);
}

void	Span::randomVector(void)
{
	/* https://en.cppreference.com/w/cpp/numeric/random/rand */
	std::srand(std::time(nullptr)); // use current time as seed for random generator
    // roll 6-sided dice 20 times
	int	limit = this->_vector.capacity() - this->_vector.size();
	for (int i = 0; i < limit; i++)
	{
		(this->_vector).push_back(std::rand() % 100);
	}
}

unsigned int Span::shortestSpan(void) const
{
	if (this->_size <= 1)
		throw (Span::ErrorMessage("size error for shortestSpan"));
	std::vector<int> vector_sort = this->_vector;
	sort(vector_sort.begin(), vector_sort.end());
	int	ret;
	for (std::vector<int>::const_iterator it = vector_sort.begin(); it != vector_sort.end(); it++)
	{
		if (it == vector_sort.begin())
			ret = abs(*it - *(it + 1));
		else if (*(it + 1) != *(vector_sort.end()))
		{
			//std::cout << "it = " << *it << std::endl;
			//std::cout << "it + 1= " << *(it + 1) << std::endl;
			if (ret > std::abs(*it - *(it + 1)))
				ret = std::abs(*it - *(it + 1));
			//std::cout << "ret == " << ret << std::endl;
		}
		else
			break ;
	}
	return (ret);
}

unsigned int Span::longestSpan(void) const
{
	/* https://en.cppreference.com/w/cpp/algorithm/max_element */
	if (this->_size <= 1)
		throw (Span::ErrorMessage("size error for longestSpan"));
	/* https://en.cppreference.com/w/cpp/algorithm/max_element */
    std::vector<int>::iterator max;
    std::vector<int>::iterator min;
	//std::cout << *std::max_element((this->_vector).begin(), (this->_vector).end()) << std::endl;
	//std::cout << *std::min_element((this->_vector).begin(), (this->_vector).end()) << std::endl;
	return ( *std::max_element((this->_vector).begin(), (this->_vector).end()) \
			- *std::min_element((this->_vector).begin(), (this->_vector).end()) );
}

void	Span::addNumber(int value)
{
	if ((this->_vector).capacity() <= (this->_vector).size())
		throw (Span::ErrorMessage("error add number, size is more than capacity"));
	(this->_vector).push_back(value);
}

const std::vector<int>	&Span::getVector(void) const
{
	return (this->_vector);
}

std::ostream	&operator<<(std::ostream &o, Span const &rhs)
{
	if (rhs.getVector().empty())
		return (o);
	o << "===== display Vector elements =====" << std::endl;
	for (std::vector<int>::const_iterator it = (rhs.getVector()).begin(); it != (rhs.getVector()).end(); it++)
	{
		o << *it << std::endl;
	}
	return (o);
}
