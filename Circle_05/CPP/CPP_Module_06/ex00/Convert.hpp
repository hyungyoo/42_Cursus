#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <cstring>
# include <iomanip>
# include <limits>
# include <cmath>

class Convert
{
	private:
		std::string _input;
		double	_num;

	public:
		Convert(void);
		Convert(std::string	input);
		~Convert(void);
		Convert	&operator=(Convert const &copy);
		Convert(Convert const &rhs);

		std::string	getInput(void) const;
		double	getNum(void) const;

		void	initialNum(void);

		void	setInput(std::string input);
		void	setNum(double num);

		char	convertToChar(void) const;
		int		convertToInt(void) const;
		float	convertToFloat(void) const;
		double	convertToDouble(void) const;

		void	printChar(std::ostream &o) const;
		void	printInt(std::ostream &o) const;
		void	printFloat(std::ostream &o) const;
		void	printDouble(std::ostream &o) const;

		class	ErrorMessage : public std::exception
		{
			private:
				const char *_errorMessage;
			public:
				ErrorMessage(void);
				ErrorMessage(const char *errorMessage);
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Convert const &rhs);

#endif
