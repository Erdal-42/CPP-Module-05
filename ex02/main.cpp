/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/17 18:37:42 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


/**
 * @brief Main function for the program.
 *
 * This function demonstrates the usage of the Bureaucrat and Form classes.
 * It constructs instances of Bureaucrat and various types of Form objects,
 * signs and executes the forms, and handles exceptions for unsigned forms
 * and insufficient grades.
 *
 * @return int Returns 0 upon successful completion of the program.
 */
int	main()
{
	std::cout << "\n-------CONSTRUCTING BUREAUCRATS-------" << std::endl;
	//Parametized Bureaucrat
	Bureaucrat b1("Bayram", 140);
	//Parametized Bureaucrat
	Bureaucrat b2("Bora", 5);

	std::cout << "\n-------CONSTRUCTING FORMS-------" << std::endl;
	PresidentialPardonForm	ppForm("Minister");
	RobotomyRequestForm 	rrForm("Vacuuming"); 
	ShrubberyCreationForm	sgForm("Street");
	std::cout << std::endl;

	std::cout << "\n=======SHRUBBERY FORM=======" << std::endl;
	std::cout << "\n-------EXECUTING AN UNSIGNED FORM-------" << std::endl;
	b1.executeForm(sgForm);

	std::cout << "-------EXECUTING A SIGNED SHRUBBERY FORM-------" << std::endl;
	std::cout << std::endl;
	sgForm.beSigned(b1);		
	std::cout << "[ATTEMPT TO EXECUTE SHRUBBERY FORM WITH INSUFFICIENT GRADE]" << std::endl;
	b1.executeForm(sgForm); 	
	std::cout << std::endl;
	std::cout << "[ATTEMPT TO EXECUTE SHRUBBERY FORM WITH SUFFICIENT GRADE]" << std::endl;
	b2.executeForm(sgForm);

	std::cout << std::endl << std::endl;
	std::cout << "=======ROBOTOMY REQUEST FORM=======" << std::endl;
	std::cout << "\n-------EXECUTING AN UNSIGNED ROBOTOMY REQUEST FORM-------" << std::endl;
	b2.executeForm(rrForm);
	rrForm.beSigned(b2);
	std::cout << std::endl;
	std::cout << "There is 50% chance of robotomy success. Lets See!" << std::endl;
	int i = 0;
	while (i ++ < 6)
	{
		std::cout << i << ". ";
		b2.executeForm(rrForm);
		std::cout << std::endl;
	}

	std::cout << std::endl; 
	std::cout << "[ATTEMPT TO EXECUTE ROBOTOMY REQUEST FORM WITH INSUFFICIENT GRADE]" << std::endl;
	b1.executeForm(rrForm);
	std::cout << std::endl;

	std::cout << "=======PRESIDENTIAL PARDON FORM=======" << std::endl;
	std::cout << "\n-------EXECUTING AN UNSIGNED PRESIDENTIAL PARDON FORM-------" << std::endl;
	b2.executeForm(ppForm);
	ppForm.beSigned(b2);
	std::cout << "\n-------EXECUTING A SIGNED PRESIDENTIAL PARDON FORM-------" << std::endl;
	b2.executeForm(ppForm);
	std::cout << std::endl;
	std::cout << "[ATTEMPT TO EXECUTE PRESIDENTIAL PARDON FORM WITH INSUFFICIENT GRADE]" << std::endl;
	b1.executeForm(ppForm);
	std::cout << "\n-------DESTRUCTORS-------" << std::endl;
}
