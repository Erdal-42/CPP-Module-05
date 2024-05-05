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

/**
 * @brief Default constructor for Bureaucrat class.
 *
 * Constructs a Bureaucrat object with default values.
 */
Bureaucrat::Bureaucrat(void) : _name("Anonymous"), _grade(minGrade) 
{
#if DEBUG
    std::cout << "Default Construction: Bureaucrat " << *this << std::endl;
#endif
}

/**
 * @brief Parametized constructor for Bureaucrat class.
 * Constructs a Bureaucrat object with the given name and grade.
 *
 * @param theName The name of the bureaucrat.
 * @param theGrade The grade of the bureaucrat.
 */
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

/**
 * @brief Destructor for Bureaucrat class.
 * Destroys a Bureaucrat object.
 */
Bureaucrat::~Bureaucrat()
{
#if DEBUG
	std::cout << "Destruction: Bureaucrat. " << *this << std::endl;
#endif 
}

/**
 * @brief Copy constructor for Bureaucrat class.
 * Constructs a copy of the given Bureaucrat object.
 *
 * @param other The Bureaucrat object to copy.
 */
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
#if DEBUG
    std::cout << "Copy Constructing: " << *this << std::endl;
#endif
}

/**
 * @brief Assignment operator overload for Bureaucrat class.
 *
 * Assigns the values of another Bureaucrat object to this object.
 *
 * @param other The Bureaucrat object to assign.
 * @return Bureaucrat& Reference to the assigned Bureaucrat object.
 */
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

/**
 * @brief Increment the grade of the bureaucrat.
 * Increments the grade of the bureaucrat by 1.
 */
void Bureaucrat::incrementGrade(void)
{
    incrementGrade(1);
}

/**
 * @brief Increment the grade of the bureaucrat by a specified amount.
 * Increments the grade of the bureaucrat by the specified amount.
 *
 * @param n The amount to increment the grade by.
 */
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

/**
 * @brief Decrement the grade of the bureaucrat.
 * Decrements the grade of the bureaucrat by 1.
 */
void Bureaucrat::decrementGrade(void)
{
    decrementGrade(1);
}

/**
 * @brief Decrement the grade of the bureaucrat by a specified amount.
 * Decrements the grade of the bureaucrat by the specified amount.
 *
 * @param n The amount to decrement the grade by.
 */
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


/**
 * @brief Getter for the name of the bureaucrat.
 *
 * @return std::string The name of the bureaucrat.
 */
const std::string Bureaucrat::getName(void) const
{
    return  (_name);
}

/**
 * @brief Getter for the grade of the bureaucrat.
 *
 * @return int The grade of the bureaucrat.
 */
int Bureaucrat::getGrade(void) const
{
    return  (_grade);
}

/**
 * @brief Setter for the grade of the bureaucrat.
 * Sets the grade of the bureaucrat to the specified value.
 *
 * @param new_grade The new grade for the bureaucrat.
 */
void				Bureaucrat::setGrade( const int new_grade)
{
	this->_grade = new_grade;
	std::cout << "Bureaucrat " << this->_name << "'s grade was set to " << new_grade << std::endl;
}

/**
 * @brief Overloads the << operator for Bureaucrat objects.
 * 
 * @param os The output stream.
 * @param bureaucrat The Bureaucrat object to be output.
 * @return std::ostream& The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "Bureaucrat Name: " << bureaucrat.getName();
    os << ", Bureaucrat Grade: " << bureaucrat.getGrade();
    return os;
}

// ----------------------------------------------------------------------------



// ---------------------- BureaucratException Functions -----------------------

/**
 * @brief Returns the error message for GradeTooHighException.
 * 
 * @return const char* The error message.
 */
const char  *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "The grade is already at highest level. ";
} 

/**
 * @brief Returns the error message for GradeTooLowException.
 * 
 * @return const char* The error message.
 */
const char  *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "The grade is already at lowest level. ";
} 

// -------------------------------- EX01 ---------------------------------

/**
 * @brief Sign a form.
 * Signs the given form if the bureaucrat's grade is sufficient.
 *
 * @param form The form to sign.
 */
void    Bureaucrat::signForm(AForm &form)
{
    form.beSigned(*this);   //this is a bureaucrat
    if (form.getSigned())
        std::cout << *this << " signed " << form << std::endl;
    else
        std::cout << *this << "couldn't sign " << form << " because his grade is not authorized for signature." << std::endl; 
}

// -------------------------------- EX02 ---------------------------------

/**
 * @brief Execute a form.
 * Executes the given form if it has been signed and the executor's grade is sufficient.
 *
 * @param form The form to execute.
 */
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
