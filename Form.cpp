#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _signGrade(Bureaucrat::minGrade), _execGrade(Bureaucrat::minGrade)
{
#if DEBUG
    std::cout << "Default Constructor: <Form(void)>" << std::endl;
#endif
}
    
Form::Form(std::string const theName, int const theSignGrade, int const theExecGrade) : 
            _name(theName), _signed(false), _signGrade(theSignGrade), _execGrade(theExecGrade)
{
    if (_signGrade < Bureaucrat::minGrade || _execGrade < Bureaucrat::minGrade)
        throw (Form::GradeTooLowException());
    if (_signGrade > Bureaucrat::maxGrade || _execGrade > Bureaucrat::maxGrade)
        throw (Form::GradeTooHighException());

#if DEBUG
    std::cout << "Constructor: <Form(std::string const _name, int const _signGrade, int const _execGrade))>" << std::endl;
#endif
}
    
//Copy Constructor
Form::Form(Form const &other) : _name(other._name), 
                                _signed(other._signed), 
                                _signGrade(other._signGrade), 
                                _execGrade(other._execGrade) 
{
#if DEBUG
    std::cout << "Copy Constructing " << *this << " using " << other << std::endl;
#endif
}

//Overload Assignment Operator
Form &Form::operator=(Form const &other)
{
    _signed = other._signed;
    return (*this);
}
   
//Destructor
Form::~Form()
{
#if DEBUG
    std::cout << "Form Destructor: " << getName() << std::endl;
#endif 
}

//Getters
std::string const Form::getName() const
{
    return  (_name); 
}

bool        Form::getSigned() const
{
    return (_signed);
}

int         Form::getSignGrade() const
{
    return (_signGrade);
}

int         Form::getExecGrade() const
{
    return (_execGrade);
}

const char  *Form::GradeTooHighException::what(void) const throw()
{
    return "The grade is already at highest level. ";
} 

const char  *Form::GradeTooLowException::what(void) const throw()
{
    return "The grade is already at lowest level. ";
}

void        Form::beSigned(Bureaucrat const &bureaucrat)
{
    int grade;

    grade = bureaucrat.getGrade();
    if (_signed == true)
        ;
    else if (grade <= getSignGrade())
        _signed = true;
    else
    {
        throw Form::GradeTooLowException();
    }
}

// Non-member function to overload the << operator
std::ostream &operator<<(std::ostream & os, Form const &form) 
{
    os << "Form Name: " << form.getName();
    os << ", Formed Signed: " << form.getSigned();
    os << ", Signature Grade: " << form.getSignGrade();
    os << ", Execution Grade: " << form.getExecGrade() << std::endl;
    return os;
}

int main()
{
    Form  a, b;
    
    a = Form("Visa", 100, 50);
    std::cout << a;

    b = Form("Passport", 100, 50);
    std::cout << b;

    return 0;
}