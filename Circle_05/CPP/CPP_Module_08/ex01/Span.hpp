#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <exception>
# include <algorithm>
# include <iterator>
# include <numeric>
# include <cmath>

class Span
{
	private:
		std::vector<int>	_vector;
		int	_size;
	
	public:
		class	ErrorMessage : public std::exception
		{
			private:
				const char *_message;
			public:
				explicit ErrorMessage(void);
				explicit ErrorMessage(const char *message);
				virtual const char *what() const throw();
		};
		explicit Span(void);
		explicit Span(int size);
		Span(Span const &copy);
		Span	&operator=(Span const &rhs);
		~Span(void);

		const std::vector<int>	&getVector(void) const;

		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		
		void	addNumber(int value);
};

std::ostream	&operator<<(std::ostream &o, Span const &rhs);

#endif
