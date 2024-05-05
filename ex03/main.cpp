/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 01:01:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/17 21:21:22 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm	*tester(Bureaucrat *b, AForm *form, std::string name, std::string target)
{
	Intern someRandomIntern;
	static int i = 1;
	
	std::cout << std::endl << "=======" << i ++ << ". TEST=======\n";
	std::cout << "Form Type: " << name << " \tTarget: " << target << std::endl;
	try
	{
		form = someRandomIntern.makeForm(name, target);
		b->signForm(*form);
		b->executeForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (form);	
}

int	main()
{
	Intern		someRandomIntern;
	AForm		*rrf = NULL;
	AForm		*ppf = NULL;
	AForm		*sgf = NULL;
	AForm		*x = NULL;
	Bureaucrat	*beau = new Bureaucrat("Statesman", 6);

	rrf = tester(beau, rrf, "robotomy request", "gate");
	ppf = tester(beau, sgf, "shrubbery creation", "park");
	sgf = tester(beau, ppf, "presidential pardon", "minister");
	x = tester(beau, x, "visa application", "tourist");

	std::cout << "--------------------" << std::endl;
	std::cout << "Testing is complete." << std::endl;
	delete beau;
		
	return (0);
}
