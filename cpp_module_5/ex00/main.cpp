/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:03:09 by smarty            #+#    #+#             */
/*   Updated: 2024/04/19 23:13:30 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *Sam = new Bureaucrat("Sam", 1);
    Bureaucrat *Pa = new Bureaucrat("Pa", 150);
    
    std::cout << *Sam << std::endl;
    std::cout << *Pa << std::endl;
    
    Pa->regress();
    Sam->regress();

    std::cout << std::endl;

    std::cout << *Sam << std::endl;
    std::cout << *Pa << std::endl;
    

    Pa->promote();
    Sam->promote();

    std::cout << std::endl;

    std::cout << *Sam << std::endl;
    std::cout << *Pa << std::endl;


    delete Sam;
    delete Pa;
    return (0);
}