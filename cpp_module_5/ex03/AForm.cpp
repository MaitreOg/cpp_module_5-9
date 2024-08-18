/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:18:37 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 05:11:59 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, const int rS, const int rE) : name(name), required_s(rS), required_e(rE)
{
    this->sign = 0;
}

AForm::AForm(const AForm &src) : name(src.name), required_s(src.required_s), required_e(src.required_e), sign(src.sign)
{
}
AForm::~AForm(void)
{
}

AForm &AForm::operator=(const AForm &src)
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

std::ostream &operator<<(std::ostream & os,AForm &F)
{
    os << F.getName() << ", required for sign = " << F.getRequiredS()<< ", required for execute = " << F.getRequiredE() << ", signed = " << F.getSigned();
    return os;
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

void AForm::setSigned(const bool sign)
{
    this->sign = sign;
}
void AForm::setName(const std::string name)
{
    const_cast<std::string&>(this->name) = name;
}
void AForm::setRequiredE(const int e)
{
    if (e < 1)
        throw (AForm::GradeTooHighException());
    else if (e > 150)
        throw (AForm::GradeTooLowException());
    const_cast<int&>(this->required_e) = e;
}
void AForm::setRequiredS(const int s)
{
    if (s < 1)
        throw (AForm::GradeTooHighException());
    else if (s > 150)
        throw (AForm::GradeTooLowException());
    const_cast<int&>(this->required_s) = s;
}

void AForm::BeSigned(Bureaucrat &B)
{
    if (this->required_s < B.getGrade())
        throw (AForm::GradeTooLowException());
    if (this->sign == 1)
        throw (AForm::isAlreadySigned());
    this->sign = 1;
}
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}
const char* AForm::isAlreadySigned::what() const throw()
{
    return "Is already signed.";
}
const char* AForm::NotSign::what() const throw()
{
    return "form is not signed";
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (this->required_e < executor.getGrade())
            throw (AForm::GradeTooLowException());
    if (this->sign == 0)
            throw (AForm::NotSign());
    this->action();
}
