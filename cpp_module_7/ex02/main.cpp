/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:04:20 by smarty            #+#    #+#             */
/*   Updated: 2024/04/27 17:53:30 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int main()
{
    
    Array<int>* tab = new Array<int>(6);
    Array<int>* tab2 = new Array<int>(1);
    try
    {
        std::cout << tab2->size() << std::endl;
        std::cout << (*tab2)[3] << std::endl;
    }
    catch (const Array<int>::outBound& e)
    {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }
    tab2 = tab;
    try
    {
        std::cout << tab2->size() << std::endl;
        std::cout << (*tab2)[3] << std::endl;
    }
        catch (const Array<int>::outBound& e)
    {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }
    delete tab2;
    return 0;
}