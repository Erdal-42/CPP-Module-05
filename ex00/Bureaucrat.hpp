/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>    				+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:39:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/07/18 14:05:59 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <exception>

const bool COMMENT = true;

/**
 * @brief Represents a bureaucrat with a name and a grade.
 */
class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        // Constructors
        Bureaucrat(void);
        Bureaucrat(const std::string);
        Bureaucrat(const std::string, int);
        //Destructor
        ~Bureaucrat();
        //Copy Constructor
        Bureaucrat(const Bureaucrat &);
        //Copy assignment operator
        Bureaucrat &operator=(const Bureaucrat &);
        //Static Member Constants
        static const int minGrade = 150;
        static const int maxGrade = 1; 
        //Getters
        std::string getName(void) const;
        int         getGrade(void) const;
        //Miscellaneous 
        void        incrementGrade(void);
        void        incrementGrade(int);
        void        decrementGrade(void);
        void        decrementGrade(int);
        //Nested Classes
        class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char  *what(void) const throw(); 
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&); 

#endif