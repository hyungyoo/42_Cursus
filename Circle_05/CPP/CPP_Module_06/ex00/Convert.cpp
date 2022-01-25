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
	//std::cout << "default constructor Convert" << std::endl;
}

Convert::Convert(const std::string input) : _input(input)	//initial with strtod
{
	// num initiala
	try
	{
		initialNum();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	std::cout << (*this);
	//std::cout << "Convert constructor with input" << std::endl;
}

Convert::~Convert(void)
{
	//std::cout << "Convert deconstructor" << std::endl;
}

Convert::Convert(Convert const &copy)
{
	(*this) = copy;
	//std::cout << "Convert copy constructor" << std::endl;
}

Convert	&Convert::operator=(Convert const &rhs)
{
	setInput(rhs.getInput());
	setNum(rhs.getNum());
	//std::cout << "Convert operator" << std::endl;
	return (*this);
}

void	Convert::initialNum(void)
{
	char	*ptr = NULL;
	setNum(std::strtod(_input.c_str(), &ptr));
	if (strcmp(ptr, ""))
	{
		if (strcmp(ptr, "f"))
			throw (Convert::ErrorMessage("Non displayable"));
	}
}

std::string Convert::getInput(void) const
{
	return (this->_input);
}

double	Convert::getNum(void) const
{
	return (this->_num);
}

void	Convert::setInput(std::string input)
{
	this->_input = input;
}

void	Convert::setNum(double num)
{
	this->_num = num;
}

char	Convert::convertToChar(void) const
{
	char	ret;
	ret = static_cast<char>(_num);
	if (std::isnan(this->getNum()) || std::isinf(this->getNum()))
		throw (Convert::ErrorMessage("impossible"));
	if (!(std::isprint(ret)) || (static_cast<int>(this->getNum()) != this->getNum()))
		throw (Convert::ErrorMessage());
	return (ret);
}

int		Convert::convertToInt(void) const
{
	int	ret;
	ret = static_cast<int>(_num);
	return (ret);
}

float	Convert::convertToFloat(void) const
{
	float	ret;
	ret = static_cast<float>(_num);
	return (ret);
}

double	Convert::convertToDouble(void) const
{
	double	ret;
	ret = static_cast<double>(_num);
	return (ret);
}

void	Convert::printFloat(std::ostream &o) const
{
	if (static_cast<int>(this->getNum()) == this->convertToFloat())
		o << "float: " << this->convertToFloat() << ".0f" << std::endl;
	else
		o << "Float: " << std::setprecision(std::numeric_limits<float>::digits10) << this->convertToFloat() << "f" << std::endl;
}

void	Convert::printDouble(std::ostream &o) const
{
	if (static_cast<int>(this->getNum()) == this->convertToDouble())
		o << "double: " << this->convertToDouble() << ".0" << std::endl;
	else
		o << "double: " << std::setprecision(std::numeric_limits<double>::digits10) << this->convertToDouble() << std::endl;
}

void	Convert::printInt(std::ostream &o) const
{
	if (std::isnan(this->getNum()) || std::isinf(this->getNum()))
		o << "int: impossible" << std::endl;
	else
		o << "int: " << this->convertToInt() << std::endl;
}

void	Convert::printChar(std::ostream &o) const
{
	if (std::isnan(this->getNum()) || std::isinf(this->getNum()))
		o << "impossible" << std::endl;
	o << "char: " << "'" << this->convertToChar() << "'" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Convert const &rhs)
{
	int	flag_char(0);
	try
	{
		rhs.convertToChar();
		// 어차피 뒤에서 NULL값이 들어오면, catch에서 what()으로 Non displayable이 
	}
	catch (const std::exception &e)
	{
		std::cerr << "char: ";
		std::cerr << e.what() << std::endl;
		flag_char = 1;
	}
	//o << "int: " << rhs.convertToInt() << std::endl;
	//o << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << rhs.convertToFloat() << "f" << std::endl;
	if (!flag_char)
		rhs.printChar(o);
	rhs.printInt(o);
	rhs.printFloat(o);
	rhs.printDouble(o);
	return (o);
}
