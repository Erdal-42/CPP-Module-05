/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/08/02 10:26:55 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

//Constructor
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", RobotomySignGrade, RobotomyExecGrade), _target("Anonymous")
{
#if DEBUG
	std::cout << "Default Construction: Robotomy Request Form. " << *this << std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(std::string theTarget)
    : AForm("Robotomy Request Form", RobotomySignGrade, RobotomyExecGrade), _target(theTarget)
{
#if DEBUG
	std::cout << "Parametized Construction: Robotomy Request Form. " << *this << std::endl;
#endif
}

RobotomyRequestForm::~RobotomyRequestForm()
{
#if DEBUG
	std::cout << "Destruction: Robotomy Request Form ." << *this << std::endl;
#endif	
}

//Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : AForm(other), _target(other._target)
{
#if DEBUG
	std::cout << "Copy Construction: Robotomy Request Form. " << *this << std::endl;
#endif	
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    if (this == &other)
        return (*this);
        
    AForm::operator=(other);
    _target = other._target;
#if DEBUG
	std::cout << "Assignment: Robotomy Request Form. " << *this << std::endl;
#endif
    return (*this);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

//Robotimization
void    RobotomyRequestForm::invokeFormExecution(void) const
{
    static int i = 0;

    std::cout << "VRRRH" << std::endl;
    if (++ i % 2)
    {
        std::cout << "The " << _target << " has been robotomized successfully." << std::endl;
    }
    else
        std::cout << "The robotomy failed." << std::endl;
}