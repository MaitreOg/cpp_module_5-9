/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:43:06 by smarty            #+#    #+#             */
/*   Updated: 2024/04/20 23:06:40 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    
    std::cout << "PresidentialPardon constructer called" << std::endl; 
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)  : AForm("PresidentialPardonForm", 25, 5), target(src.getTarget())
{
    std::cout << "PresidentialPardon copy constructer called" << std::endl; 
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardon destructor called" << std::endl; 
}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
    this->target = src.target;
    this->name = src.name;
    this->sign = src.sign;
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