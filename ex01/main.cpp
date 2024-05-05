/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>    				+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:39:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/07/18 14:05:59 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/**
 * @brief Main function demonstrating the use of Bureaucrat and Form classes.
 *
 * This function creates instances of Bureaucrat and Form objects and demonstrates 
 * their interactions, including construction, signing, and destruction.
 * 
 * @return int Returns 0 on successful completion.
 */
int	main()
{
	std::cout << "\n=======CONSTRUCTING BUREAUCRATS=======" << std::endl;
	//Default Bureaucrat
	Bureaucrat b1("Border Force", 140);
	
	//Parametized Bureaucrat
	Bureaucrat b2("Konsolate General", 5);

	std::cout << "\n=======CONSTRUCTING FORMS=======" << std::endl;
	Form    f1("Visa Application", 145, 148);
	Form    f2("Passport Application", 10, 50); 

	std::cout << "\n-------PASSPORT APPLICATION FORM-------" << std::endl;
	std::cout << "[ATTEMPT TO SIGN FORM WITH INSUFFICIENT GRADE]" << std::endl;
	try
    {
        f2.beSigned(b1);
    } catch (std::exception &e)
    {
        std::cout << f2 << " " << b1 << std::endl;
        std::cout << e.what() << std::endl;
    }

	std::cout << "\n=======SIGNING FORM=======" << std::endl;
    std::cout << "\n-------PASSPORT APPLICATION FORM-------" << std::endl;
    b2.signForm(f2);

    std::cout << "\n-------VISA APPLICATION FORM-------" << std::endl;
    b1.signForm(f1);
    b2.signForm(f1);		

	std::cout << "\n=======DESTRUCTORS=======" << std::endl;

    return (0);
}