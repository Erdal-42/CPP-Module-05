/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/17 21:02:21 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _signGrade(Bureaucrat::minGrade), _execGrade(Bureaucrat::minGrade)
{
#if DEBUG_AForm
    std::cout << "Default Construction: AForm " << *this << std::endl;
#endif
}

//Destructor
AForm::~AForm()
{
#if DEBUG_AForm
    std::cout << "Destruction:  AForm " << *this << std::endl;
#endif 
}

AForm::AForm(const std::string theName, int theSignGrade, int theExecGrade) : 
            _name(theName), _signed(false), _signGrade(theSignGrade), _execGrade(theExecGrade)
{
    if (_signGrade > Bureaucrat::minGrade || _execGrade > Bureaucrat::minGrade)
        throw (AForm::GradeTooLowException());
    if (_signGrade < Bureaucrat::maxGrade || _execGrade < Bureaucrat::maxGrade)
        throw (AForm::GradeTooHighException());

#if DEBUG_AForm
    std::cout << "Parametized Construction: AForm " << *this << std::endl;
#endif
}

//Copy Constructor
AForm::AForm(AForm const &other) : _name(other._name), 
                                _signed(other._signed), 
                                _signGrade(other._signGrade), 
                                _execGrade(other._execGrade) 
{
#if DEBUG_AForm
    std::cout << "Copy Constructing " << *this << std::endl;
#endif
}

//Overload Assignment Operator
AForm &AForm::operator=(AForm const &other)
{
    _signed = other._signed;
    return (*this);
}

// Getters
std::string	AForm::getName() const
{
    return  (_name); 
}

int         AForm::getSignGrade() const
{
    return (_signGrade);
}

int         AForm::getExecGrade() const
{
    return (_execGrade);
}

bool        AForm::getSigned() const
{
    return (_signed);
}

// Setters
void				AForm::setSigned(const bool new_value)
{
	std::cout << *this << " signed value was set to " << new_value << std::endl;
	this->_signed = new_value;
}

// Nested Exception classes:
const char  *AForm::Exception::what() const throw()
{
	return ("FormException");
}

const char  *AForm::GradeTooHighException::what(void) const throw()
{
    return ("The grade is too high. \n");
}

const char  *AForm::GradeTooLowException::what(void) const throw()
{
    return ("The grade is too low. \n");
}

const char *AForm::UnsignedFormException::what(void) const throw()
{
    return ("This form needs to be signed first. \n");
}

const char *AForm::AlreadySignedException::what(void) const throw()
{
    return ("This form was signed. \n");
}

std::ostream &operator<<(std::ostream & os, AForm const &form) 
{
    os << "Form Name: " << form.getName();
    os << ", Form Signed: " << form.getSigned();
    os << ", Signature Grade: " << form.getSignGrade();
    os << ", Execution Grade: " << form.getExecGrade();
    return os;
}

// Functions
void        AForm::beSigned(Bureaucrat &bureaucrat)
{
    int grade;

    grade = bureaucrat.getGrade();
    if (_signed == true)
        return ;
    else if (grade <= getSignGrade())
    {
        _signed = true;
    }
    else
    {
        throw (AForm::GradeTooLowException());
    }
}

void    AForm::execute(Bureaucrat const &executor) const
{
    if (_signed)
    {
        if (executor.getGrade() > _execGrade)
            throw AForm::GradeTooLowException(); 
        invokeFormExecution();
    }
    else
    {
        throw AForm::UnsignedFormException();
    }
}