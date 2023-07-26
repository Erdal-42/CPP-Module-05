/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>    				+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:39:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/07/18 14:05:59 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _grade(minGrade) 
{
#if DEBUG
    std::cout << "Default Constructor: <Bureaucrat(void)>" << std::endl;
#endif
}

Bureaucrat::Bureaucrat(std::string theName, int theGrade) : _name(theName), _grade(theGrade)
{
#if DEBUG
    std::cout << "Constructor: <Bureaucrat(std::string theName, int theGrade)>" << std::endl;
#endif
}

//Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
#if DEBUG
    std::cout << "Copy Constructing " << this << " using " << &other << std::endl;
#endif
}

//Copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        _name = other._name;
        _grade = other._grade;
    }
#if DEBUG
    std::cout << "Copy Assigning" << std::endl;
#endif
    return (*this);
}

//Destructor
Bureaucrat::~Bureaucrat()
{
#if DEBUG
    std::cout << "Destructor: " << getName() << std::endl;
#endif   
}

// Non-member function to overload the << operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "Bureaucrat Name: " << bureaucrat.getName();
    os << ", Bureaucrat Grade: " << bureaucrat.getGrade() << std::endl;
    return os;
}

std::string Bureaucrat::getName(void) const
{
    return  (_name);
}

int Bureaucrat::getGrade(void) const
{
    return  (_grade);
}

void Bureaucrat::incrementGrade(void)
{
    incrementGrade(1);
}

void Bureaucrat::incrementGrade(int n)
{
#if DEBUG
    std::cout << "Incrementing Grade by " << n << std::endl;
#endif
    try
    {
        if (_grade - n < maxGrade)
            throw Bureaucrat::GradeTooHighException();
        _grade -= n;
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
    std::cout << "Decrementing Grade by " << n << std::endl;
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

void    Bureaucrat::signForm(Form form) const
{
    form.beSigned(this);   //this is a bureaucrat
    if (form.getSigned())
        std::cout << *this << " signed " << form << std::endl;
    else
        std::cout << *this << "couldn't sign " << form << " because his grade is not authorized for signature." << std::endl; 
}

const char  *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "The grade is already at highest level. ";
} 

const char  *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "The grade is already at lowest level. ";
} 
/*
int main()
{
    Bureaucrat  a, b;
    int i;
    
    a = Bureaucrat("Koksal Toptan");
    std::cout << a;
    a.incrementGrade();
    std::cout << a;
    a.decrementGrade();
    std::cout << a;
    a.decrementGrade();
    std::cout << a;

    b = a;
    std::cout << b;
    b.incrementGrade(140);
    std::cout << b;
    i = 0;
    while(i ++ < 11)
        b.incrementGrade();
    return 0;
}
*/