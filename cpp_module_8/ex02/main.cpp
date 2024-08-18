/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:06:01 by smarty            #+#    #+#             */
/*   Updated: 2024/04/30 16:01:12 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737); 
    //[...] 
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    std::list<int> lstack; // Modifier le type de la variable mstack

    lstack.push_back(5); // Utiliser push_back() au lieu de push()
    lstack.push_back(17);

    std::cout << lstack.back() << std::endl; // Utiliser back() au lieu de top()

    lstack.pop_back(); // Utiliser pop_back() au lieu de pop()

    std::cout << lstack.size() << std::endl;

    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737); 
    //[...] 
    lstack.push_back(0);

    std::list<int>::iterator it2 = lstack.begin(); // Utiliser begin() au lieu de top()
    std::list<int>::iterator ite2 = lstack.end();
    
    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    return 0;
}