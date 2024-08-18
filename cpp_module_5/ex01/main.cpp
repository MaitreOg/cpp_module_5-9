/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:03:09 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 04:44:57 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat Sam ("Sam", 1);
        Bureaucrat Pa("Pa", 150);
        Form    dossier("secrets", 2, 1);
    
        std::cout << Sam << std::endl;
        std::cout << Pa << std::endl;
        std::cout << dossier << std::endl << std::endl;
       
        Sam.signForm(dossier);
        Pa.signForm(dossier);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << std::endl << std::endl;

    try
    {
        Bureaucrat Sam ("Sam", 30);
        Bureaucrat Pa("Pa", 40);
        Form    dossier("secrets", 45, 30);
        
        std::cout << Sam << std::endl;
        std::cout << Pa << std::endl;
        std::cout << dossier << std::endl << std::endl;
       
        Sam.signForm(dossier);
        Pa.signForm(dossier);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << std::endl << std::endl;

    try
    {
        Bureaucrat Sam ("Sam", 1);
        Bureaucrat Pa("Pa", 40);
        Form    dossier_secret("TOP SECRET", 3, 1);
        Form    dossier_banale("FLASH INFO", 150, 30);
        
        std::cout << Sam << std::endl;
        std::cout << Pa << std::endl;
        std::cout << dossier_banale << std::endl << std::endl;
       
        Sam.signForm(dossier_secret);
        Pa.signForm(dossier_banale);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}