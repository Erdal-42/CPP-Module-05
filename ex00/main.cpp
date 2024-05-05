/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>    				+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:39:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/07/18 14:05:59 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/**
 * @brief Main function to test the Bureaucrat class.
 * 
 * @return int Exit status of the program.
 */
int main()
{   
    Bureaucrat a("Koksal Toptan");
    a.incrementGrade(); 
    a.decrementGrade();
    a.decrementGrade();
    std::cout << std::endl;

    Bureaucrat b("Ismail Cem", 2);
    b.incrementGrade();
    b.incrementGrade();
    std::cout << std::endl;

    try
    {
        Bureaucrat c = Bureaucrat("Necmi Eryılmaz", 160);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Bureaucrat d = b;
    return 0;
}