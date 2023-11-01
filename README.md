
CPP Module 05 is a project where I have demonstrated my understanding and implementation of exceptions in C++. 

EXERCISE 00
In line with the project requirement, I represented a “Bureaucrat” with a certain rating of his authority level. Exceptions were used to catch invalid cases of his attributes.
MANDATORY RULES
Program Name : ex00
Submission Files : Bureaucrat.hpp, Bureaucrat.cpp, Main.cpp, Makefile
Parameters : -
Return Value : the output of a sample main function is displayed at the stdout.
A Bureaucrat must have:

• A constant name.

• And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade). Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception: either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException. Since grade 1 is the highest one and 150 the lowest, incrementing a grade 3 should give a grade 2 to the bureaucrat.   

EXERCISE 01
The objects of Bureaucrat classes  in Exercise 00 above will be signing instances of class Form coded in this exercise.
MANDATORY RULES
Program Name : ex01
Submission Files : Files from previous exercise + Form.{h, hpp}, Form.cpp
Parameters : -
Return Value : the output of a sample main function is displayed at the stdout.


Form class, has:
• A constant name.

• A boolean indicating whether it is signed (at construction, it’s not).

• A constant grade required to sign it.

• And a constant grade required to execute it.

All these attributes are private, not protected. The grades of the Form follow the same rules that apply to the Bureaucrat. Thus, the following exceptions will be thrown if a form grade is out of bounds: Form::GradeTooHighException and Form::GradeTooLowException.

EXERCISE 02
In this exercise I was required to transform the class Form into abstract and renamed it AForm.
Furthermore I had to generate 3 concrete classes following on from class AForm. They were;

• ShrubberyCreationForm: Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory, and writes ASCII trees
inside it.

• RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> has been robotomized successfully 50% of the time. Otherwise, informs that the robotomy failed.

• PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.

All of them take only one parameter in their constructor: the target of the form. For
example, "home" if you want to plant shrubbery at home.

MANDATORY RULES
Program Name : ex02
Submission Files : Makefile, main.cpp, Bureaucrat.[{h, hpp},cpp], Bureaucrat.cpp + AForm.[{h, hpp},cpp], ShrubberyCreationForm.[{h, hpp},cpp], + RobotomyRequestForm.[{h, hpp},cpp], PresidentialPardonForm.[{h, hpp},cpp]
Parameters : -
Return Value : the output of a sample main function is displayed at the stdout.

We are also required to write a member function in the abstract class AForm, execute(Bureaucrat const & executor) const that conducts the execution of a form. The function must check that the form was signed and that the grade of the bureaucrat attempting to execute the form is high enough. Otherwise, throw an appropriate exception.
Finally I added the  executeForm(Form const & form) member function to the Bureaucrat. It attempts to execute the form. I have included tests in the main function to prove that everything worked as expected.

EXERCISE 03
The purpose of this exercise was for me to implement an Intern class. The intern has no name, no grade, no unique characteristics. An object of the Intern Class is to fillout the form that is requested. For this I scripted the Intern Class member function makeForm() function that takes two strings; the first is the name of a form and the second is the target of the form. It return a pointer to a Form object (whose name is the one passed as parameter) whose target will be initialized to the second parameter. If the form name passed as parameter is non-existing, it prints an explicit error message.
MANDATORY RULES
Program Name : ex03
Submission Files : Files from previous exercises + Intern.{h, hpp}, Intern.cpp
Parameters : -
Return Value : the output of a sample main function
