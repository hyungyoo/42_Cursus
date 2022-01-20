#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat(void);
		Bureaucrat	&operator=(Bureaucrat const &rhs);
		
		const std::string getName(void) const;
		int	getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		class	GradeTooHighException : public std::exception
		{
			private:
				const char *_message;
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				const char *_message;
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
