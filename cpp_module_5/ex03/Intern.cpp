/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:52:53 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 06:43:05 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern &src)
{
    if (&src != this)
        *this = src;
}


Intern::~Intern(void)
{
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
            std::cout << "Error : the intern is fired" << std::endl;
            return NULL;
    }
    return NULL;
}
