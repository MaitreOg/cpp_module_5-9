/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:18:37 by smarty            #+#    #+#             */
/*   Updated: 2024/04/19 23:55:04 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int rS, const int rE) : name(name), required_s(rS), required_e(rE)
{
    this->sign = 0;
    std::cout << "Form constructer called" << std::endl;
}

Form::Form(const Form &src) : name(src.getName()), required_e(src.getRequiredE()), required_s(src.getRequiredS()), sign(src.getSigned())
{
    std::cout << "Form copy constructer called" << std::endl;
}


Form::~Form(void)
{
    std::cout << "Form destructeur called" << std::endl;
}

bool Form::getSigned() const
{
    return  this->sign;
}
const std::string Form::getName() const
{
    return this->name;
}
const int    Form::getRequiredE() const
{
    return this->required_e;
}
const int    Form::getRequiredS() const
{
    return this->required_s;
}

void Form::BeSigned(Bureaucrat &B)
{
    try
    {
        if (this->required_e < B.getGrade())
            throw GradeTooLowException();
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
        return ;
    }
    this->sign = 1;
    B.signForm(this->name);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}
std::ostream &operator<<(std::ostream & os,Form &F)
{
    os << F.getName() << ", required for sign = " << F.getRequiredS()<< ", required for execute = " << F.getRequiredE() << ", signed = " << F.getSigned();
    return os;
}