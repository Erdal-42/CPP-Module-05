/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/17 18:37:32 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

#define DEBUG   1

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		
	public:
		// Constructors 
		Bureaucrat();
		Bureaucrat(const std::string, int);
		// Destructor 
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &);
		// '=' Overload
		Bureaucrat &operator=(const Bureaucrat &);

        static int const minGrade = 150;
        static int const maxGrade = 1; 

		// Increment / Decrement grade
        void        		incrementGrade(void);
        void        		incrementGrade(int);
		void        		decrementGrade(void);
        void        		decrementGrade(int);

		// Getters
        const std::string 	getName(void) const;
        int         		getGrade(void) const;

		// Setters
		void				setGrade( const int new_grade);

		// Nested Exception classes:
        class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char  *what(void) const throw(); 
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };

		// ex01
		void signForm(AForm &);

		// ex02
		void executeForm(AForm const &);
};

// << Overload
std::ostream& operator<<(std::ostream &, const Bureaucrat &);


#endif