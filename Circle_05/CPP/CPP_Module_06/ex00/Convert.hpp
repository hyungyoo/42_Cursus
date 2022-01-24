#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>

class Convert
{
	private:
		std::string _input;
		double	_num;
		bool	_isError;

	public:
		Convert(void);
		Convert(std::string	input);
		~Convert(void);
		Convert	&operator=(Convert const &copy);
		Convert(Convert const &rhs);

		bool	getError(void) const;
		std::string	getInput(void) const;
		double	getNum(void) const;

		void	setError(bool isError);
		void	setInput(std::string input);
		void	setNum(double num);

		char	ConvertToChar(void);
		int		ConvertToInt(void);
		float	ConvertToFloat(void);
		double	ConvertToDouble(void);

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
