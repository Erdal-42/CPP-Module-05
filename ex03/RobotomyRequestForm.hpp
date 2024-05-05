/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/08/02 10:26:55 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &);
		RobotomyRequestForm & operator=(RobotomyRequestForm const &); 
		std::string	getTarget( void ) const;
		void    	invokeFormExecution(void) const;
		static int const RobotomySignGrade = 72;
        static int const RobotomyExecGrade = 45;
};

#endif