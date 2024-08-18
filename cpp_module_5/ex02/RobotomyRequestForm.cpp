/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:42:36 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 06:10:03 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)  : AForm("RobotomyRequestForm", 72, 45), target(src.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &src)
{
    if (&src != this)
    {
        AForm::operator=(src);
        this->target = src.target;
    }
    return *this;
}
void RobotomyRequestForm::action() const
{
    std::srand(std::time(nullptr));
    int random_value = std::rand() % 2;

    std::cout << "grrrr rrrrr" << std::endl;
    if (random_value == 0)
        std::cout << "\033[32m" << this->target << " has been robotomized" << "\033[0m" << std::endl;
    else
        std::cout << "\033[31m" << this->target << " robotomized failed" << "\033[0m" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->target;
}