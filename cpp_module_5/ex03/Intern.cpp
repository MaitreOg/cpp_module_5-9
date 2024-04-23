/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:52:53 by smarty            #+#    #+#             */
/*   Updated: 2024/04/23 18:03:27 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructer called" << std::endl;
}

Intern::Intern(Intern &src)
{
    *this = src;
    std::cout << "Intern copy constructer called" << std::endl;
}


Intern::~Intern(void)
{
    std::cout << "Intern destructeur called" << std::endl;
}

Intern &Intern::operator=(Intern &src)
{
    return *this;
}

AForm* Intern::makeForm(std::string nameForm, std::string target)
{
    int i = 0;
    std::string tab[3] = {"presidential pardon", "shrubbery", "robotomy request"};
    while (nameForm != tab[i] && i < 3)
        i++;
    switch(i)
    {
        AForm *dossier;
        case 0:
            dossier = new PresidentialPardonForm(target);
            std::cout << "Intern creates " << nameForm << std::endl;
            return (dossier);
        case 1:
            dossier = new ShrubberyCreationForm(target);
            std::cout << "Intern creates " << nameForm << std::endl;
            return (dossier);
        case 2:
            dossier = new RobotomyRequestForm(target);
            std::cout << "Intern creates " << nameForm << std::endl;
            return (dossier);
        case 3:
            std::cout << "Error : argument invalid" << std::endl;
            return NULL;
    }
    return NULL;
}
