#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form
{
    private:
        std::string const   _name;
        bool                _signed;
        int const           _signGrade;
        int const           _execGrade;
    public:
    //Constructors
        Form();
        Form(std::string const, int const, int const);
    //Copy Constructor
        Form(Form const &);
    //Overload Assignment Operator
        Form &operator=(Form const &);
    //Destructor
        ~Form();
    //Getters
        std::string const   getName() const;
        bool                getSigned() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
    //Miscellaneous
        void                beSigned(Bureaucrat const&);
    //Nested Classes
        class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char  *what(void) const throw(); 
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };
};

//overloaded printer
std::ostream& operator<<(std::ostream &, const Form &);

#endif