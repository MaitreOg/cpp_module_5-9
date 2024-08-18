/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:51:19 by smarty            #+#    #+#             */
/*   Updated: 2024/04/30 15:38:12 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    try 
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.printSpan();
    }
    catch (const Span::isFull& e)
    {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const Span::isEmpty& e)
    {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << std::endl;

    Span sp2 = Span(5);
    sp2.addMoreNumbers();
    sp2.printSpan();

    std::cout << std::endl;

    try
    {
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (const Span::isEmpty& e)
    {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }
    return 0;
    
}