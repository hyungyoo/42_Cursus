#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool	_isSigned;
		const int	_gradeRequiredSign;
		const int 	_gradeRequiredExecute;
	
	public:
		Form(void);
		Form(const std::string name, int gradeRequiredSign, int gradeRequiredExecute);
		Form(Form const &copy);
		Form	&operator=(Form const &rhs);
		~Form(void);

		const std::string &getName(void) const;
		bool	getIsSign(void) const;
		const int getGradeRequiredSign(void) const;
		const int getGradeRequiredExecute(void) const;

		void	beSigned(Bureaucrat	const &rhs);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
