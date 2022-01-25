#include "Convert.hpp"

Convert::ErrorMessage::ErrorMessage(void) : _errorMessage("Non displayable")
{
}

Convert::ErrorMessage::ErrorMessage(const char *errorMessage) : _errorMessage(errorMessage)
{
}

const char *Convert::ErrorMessage::what() const throw()
{
	return (this->_errorMessage);
}

Convert::Convert(void)
{
	std::cout << "default constructor Convert" << std::endl;
}

Convert::Convert(const std::string input) : 
_input(input),
_num(0.0),	//initial with strtod
_isError(false)	//intial after check input
{
	// num initial
	std::cout << "Convert constructor with input" << std::endl;
}

Convert::~Convert(void)
{
	std::cout << "Convert deconstructor" << std::endl;
}

Convert::Convert(Convert const &copy)
{
	(*this) = copy;
	std::cout << "Convert copy constructor" << std::endl;
}

Convert	&Convert::operator=(Convert const &rhs)
{
	setInput(rhs.getInput());
	setNum(rhs.getNum());
	setError(rhs.getError());
	std::cout << "Convert operator" << std::endl;
	return (*this);
}

bool	Convert::getError(void) const
{
	return (this->_isError);
}

std::string Convert::getInput(void) const
{
	return (this->_input);
}

double	Convert::getNum(void) const
{
	return (this->_num);
}

void	Convert::setError(bool isError)
{
	this->_num = isError;
}

void	Convert::setInput(std::string input)
{
	this->_input = input;
}

void	Convert::setNum(double num)
{
	this->_num = num;
}

char	Convert::ConvertToChar(void)
{
	char	ret;
	ret = static_cast<char>(_num);
	std::cout << "is num == " <<  std::isprint(ret) << std::endl;
	if (std::isprint(ret))
	{
		std::cout << "char == " << ret << std::endl;
	}
	else
		throw (Convert::ErrorMessage());
	return (ret);
}

int		Convert::ConvertToInt(void)
{
	int	ret;
	ret = static_cast<int>(_num);
	return (ret);
}

float	Convert::ConvertToFloat(void)
{
	float	ret;
	ret = static_cast<float>(_num);
	return (ret);
}

double	Convert::ConvertToDouble(void)
{
	double	ret;
	ret = static_cast<double>(_num);
	return (ret);
}

std::ostream	&operator<<(std::ostream &o, Convert const &rhs)
{
	o << "here" << std::endl;
	return (o);
}
