/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>    				+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:39:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/07/18 14:05:59 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/**
 * @brief Default constructor for Bureaucrat class.
 */
Bureaucrat::Bureaucrat(void) : _grade(minGrade) 
{
    if (COMMENT)
        std::cout << "Default Constructor: <Bureaucrat(void)>" << std::endl;
}

/**
 * @brief Parameterized constructor for Bureaucrat class.
 * 
 * @param theName The name of the bureaucrat.
 */
Bureaucrat::Bureaucrat(const std::string theName) : _name(theName), _grade(minGrade)
{
    if (COMMENT)
    {
        std::cout << "Parametized Constructor: <Bureaucrat(std::string theName)> for " << theName << std::endl;
    }
}

/**
 * @brief Parameterized constructor for Bureaucrat class.
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
        std::cout << "Destructor: " << _name << std::endl;
    }
}

/**
 * @brief Copy constructor for Bureaucrat class.
 * 
 * @param other The bureaucrat object to copy.
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
 * @param other The bureaucrat object to assign.
 * @return Bureaucrat& Reference to the assigned object.
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
 * @brief Get the name of the bureaucrat.
 * 
 * @return std::string The name of the bureaucrat.
 */
std::string Bureaucrat::getName(void) const
{
    return  (_name);
}

/**
 * @brief Get the grade of the bureaucrat.
 * 
 * @return int The grade of the bureaucrat.
 */
int Bureaucrat::getGrade(void) const
{
    return  (_grade);
}

void Bureaucrat::incrementGrade(void)
{
    incrementGrade(1);
}

/**
 * @brief Increment the grade of the bureaucrat by a specified amount.
 * 
 * @param n The amount to increment the grade by.
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
 * @brief Decrement the grade of the bureaucrat by 1.
 */
void Bureaucrat::decrementGrade(void)
{
    decrementGrade(1);
}

/**
 * @brief Decrement the grade of the bureaucrat by a specified amount.
 * 
 * @param n The amount to decrement the grade by.
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
 * @brief Get the exception message for a grade too high exception.
 * 
 * @return const char* The exception message.
 */
const char  *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "The grade is beyond highest level. ";
} 

/**
 * @brief Get the exception message for a grade too low exception.
 * 
 * @return const char* The exception message.
 */
const char  *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "The grade is beyond lowest level. ";
} 

/**
 * @brief Overload the stream insertion operator to print a bureaucrat object.
 * 
 * @param os The output stream.
 * @param bureaucrat The bureaucrat object to print.
 * @return std::ostream& The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) 
{
    os << "Bureaucrat: " << bureaucrat.getName() << ", Grade: " 
       << bureaucrat.getGrade();
    return os;
}