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


/**
 * @brief Default constructor for PresidentialPardonForm.
 * 
 * Constructs a PresidentialPardonForm with default values for sign and execute grades,
 * and sets the target to "Anonymous Target".
 */
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon Form", PresidentialSignGrade, PresidentialExecGrade), _target("Anonymous Target")
{
#if DEBUG
	std::cout << "Default Construction: Presidential Pardon Form. " << *this << std::endl;
#endif	
}

/**
 * @brief Parametized constructor for PresidentialPardonForm.
 * Constructs a PresidentialPardonForm with the specified target and default values for sign and execute grades.
 *
 * @param theTarget The target of the presidential pardon.
 */
PresidentialPardonForm::PresidentialPardonForm(std::string theTarget)
    : AForm("Presidential Pardon Form", PresidentialSignGrade, PresidentialExecGrade), _target(theTarget)
{
#if DEBUG
	std::cout << "Parametized Construction: Presidential Pardon Form. " << *this << std::endl;
#endif
}

/**
 * @brief Destructor for PresidentialPardonForm.
 * Destroys a PresidentialPardonForm object.
 */
PresidentialPardonForm::~PresidentialPardonForm()
{
#if DEBUG
	std::cout << "Destruction: Presidential Pardon Form. " << *this << std::endl;
#endif
}

/**
 * @brief Copy constructor for PresidentialPardonForm.
 * Constructs a copy of another PresidentialPardonForm object.
 *
 * @param other The PresidentialPardonForm object to copy.
 */
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
        : AForm(other), _target(other._target) 
{
#if DEBUG
	std::cout << "Copy Construction: Presidential Pardon Form. " << *this << std::endl;
#endif	
}

/**
 * @brief Assignment operator overload for PresidentialPardonForm.
 * Assigns the values of another PresidentialPardonForm object to this object.
 *
 * @param other The PresidentialPardonForm object to assign.
 * @return PresidentialPardonForm& Reference to the assigned object.
 */
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

/**
 * @brief Getter for the target of the presidential pardon.
 * 
 * @return std::string The target of the presidential pardon.
 */
std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (_target);
}

/**
 * @brief Executes the form, providing a presidential pardon.
 * Displays a message indicating that the target has been pardoned by Zaphod Beeblebrox.
 */
void PresidentialPardonForm::invokeFormExecution(void) const
{
    std::cout << "The " << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
