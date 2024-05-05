#include "Form.hpp"

/**
 * @brief Default constructor for Form class. Initializes the name to "Default", signed status to false, and grade to the minimum grade.
 */
Form::Form() : _name("Default"), _signed(false), _signGrade(Bureaucrat::minGrade), _execGrade(Bureaucrat::minGrade)
{
    if (COMMENT2)
    {
        std::cout << "Default Constructor: <Form(void)>" << std::endl;
    }
}
    
/**
 * @brief Parameterized constructor for Form class. Initializes the name, sign grade, and execution grade.
 * 
 * @param theName The name of the form.
 * @param theSignGrade The grade required for signing the form.
 * @param theExecGrade The grade required for executing the form.
 */
Form::Form(const std::string theName, const int theSignGrade, const int theExecGrade) : 
            _name(theName), _signed(false), _signGrade(theSignGrade), _execGrade(theExecGrade)
{
    if (_signGrade < Bureaucrat::maxGrade || _execGrade < Bureaucrat ::maxGrade)
        throw (Form::GradeTooHighException());
    if (_signGrade > Bureaucrat::minGrade || _execGrade > Bureaucrat::minGrade)
        throw (Form::GradeTooLowException());
    if (COMMENT2)
    {
        std::cout << "Parametized Constructor: " << *this << std::endl;
    }
}

/**
 * @brief Destructor for Form class.
 */
Form::~Form()
{
    if (COMMENT2)
    {
        std::cout << "Form Destructor: " << getName() << std::endl;
    }
}

/**
 * @brief Copy constructor for Form class.
 * 
 * @param other The Form object to be copied.
 */
Form::Form(const Form &other) : _name(other._name), 
                                _signed(other._signed), 
                                _signGrade(other._signGrade), 
                                _execGrade(other._execGrade) 
{
    if (COMMENT2)
    {
        std::cout << "Copy Constructing " << *this << " using " << other << std::endl;
    }
}

/**
 * @brief Overload assignment operator for Form class.
 * 
 * @param other The Form object to be assigned.
 * @return Form& The reference to the assigned Form object.
 */
Form &Form::operator=(const Form &other)
{
    _signed = other._signed;
    return (*this);
}

/**
 * @brief Getter function for the name of the form.
 * 
 * @return const std::string The name of the form.
 */
const std::string Form::getName() const
{
    return  (_name); 
}

/**
 * @brief Getter function for the signed status of the form.
 * 
 * @return bool The signed status of the form.
 */
bool Form::getSigned() const
{
    return (_signed);
}

/**
 * @brief Getter function for the sign grade of the form.
 * 
 * @return int The sign grade of the form.
 */
int Form::getSignGrade() const
{
    return (_signGrade);
}

/**
 * @brief Getter function for the execution grade of the form.
 * 
 * @return int The execution grade of the form.
 */
int Form::getExecGrade() const
{
    return (_execGrade);
}

/**
 * @brief Returns the error message for GradeTooHighException.
 * 
 * @return const char* The error message.
 */
const char  *Form::GradeTooHighException::what(void) const throw()
{
    return "the grade is too high. ";
} 

/**
 * @brief Returns the error message for GradeTooLowException.
 * 
 * @return const char* The error message.
 */
const char  *Form::GradeTooLowException::what(void) const throw()
{
    return "the grade is too low. ";
}

/**
 * @brief Signs the form if it is not already signed.
 * 
 * @param bureaucrat The bureaucrat signing the form.
 */
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (_signed == true)
        return ;
    else if (bureaucrat.getGrade() <= getSignGrade())
    { 
        _signed = true;
        
    }
    else
        throw Form::GradeTooLowException();
}

/**
 * @brief Overloads the << operator for Form objects.
 * 
 * @param os The output stream.
 * @param form The Form object to be output.
 * @return std::ostream& The output stream.
 */
std::ostream &operator<<(std::ostream & os, const Form &form) 
{
    os << "Form Name: " << form.getName();
    os << ", Form Signed: " << form.getSigned();
    os << ", Signature Grade: " << form.getSignGrade();
    os << ", Execution Grade: " << form.getExecGrade();
    return os;
}
