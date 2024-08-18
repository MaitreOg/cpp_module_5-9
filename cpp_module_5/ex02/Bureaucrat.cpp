/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:03:05 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 05:03:31 by smarty           ###   ########.fr       */
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

std::ostream &operator<<(std::ostream & os,Bureaucrat &B)
{
    os << B.getName() << ", Bureaucrate grade " << B.getGrade();
    return os;
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
    if ((this->grade - 1) < 1)
        throw GradeTooHighException();
    this->grade -= 1;
}
void    Bureaucrat::regress()
{
    if ((this->grade + 1) > 150)
        throw GradeTooLowException();
    this->grade += 1;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.BeSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << this->name << " could not signed " << form.getName() << " because " << e.what() << std::endl;
    }
}
void    Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->name<< " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << this->name << " could not execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}




