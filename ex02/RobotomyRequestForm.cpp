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

/**
 * @brief Default constructor for RobotomyRequestForm.
 *        Constructs a RobotomyRequestForm with default values.
 */
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", RobotomySignGrade, RobotomyExecGrade), _target("Anonymous")
{
#if DEBUG
    std::cout << "Default Construction: Robotomy Request Form. " << *this << std::endl;
#endif
}

/**
 * @brief Parameterized constructor for RobotomyRequestForm.
 *        Constructs a RobotomyRequestForm with specified target.
 * @param theTarget The target for the robotomy request.
 */
RobotomyRequestForm::RobotomyRequestForm(std::string theTarget)
    : AForm("Robotomy Request Form", RobotomySignGrade, RobotomyExecGrade), _target(theTarget)
{
#if DEBUG
    std::cout << "Parametized Construction: Robotomy Request Form. " << *this << std::endl;
#endif
}

/**
 * @brief Destructor for RobotomyRequestForm.
 *        Destructs a RobotomyRequestForm instance.
 */
RobotomyRequestForm::~RobotomyRequestForm()
{
#if DEBUG
    std::cout << "Destruction: Robotomy Request Form ." << *this << std::endl;
#endif
}

/**
 * @brief Copy constructor for RobotomyRequestForm.
 *        Constructs a RobotomyRequestForm by copying another RobotomyRequestForm.
 * @param other The RobotomyRequestForm to copy.
 */
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : AForm(other), _target(other._target)
{
#if DEBUG
    std::cout << "Copy Construction: Robotomy Request Form. " << *this << std::endl;
#endif
}

/**
 * @brief Assignment operator overload for RobotomyRequestForm.
 *        Assigns the contents of another RobotomyRequestForm to this one.
 * @param other The RobotomyRequestForm to assign.
 * @return A reference to the assigned RobotomyRequestForm.
 */
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

/**
 * @brief Getter for the target of the robotomy request.
 * @return The target of the robotomy request.
 */
std::string RobotomyRequestForm::getTarget(void) const
{
    return (_target);
}

/**
 * @brief Executes the robotomy request.
 *        Simulates a robotomy attempt with a 50% success rate.
 */
void RobotomyRequestForm::invokeFormExecution(void) const
{
    static int i = 0;

    std::cout << "VRRRH" << std::endl;
    if (++i % 2)
    {
        std::cout << "The " << _target << " has been robotomized successfully." << std::endl;
    }
    else
        std::cout << "The robotomy failed." << std::endl;
}
