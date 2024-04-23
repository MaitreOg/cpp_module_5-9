/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:03:09 by smarty            #+#    #+#             */
/*   Updated: 2024/04/23 18:01:40 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
int main()
{

    Intern  someRandomIntern;
    AForm*   rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    Intern  someRandomIntern1;
    AForm*   rrf1;
    rrf1 = someRandomIntern1.makeForm("presidential pardon", "Bender");

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    Intern  someRandomIntern2;
    AForm*   rrf2;
    rrf2 = someRandomIntern2.makeForm("shruberry", "Bender");

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
   
/*    Bureaucrat *Sam = new Bureaucrat("Sam", 1);
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
    dossier->execute(*Pa);

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
    delete dossier;*/
    return (0);
}