/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:42:36 by smarty            #+#    #+#             */
/*   Updated: 2024/04/20 23:07:16 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    
    std::cout << "RobotoMyRequest constructer called" << std::endl; 
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)  : AForm("RobotomyRequestForm", 72, 45), target(src.getTarget())
{
    std::cout << "RobotoMyRequest copy constructer called" << std::endl; 
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotoMyRequest destructor called" << std::endl; 
}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &src)
{
    this->target = src.target;
    this->name = src.name;
    this->sign = src.sign;
    return *this;
}
void RobotomyRequestForm::action() const
{
    std::srand(std::time(nullptr));
    int random_value = std::rand() % 100;

    std::cout << "grrrr rrrrr" << std::endl;
    if (random_value < 50)
        std::cout << this->target << " has been robotimezed" << std::endl;
    else
        std::cout << this->target << " robotimezed failed" << std::endl;

}

std::string RobotomyRequestForm::getTarget() const
{
    return this->target;
}