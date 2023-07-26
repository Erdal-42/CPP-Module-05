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

int main()
{
    Bureaucrat  a, b;
    
    a = Bureaucrat("Koksal Toptan");
    std::cout << a;
    a.incrementGrade();
    std::cout << a;
    a.decrementGrade();
    std::cout << a;
    a.decrementGrade();
    std::cout << a;

    b = Bureaucrat("Ismail Cem", 2);
    std::cout << b;
    b.incrementGrade();
    std::cout << b;
    b.incrementGrade();
    std::cout << b;

    return 0;
}