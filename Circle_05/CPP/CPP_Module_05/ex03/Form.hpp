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
		const std::string _target;
	
	public:
		Form(void);
		Form(const std::string name, int gradeRequiredSign, int gradeRequiredExecute);
		Form(const std::string name, int gradeRequiredSign, int gradeRequiredExecute, const std::string target);
		Form(Form const &copy);
		Form	&operator=(Form const &rhs);

		/* for ex02 */
		virtual ~Form(void);
		/* abstract */
		virtual void execute(Bureaucrat const & executor) = 0;

		const std::string &getName(void) const;
		const std::string &getTarget(void) const;
		bool	getIsSign(void) const;
		const int getGradeRequiredSign(void) const;
		const int getGradeRequiredExecute(void) const;

		void	beSigned(Bureaucrat	const &rhs);

		class	GradeTooHighException : public std::exception
		{
			private:
				const char *_message;

			public:
				GradeTooHighException(void);
				GradeTooHighException(const char *message);
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				const char *_message;

			public:
				GradeTooLowException(void);
				GradeTooLowException(const char *message);
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
