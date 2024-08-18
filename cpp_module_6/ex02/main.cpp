/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:51:48 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 07:41:35 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base * generate(void)
{
    std::srand(std::time(nullptr));
    int randomNumber = std::rand() % 3;
    switch (randomNumber)
    {
        case 0:
            std::cout << "generate a A class" << std::endl;
            return  new A; 
        case 1:
            std::cout << "generate a B class" << std::endl;
            return  new B; 
        case 2:
            std::cout << "generate a C class" << std::endl;
            return new C;
    }
    return NULL;
}

void identify(Base* p)
{
    if (A* ptr = dynamic_cast<A*>(p))
        std::cout << "type is A" << std::endl;
    else if (B* ptr = dynamic_cast<B*>(p))
        std::cout << "type is B" << std::endl;
    else if (C* ptr = dynamic_cast<C*>(p))
        std::cout << "type is C" << std::endl;
    else
        std::cout << "type is Unknow" << std::endl;
}


void identify(Base& p)
{
    try
    {
        if (dynamic_cast<A*>(&p) != NULL)
            std::cout << "type is A" << std::endl;
        else if (dynamic_cast<B*>(&p) != NULL)
         std::cout << "type is B" << std::endl;
        else if (dynamic_cast<C*>(&p) != NULL)
            std::cout << "type is C" << std::endl;
        else
            std::cout << "type is Unknow" << std::endl;
    }
    catch (const std::bad_cast &e)
    {
        std::cerr << e.what() << std::endl;
    }

}

int main()
{
    Base* test = generate();
    identify(test);
    identify(*test);
}
