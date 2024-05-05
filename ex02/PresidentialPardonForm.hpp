/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/08/02 10:26:55 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &);
		PresidentialPardonForm & operator=(PresidentialPardonForm const &);
		std::string	getTarget( void ) const;
		void    invokeFormExecution(void) const;
		//Static Member Constants
        static int const PresidentialSignGrade = 25;
        static int const PresidentialExecGrade = 5; 
};

#endif