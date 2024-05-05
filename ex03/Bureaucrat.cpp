/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/17 18:25:53 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


// --------------------------- Bureaucrat Functions ----------------------------

Bureaucrat::Bureaucrat(void) : _name("Anonymous"), _grade(minGrade) 
{
#if DEBUG
    std::cout << "Default Construction: Bureaucrat " << *this << std::endl;
#endif
}

Bureaucrat::Bureaucrat(const std::string theName, int theGrade) : _name(theName), _grade(theGrade)
{

    if (theGrade > minGrade)
        throw Bureaucrat::GradeTooLowException();
    else if (theGrade < maxGrade)
        throw Bureaucrat::GradeTooHighException();
    _grade = theGrade;
#if DEBUG
    std::cout << "Parametized Construction: Bureaucrat " << *this << std::endl;
#endif
}

//Destructor
Bureaucrat::~Bureaucrat()
{
#if DEBUG
	std::cout << "Destruction: Bureaucrat. " << *this << std::endl;
#endif 
}

//Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
#if DEBUG
    std::cout << "Copy Constructing: " << *this << std::endl;
#endif
}

//Copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
#if DEBUG
    std::cout << "Assigning: " << *this << std::endl;
#endif
    return (*this);
}

void Bureaucrat::incrementGrade(void)
{
    incrementGrade(1);
}

void Bureaucrat::incrementGrade(int n)
{
    try
    {
        if (_grade - n < maxGrade)
            throw Bureaucrat::GradeTooHighException();
        _grade -= n;
#if DEBUG
    std::cout << "Incrementing Grade by " << n << ": " << *this << std::endl;
#endif
    }
    catch (GradeTooHighException &e)
    {
        std::cout << "GradeTooHighException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
}

void Bureaucrat::decrementGrade(void)
{
    decrementGrade(1);
}

void Bureaucrat::decrementGrade(int n)
{
#if DEBUG
    std::cout << "Decrementing Grade by " << n << ": " << *this << std::endl;
#endif
    try
    {
        if (_grade + n > minGrade)
            throw Bureaucrat::GradeTooLowException();
        _grade += n;
    }
    catch (GradeTooLowException &e)
    {
        std::cout << "GradeTooLowException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
}


// Getters
const std::string Bureaucrat::getName(void) const
{
    return  (_name);
}

int Bureaucrat::getGrade(void) const
{
    return  (_grade);
}

// Setters
void				Bureaucrat::setGrade( const int new_grade)
{
	this->_grade = new_grade;
	std::cout << "Bureaucrat " << this->_name << "'s grade was set to " << new_grade << std::endl;
}

// Non-member function to overload the << operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "Bureaucrat Name: " << bureaucrat.getName();
    os << ", Bureaucrat Grade: " << bureaucrat.getGrade();
    return os;
}

// ----------------------------------------------------------------------------



// ---------------------- BureaucratException Functions -----------------------

const char  *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "The grade is already at highest level. ";
} 

const char  *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "The grade is already at lowest level. ";
} 

// -------------------------------- EX01 ---------------------------------

void    Bureaucrat::signForm(AForm &form)
{
    form.beSigned(*this);   //this is a bureaucrat
    if (form.getSigned())
        std::cout << *this << " signed " << form << std::endl;
    else
        std::cout << *this << "couldn't sign " << form << " because his grade is not authorized for signature." << std::endl; 
}

// -------------------------------- EX02 ---------------------------------

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " successfully executed " << form;
    }
    catch (AForm::Exception &e)
    {
        std::cout << *this << " cannot execute the " << form << std::endl; 
        std::cout << e.what() << std::endl;
    }
}
