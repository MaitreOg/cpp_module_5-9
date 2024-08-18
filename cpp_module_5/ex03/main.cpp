/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:03:09 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 06:43:26 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
int main()
{
    try
    {
        Intern  StagiaireA;
        AForm*   rrf;
        rrf = StagiaireA.makeForm("robotomy request", "Time to Robotics");
        delete rrf;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Intern  StagiaireB;
        AForm*   rrf1;
        rrf1 = StagiaireB.makeForm("presidential pardon", "Top Secret");
        delete rrf1;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    
    try
    {
        Intern  StagiaireC;
        AForm*   rrf2;
        rrf2 = StagiaireC.makeForm("shrubbery", "is a tree");
        delete rrf2;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Intern  StagiaireC;
        AForm*   rrf2;
        rrf2 = StagiaireC.makeForm("notexist", "is a tree");
        delete rrf2;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    return (0);
}