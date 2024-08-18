/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:01 by smarty            #+#    #+#             */
/*   Updated: 2024/04/29 16:14:36 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
const int* easyfind(const std::vector<T> &vec, T value)
{
    typename std::vector<T>::const_iterator it;
    for(it = vec.begin(); it != vec.end(); ++it)
    {
        if (*it == value)
            return &(*it);
    }
    return nullptr;
}

int main()
{
    std::vector<int> tab;
    tab.push_back(1);
    tab.push_back(2);
    tab.push_back(3);
    tab.push_back(4);
    tab.push_back(5);
    const int* tab2 = easyfind(tab, 6);
    if (tab2 == nullptr)
    {
        std::cout << "Error : occurence not find" << std::endl;
    }
    else
    {
        for(int i= 0; tab2[i]; i++)
            std::cout << tab2[i] << std::endl;
    }

    std::cout  << std::endl;
    std::cout  << std::endl;
    std::cout  << std::endl;

    const int* tab3 = easyfind(tab, 3);
    if (tab3 == nullptr)
    {
        std::cout << "Error : occurence not find" << std::endl;
    }
    else
    {
        for(int i= 0; tab3[i]; i++)
            std::cout << tab3[i] << std::endl;
    }
    return 0;
}