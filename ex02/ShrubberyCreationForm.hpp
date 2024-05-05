/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/08/02 10:26:55 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fcntl.h>

class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &);
		std::string	getTarget() const;
		void    	invokeFormExecution(void) const;
		static int const ShrubberySignGrade = 145;
        static int const ShrubberyExecGrade = 137;
};

#endif