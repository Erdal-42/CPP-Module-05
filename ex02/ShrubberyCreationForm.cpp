/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/17 18:38:30 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/**
 * @brief Default constructor for ShrubberyCreationForm.
 *        Constructs a ShrubberyCreationForm with default values.
 */
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", ShrubberySignGrade, ShrubberyExecGrade), _target("Anonymous")
{
#if DEBUG
    std::cout << "Default Construction: Shrubbery Creation Form. " << *this << std::endl;
#endif
}

/**
 * @brief Parameterized constructor for ShrubberyCreationForm.
 *        Constructs a ShrubberyCreationForm with specified target.
 * @param theTarget The target for the shrubbery creation.
 */
ShrubberyCreationForm::ShrubberyCreationForm(std::string theTarget)
    : AForm("Shrubbery Creation Form", ShrubberySignGrade, ShrubberyExecGrade), _target(theTarget)
{
#if DEBUG
    std::cout << "Parametized Construction: Shrubbery Creation Form. " << *this << std::endl;
#endif
}

/**
 * @brief Destructor for ShrubberyCreationForm.
 *        Destructs a ShrubberyCreationForm instance.
 */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
#if DEBUG
    std::cout << "Destruction: Shrubbery Creation Form. " << *this << std::endl;
#endif
}

/**
 * @brief Copy constructor for ShrubberyCreationForm.
 *        Constructs a ShrubberyCreationForm by copying another ShrubberyCreationForm.
 * @param other The ShrubberyCreationForm to copy.
 */
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : AForm(other), _target(other._target)
{
#if DEBUG
    std::cout << "Copy Construction: Shrubbery Creation Form. " << *this << std::endl;
#endif
}

/**
 * @brief Assignment operator overload for ShrubberyCreationForm.
 *        Assigns the contents of another ShrubberyCreationForm to this one.
 * @param other The ShrubberyCreationForm to assign.
 * @return A reference to the assigned ShrubberyCreationForm.
 */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    if (this == &other)
        return (*this);

    AForm::operator=(other);
    _target = other._target;
#if DEBUG
    std::cout << "Assignment: Shrubbery Creation Form. " << *this << std::endl;
#endif
    return (*this);
}

/**
 * @brief Getter for the target of the shrubbery creation.
 * @return The target of the shrubbery creation.
 */
std::string ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

/**
 * @brief Executes the shrubbery creation request.
 *        Creates a file with a shrubbery ASCII art.
 */
void ShrubberyCreationForm::invokeFormExecution(void) const
{
    int fd;
    int i;

    fd = open((_target + "_shrubbery" + ".txt").c_str(), O_RDWR | O_CREAT | O_APPEND);
    i = 0;
    while (i < 26)
    {
        write(fd, "abcdefghijklmnopqrstuvwxyz", ++i);
        write(fd, "\n", 1);
    }
    i = 0;
    while (i < 10)
    {
        write(fd, &"123456789"[i++], 1);
        if (!(i % 3))
            write(fd, "\n", 1);
    }
    close(fd);
}
