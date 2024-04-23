/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:03:09 by smarty            #+#    #+#             */
/*   Updated: 2024/04/19 23:57:19 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat *Sam = new Bureaucrat("Sam", 1);
    Bureaucrat *Pa = new Bureaucrat("Pa", 150);
    Form    *dossier = new Form("secrets", 2, 1);
    
    std::cout << *Sam << std::endl;
    std::cout << *Pa << std::endl;

    std::cout << std::endl;

    dossier->BeSigned(*Pa);
    dossier->BeSigned(*Sam);


    std::cout << *dossier << std::endl;
    delete Sam;
    delete Pa;
    delete dossier;
    return (0);
}