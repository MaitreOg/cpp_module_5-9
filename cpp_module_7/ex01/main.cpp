/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:49:56 by smarty            #+#    #+#             */
/*   Updated: 2024/04/26 14:55:20 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Iter.hpp"

template<typename T, typename Y>
void Iter(T* a, Y b, void (*func)(T))
{
    int i = 0;
	while (i < b)
    {
        func(a[i]);
        i++;
    }
}
template<typename T>
void print_tab(T a)
{
    std::cout << a << std::endl;
}
int main( void ) 
{
	int len = 3;
	std::string tab[3] = {"A", "B", "C"};
    Iter(tab, len, print_tab);
	return 0;
}