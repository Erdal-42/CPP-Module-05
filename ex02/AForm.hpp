/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/17 18:37:01 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include <unistd.h>
#include "Bureaucrat.hpp"

#define DEBUG_AForm 0

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	protected:
        virtual void    	invokeFormExecution() const = 0;

	public:
		// Constructors 
		AForm();
        // Destructor 
		virtual ~AForm();
		AForm(std::string, int, int);
		AForm(AForm const &);
        // '=' Overload
		AForm & operator=(AForm const &);

		// Getters
        std::string			getName() const;
        bool                getSigned() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;

		// Setters
		void				setSigned(const bool new_value);

		// Nested Exception classes:
		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
        class GradeTooHighException : public AForm::Exception 
        {
            public:
                virtual const char  *what(void) const throw(); 
        };
        class GradeTooLowException : public AForm::Exception
        {
            public:
                virtual const char *what(void) const throw();
        };
        class UnsignedFormException : public AForm::Exception
        {
            public:
                virtual const char *what(void) const throw();
        };
        class AlreadySignedException : public AForm::Exception
        {
            public:
                virtual const char *what(void) const throw();
        };

		// Miscellaneous Functions
		void	beSigned(Bureaucrat & ref);
        void	execute(Bureaucrat const & executor) const;
	};

// << overload
std::ostream & operator<<( std::ostream & o, AForm const & rhs);

#endif