/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:43:06 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 05:44:56 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)  : AForm("PresidentialPardonForm", 25, 5), target(src.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
    if (&src != this)
    {
        AForm::operator=(src);
        this->target = src.target;
    }
    return *this;
}
void PresidentialPardonForm::action() const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl; 
}

std::string PresidentialPardonForm::getTarget() const
{
    return this->target;
}