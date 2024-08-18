/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:03:09 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 06:25:40 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try
	{
		Bureaucrat Sam("Sam", 1);
		Bureaucrat Pa("Pa", 26);
		ShrubberyCreationForm dossier1("secrets");
		ShrubberyCreationForm dossier2("public");
	
		std::cout << Sam << std::endl;
		std::cout << Pa << std::endl;

		std::cout << std::endl;

		Pa.promote();
		std::cout << Pa << std::endl;
		Pa.signForm(dossier2);
		Sam.signForm(dossier1);

		std::cout << std::endl;
		
		Sam.executeForm(dossier1);
		Pa.executeForm(dossier2);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << std::endl << std::endl;

	try
	{
		Bureaucrat Sam("Sam", 1);

		PresidentialPardonForm dossier1("Sam$");
		PresidentialPardonForm dossier2("Not sam ...");
		dossier2 = dossier1;

		Sam.signForm(dossier2);
		Sam.executeForm(dossier2);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl;

	try
	{
		Bureaucrat Sam("Sam", 1);
		Bureaucrat Pa("Pa", 150);

		RobotomyRequestForm dossier("cyborg");

		Sam.signForm(dossier);
		Sam.executeForm(dossier);
		Pa.executeForm(dossier);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl;


	
	
	return (0);
}