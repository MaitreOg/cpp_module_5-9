/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:03:05 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 03:39:28 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    try
    {
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }

catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    if (&src != this)
        *this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (&src != this)
    {
        this->setName(src.name);
        this->grade = src.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
}
void    Bureaucrat::setName(const std::string str)
{
    const_cast<std::string&>(this->name) = str;
}

int Bureaucrat::getGrade() const
{
    return  this->grade;
}
const std::string Bureaucrat::getName() const
{
    return this->name;
}
void    Bureaucrat::promote()
{
    try
    {
        if ((this->grade - 1) < 1)
            throw GradeTooHighException();
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
        this->grade += 1;
    }
    this->grade -= 1;
}
void    Bureaucrat::regress()
{
    try
    {
        if ((this->grade + 1) > 150)
            throw GradeTooLowException();
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
        this->grade -= 1;
    }
    this->grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}
std::ostream &operator<<(std::ostream & os,Bureaucrat &B)
{
    os << B.getName() << ", Bureaucrate grade " << B.getGrade();
    return os;
}

