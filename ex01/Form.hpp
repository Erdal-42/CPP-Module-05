#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

const bool COMMENT2 = true;

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _execGrade;
    public:
        //Constructors
        Form();
        Form(const std::string, const int, const int);
        //Destructor
        ~Form();
        //Copy Constructor
        Form(const Form &);
        //Overload Assignment Operator
        Form &operator=(const Form &);
        //Getters
        const std::string   getName() const;
        bool                getSigned() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
        //Miscellaneous
        void                beSigned(const Bureaucrat&);
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