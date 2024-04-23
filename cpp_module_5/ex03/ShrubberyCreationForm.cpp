/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:41:54 by smarty            #+#    #+#             */
/*   Updated: 2024/04/20 23:09:19 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(target + "_Shruberry", 145, 137), target(target)
{
    
    std::cout << "Shrubbery constructer called" << std::endl; 
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)  : AForm(src.getName(), 145, 137), target(src.getTarget())
{
    std::cout << "Shrubbery copy constructer called" << std::endl; 
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Shrubbery destructor called" << std::endl; 
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &src)
{
    this->target = src.target;
    this->name = src.name;
    this->sign = src.sign;
    return *this;
}
void ShrubberyCreationForm::action() const
{
    std::string name_file = this->target + "_Shrubbery";
    std::ofstream file(name_file);
     if (!file.is_open())
     {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return ;
    }
    file << "    A    " << std::endl;
    file << "   / \\   " << std::endl;
    file << "  B   C  " << std::endl;
    file << " / \\     " << std::endl;
    file << "D   E    " << std::endl;
    file.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->target;
}