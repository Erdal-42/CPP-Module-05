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

/**
 * @brief Default constructor for Bureaucrat class. Initializes the grade to the minimum grade.
 */
Bureaucrat::Bureaucrat(void) : _grade(minGrade) 
{
    if (COMMENT)
        std::cout << "Default Constructor: <Bureaucrat(void)>" << std::endl;
}

/**
 * @brief Parameterized constructor for Bureaucrat class. Initializes the name and grade.
 * 
 * @param theName The name of the bureaucrat.
 */
Bureaucrat::Bureaucrat(const std::string theName) : _name(theName), _grade(minGrade)
{
    if (COMMENT)
    {
        std::cout << "Parametized Constructor: " << *this << std::endl;
    }
}

/**
 * @brief Parameterized constructor for Bureaucrat class. Initializes the name and grade.
 * 
 * @param theName The name of the bureaucrat.
 * @param theGrade The grade of the bureaucrat.
 */
Bureaucrat::Bureaucrat(const std::string theName, int theGrade) : _name(theName)
{
    if (theGrade > minGrade)
        throw GradeTooLowException();
    else
    {
        _grade = theGrade;
        if (COMMENT)
        {
            std::cout << "Parametized Constructor: " << *this << std::endl;
        }
    }
}

/**
 * @brief Destructor for Bureaucrat class.
 */
Bureaucrat::~Bureaucrat()
{
    if (COMMENT)
    {
        std::cout << "Bureaucrat Destructor: " << _name << std::endl;
    }
}

/**
 * @brief Copy constructor for Bureaucrat class.
 * 
 * @param other The Bureaucrat object to be copied.
 */
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
    if (COMMENT)
    {
        std::cout << "Copy Constructing " << *this << " using " << other << std::endl;
    }
}

/**
 * @brief Assignment operator overload for Bureaucrat class.
 * 
 * @param other The Bureaucrat object to be assigned.
 * @return Bureaucrat& The reference to the assigned Bureaucrat object.
 */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
    if (COMMENT)
    {
        std::cout << "Assigning " << other << " to \"" << this->_name << "\"" << std::endl;
    }
    return (*this);
}

/**
 * @brief Getter function for the name of the bureaucrat.
 * 
 * @return const std::string The name of the bureaucrat.
 */
const std::string Bureaucrat::getName(void) const
{
    return  (_name);
}

/**
 * @brief Getter function for the grade of the bureaucrat.
 * 
 * @return int The grade of the bureaucrat.
 */
int Bureaucrat::getGrade(void) const
{
    return  (_grade);
}

/**
 * @brief Increments the grade of the bureaucrat by 1.
 */
void Bureaucrat::incrementGrade(void)
{
    incrementGrade(1);
}

/**
 * @brief Increments the grade of the bureaucrat by a specified amount.
 * 
 * @param n The amount by which the grade should be incremented.
 */
void Bureaucrat::incrementGrade(int n)
{
    if (COMMENT)
    {
        std::cout << *this << " Incrementing Grade by " << n << std::endl;
    }
    try
    {
        if (_grade - n < maxGrade)
            throw Bureaucrat::GradeTooHighException();
        _grade -= n;
    }
    catch (GradeTooHighException &e)
    {
        std::cout << "GradeTooHighException caught. ";
        std::cout << e.what() << std::endl;
    }
}

/**
 * @brief Decrements the grade of the bureaucrat by 1.
 */
void Bureaucrat::decrementGrade(void)
{
    decrementGrade(1);
}

/**
 * @brief Decrements the grade of the bureaucrat by a specified amount.
 * 
 * @param n The amount by which the grade should be decremented.
 */
void Bureaucrat::decrementGrade(int n)
{
    if (COMMENT)
    {
        std::cout << *this << " Decrementing Grade by " << n << " for " << _name << std::endl;
    }
    try
    {
        if (_grade + n > minGrade)
            throw Bureaucrat::GradeTooLowException();
        _grade += n;
    }
    catch (GradeTooLowException &e)
    {
        std::cout << "GradeTooLowException caught. ";
        std::cout << e.what() << std::endl;
    }
}

/**
 * @brief Signs a form if it is not already signed.
 * 
 * @param form The form to be signed.
 */
void    Bureaucrat::signForm(Form &form) const
{
    if (!form.getSigned())
    {
        try
        {
            form.beSigned(*this);
            std::cout << *this << " signed " << form << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << *this << " couldn't sign " << form << " because ";
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        std::cout << *this << " couldn't sign " << form << " because ";
        std::cout << "this form has already been signed. " << std::endl;
    }
}

/**
 * @brief Returns the error message for GradeTooHighException.
 * 
 * @return const char* The error message.
 */
const char  *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "The grade is beyond the highest level 1. ";
} 

/**
 * @brief Returns the error message for GradeTooLowException.
 * 
 * @return const char* The error message.
 */
const char  *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "The grade is beyond the lowest level 150. ";
}

/**
 * @brief Overloads the << operator for Bureaucrat objects.
 * 
 * @param os The output stream.
 * @param bureaucrat The Bureaucrat object to be output.
 * @return std::ostream& The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) 
{
    os << "Bureaucrat: " << bureaucrat.getName() << ", Grade: ";
    if (bureaucrat.getGrade() <= 151 && bureaucrat.getGrade() >= 1) 
       os << bureaucrat.getGrade();
    return os;
}