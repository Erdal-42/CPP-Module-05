/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/17 18:35:58 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

/**
 * @brief Default constructor for AForm class.
 *
 * Constructs an AForm object with default values.
 */
AForm::AForm() : _name("Default"), _signed(false), _signGrade(Bureaucrat::minGrade), _execGrade(Bureaucrat::minGrade)
{
#if DEBUG_AForm
    std::cout << "Default Construction: AForm " << *this << std::endl;
#endif
}

/**
 * @brief Destructor for AForm class.
 *
 * Destroys an AForm object.
 */
AForm::~AForm()
{
#if DEBUG_AForm
    std::cout << "Destruction:  AForm " << *this << std::endl;
#endif 
}

/**
 * @brief Parametized constructor for AForm class.
 *
 * Constructs an AForm object with the given parameters.
 *
 * @param theName The name of the form.
 * @param theSignGrade The grade required for signing the form.
 * @param theExecGrade The grade required for executing the form.
 */
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

/**
 * @brief Copy constructor for AForm class.
 * Constructs a copy of the given AForm object.
 *
 * @param other The AForm object to copy.
 */
AForm::AForm(AForm const &other) : _name(other._name), 
                                _signed(other._signed), 
                                _signGrade(other._signGrade), 
                                _execGrade(other._execGrade) 
{
#if DEBUG_AForm
    std::cout << "Copy Constructing " << *this << std::endl;
#endif
}

/**
 * @brief Assignment operator overload for AForm class.
 * Assigns the values of another AForm object to this object.
 *
 * @param other The AForm object to assign.
 * @return AForm& Reference to the assigned AForm object.
 */
AForm &AForm::operator=(AForm const &other)
{
    _signed = other._signed;
    return (*this);
}

/**
 * @brief Getter for the name of the form.

 * @return std::string The name of the form.
 */
std::string	AForm::getName() const
{
    return  (_name); 
}

/**
 * @brief Getter for the sign grade of the form.
 *
 * @return int The sign grade of the form.
 */
int         AForm::getSignGrade() const
{
    return (_signGrade);
}

/**
 * @brief Getter for the execution grade of the form.
 *
 * @return int The execution grade of the form.
 */
int         AForm::getExecGrade() const
{
    return (_execGrade);
}

/**
 * @brief Getter for the signed status of the form.
 *
 * @return bool The signed status of the form.
 */
bool        AForm::getSigned() const
{
    return (_signed);
}

/**
 * @brief Setter for the signed status of the form.
 *
 * @param new_value The new signed status of the form.
 */
void        AForm::setSigned(const bool new_value)
{
    std::cout << *this << " signed value was set to " << new_value << std::endl;
    this->_signed = new_value;
}

/**
 * @brief Exception class for AForm class.
 *
 * Provides a base class for exceptions related to AForm objects.
 */
const char  *AForm::Exception::what() const throw()
{
    return ("FormException");
}

/**
 * @brief Exception class for AForm class.
 *
 * Represents an exception for when the grade required for a form is too high.
 */
const char  *AForm::GradeTooHighException::what(void) const throw()
{
    return ("The grade is too high. \n");
}

/**
 * @brief Exception class for AForm class.
 *
 * Represents an exception for when the grade required for a form is too low.
 */
const char  *AForm::GradeTooLowException::what(void) const throw()
{
    return ("The grade is too low. \n");
}

/**
 * @brief Exception class for AForm class.
 * Represents an exception for when a form needs to be signed first.
 */
const char *AForm::UnsignedFormException::what(void) const throw()
{
    return ("This form needs to be signed first. \n");
}

/**
 * @brief Exception class for AForm class.
 * Represents an exception for when a form has already been signed.
 */
const char *AForm::AlreadySignedException::what(void) const throw()
{
    return ("This form was signed. \n");
}

/**
 * @brief Overloaded stream insertion operator for AForm class.
 *
 * Inserts the details of the form into the output stream.
 *
 * @param os The output stream.
 * @param form The AForm object to insert.
 * @return std::ostream& The output stream with the form details inserted.
 */
std::ostream &operator<<(std::ostream & os, AForm const &form) 
{
    os << "Form Name: " << form.getName();
    os << ", Form Signed: " << form.getSigned();
    os << ", Signature Grade: " << form.getSignGrade();
    os << ", Execution Grade: " << form.getExecGrade();
    return os;
}

/**
 * @brief Sign the form.
 *
 * Signs the form if the bureaucrat's grade is sufficient.
 *
 * @param bureaucrat The bureaucrat signing the form.
 */
void        AForm::beSigned(Bureaucrat &bureaucrat)
{
    int grade;

    grade = bureaucrat.getGrade();
    if (_signed == true)
        return ;
    else if (grade <= getSignGrade())
    {
        _signed = true;
        std::cout << "The bureaucrat " << bureaucrat.getName() << " has signed the form " << this->getName() << "." << std::endl;
    }
    else
    {
        throw (AForm::GradeTooLowException());
    }
}

/**
 * @brief Execute the form.
 *
 * Executes the form if it has been signed and the executor's grade is sufficient.
 *
 * @param executor The bureaucrat executing the form.
 */
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
