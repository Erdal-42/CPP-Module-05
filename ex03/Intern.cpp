/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 01:01:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/08/05 01:01:55 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

AForm* Intern::_generatePresidentialPardonForm(std::string const& target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::_generateRobotomyRequestForm(std::string const& target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::_generateShrubberyCreationForm(std::string const& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm   *Intern::makeForm(const std::string name, std::string target)
{
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"}; 
    AForm* (Intern::*formConstructors[3])(std::string const& target) = 
    {
                &Intern::_generatePresidentialPardonForm, 
                &Intern::_generateRobotomyRequestForm, 
                &Intern::_generateShrubberyCreationForm
    };
    for(int i = 0; i < 3; i ++)
    {
        if (forms[i] == name)
        {
#if DEBUG_INTERN
    std::cout << "The intern has successfully filled in the "  << name << " form." << std::endl;
#endif
            return (this->*formConstructors[i]) (target);
        }
    }
    throw (Intern::UnrecognisableFormNameException());

    return (NULL);
}

const char *Intern::UnrecognisableFormNameException::what() const throw()
{
    return ("We cannot recognise the form type you entered.\n");
}
