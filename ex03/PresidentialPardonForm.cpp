/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/17 18:37:59 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


//Constructor
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon Form", PresidentialSignGrade, PresidentialExecGrade), _target("Anonymous Target")
{
#if DEBUG
	std::cout << "Default Construction: Presidential Pardon Form. " << *this << std::endl;
#endif	
}

PresidentialPardonForm::PresidentialPardonForm(std::string theTarget)
    : AForm("Presidential Pardon Form", PresidentialSignGrade, PresidentialExecGrade), _target(theTarget)
{
#if DEBUG
	std::cout << "Parametized Construction: Presidential Pardon Form. " << *this << std::endl;
#endif
}

PresidentialPardonForm::~PresidentialPardonForm()
{
#if DEBUG
	std::cout << "Destruction: Presidential Pardon Form. " << *this << std::endl;
#endif
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
        : AForm(other), _target(other._target) 
{
#if DEBUG
	std::cout << "Copy Construction: Presidential Pardon Form. " << *this << std::endl;
#endif	
}

//Assignment Operator Overload
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & other) 
{
    if (this == &other)
        return *this; 
    AForm::operator=(other);
    _target = other._target;
#if DEBUG
	std::cout << "Assignment: Presidential Pardon Form. " << *this << std::endl;
#endif
    return *this;
}

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (_target);
}

void    PresidentialPardonForm::invokeFormExecution(void) const
{
    std::cout << "The " << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}