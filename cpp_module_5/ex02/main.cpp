/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:03:09 by smarty            #+#    #+#             */
/*   Updated: 2024/04/20 23:11:09 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat *Sam = new Bureaucrat("Sam", 1);
    Bureaucrat *Pa = new Bureaucrat("Pa", 26);
    AForm   *dossier = new ShrubberyCreationForm("secrets");
    AForm   *dossier2 = new ShrubberyCreationForm("public");
    
    std::cout << *Sam << std::endl;
    std::cout << *Pa << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    dossier2->BeSigned(*Pa);
    Pa->promote();
    std::cout << *Pa << std::endl;
    dossier2->BeSigned(*Pa);
    dossier->BeSigned(*Sam);

    std::cout << std::endl;
    std::cout << std::endl;

    dossier->execute(*Sam);
    dossier2->execute(*Pa);

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << *dossier << std::endl;
    std::cout << *dossier2 << std::endl;
    dossier2 = dossier;
    std::cout << *dossier2 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    
    delete Sam;
    delete Pa;
    delete dossier;
    return (0);
}