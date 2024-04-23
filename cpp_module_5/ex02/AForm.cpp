/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:18:37 by smarty            #+#    #+#             */
/*   Updated: 2024/04/20 22:51:29 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, const int rS, const int rE) : name(name), required_s(rS), required_e(rE)
{
    this->sign = 0;
    std::cout << "AForm constructer called" << std::endl;
}

AForm::AForm(const AForm &src) : name(src.getName()), required_e(src.getRequiredE()), required_s(src.getRequiredS()), sign(src.getSigned())
{
    std::cout << "AForm copy constructer called" << std::endl;
}


AForm::~AForm(void)
{
    std::cout << "AForm destructeur called" << std::endl;
}

bool AForm::getSigned() const
{
    return  this->sign;
}
const std::string AForm::getName() const
{
    return this->name;
}
const int    AForm::getRequiredE() const
{
    return this->required_e;
}
const int    AForm::getRequiredS() const
{
    return this->required_s;
}

void AForm::BeSigned(Bureaucrat &B)
{
    try
    {
        if (this->required_s < B.getGrade())
            throw GradeTooLowException();
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
        return ;
    }
    if (this->sign == 0)
    {
        this->sign = 1;
        B.signForm(this->name);
    }
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char* AForm::NotSign::what() const throw()
{
    return "form is not signed";
}
std::ostream &operator<<(std::ostream & os, AForm &F)
{
    os << F.getName() << ", required for sign = " << F.getRequiredS()<< ", required for execute = " << F.getRequiredE() << ", signed = " << F.getSigned();
    return os;
}

void AForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (this->required_e < executor.getGrade())
            throw GradeTooLowException();
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
        return ;
    }

    try
    {
        if (this->required_e < executor.getGrade())
            throw NotSign();
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
        return ;
    }
    this->action();
    executor.executeForm(*this);
}
