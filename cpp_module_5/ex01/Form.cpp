/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:18:37 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 05:04:40 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int rS, const int rE) : name(name), required_s(rS), required_e(rE)
{
    this->sign = 0;
}

Form::Form(const Form &src) : name(src.name), required_s(src.required_s), required_e(src.required_e), sign(src.sign)
{
}

Form &Form::operator=(const Form &src)
{
    if (&src != this)
    {
        this->setName(src.getName());
        this->setSigned(src.getSigned());
        this->setRequiredE(src.getRequiredE());
        this->setRequiredS(src.getRequiredS());

    }
    return (*this);
}

std::ostream &operator<<(std::ostream & os,Form &F)
{
    os << F.getName() << ", required for sign = " << F.getRequiredS()<< ", required for execute = " << F.getRequiredE() << ", signed = " << F.getSigned();
    return os;
}

Form::~Form(void)
{
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

void Form::setSigned(const bool sign)
{
    this->sign = sign;
}
void Form::setName(const std::string name)
{
    const_cast<std::string&>(this->name) = name;
}
void Form::setRequiredE(const int e)
{
    if (e < 1)
        throw (Form::GradeTooHighException());
    else if (e > 150)
        throw (Form::GradeTooLowException());
    const_cast<int&>(this->required_e) = e;
}
void Form::setRequiredS(const int s)
{
    if (s < 1)
        throw (Form::GradeTooHighException());
    else if (s > 150)
        throw (Form::GradeTooLowException());
    const_cast<int&>(this->required_s) = s;
}

void Form::BeSigned(Bureaucrat &B)
{
    if (this->required_s < B.getGrade())
        throw (Form::GradeTooLowException());
    if (this->sign == 1)
        throw (Form::isAlreadySigned());
    this->sign = 1;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}
const char* Form::isAlreadySigned::what() const throw()
{
    return "Is already signed.";
}