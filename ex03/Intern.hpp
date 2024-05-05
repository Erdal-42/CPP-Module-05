/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 01:01:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/08/05 01:01:55 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define DEBUG_INTERN    1 

class Intern
{
    private:
    private:
        AForm* _generatePresidentialPardonForm(std::string const& target);
        AForm* _generateRobotomyRequestForm(std::string const& target);
        AForm* _generateShrubberyCreationForm(std::string const& target);
    public:
        //Constructors 
        Intern();
        // Destructors
        ~Intern();
        //Find and fill in the form  
        AForm *makeForm(const std::string, std::string);
        class UnrecognisableFormNameException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};