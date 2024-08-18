/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:50:45 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 07:27:41 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "constructor called" << std::endl;
}
ScalarConverter::ScalarConverter(ScalarConverter &src)
{
    *this = src;
    std::cout << "copy constructor called" << std::endl;
}
ScalarConverter::~ScalarConverter(void)
{
    std::cout << "destructor called" << std::endl;
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter &src)
{
    std::cout << "constructor called" << std::endl;
    return src;
}
void ScalarConverter::convert(std::string literal)
{
    int i = 0;
    bool f= 0;
 
    if (literal.size() == 1 && literal[i] >= 32 && literal[i] < 48 || literal[i] > 57 && literal[i] <= 126)
        literal = std::to_string(static_cast<int>(literal[0]));
    if (literal == "-inf")
    {
        std::cout << "char : Non displayable" << std::endl;
        std::cout << "int : -inf"  << std::endl;
        std::cout << "float : -inff" << std::endl;
        std::cout << "double : -inf" << std::endl;
        return ;
    }
    if (literal == "+inf")
    {
        std::cout << "char : Non displayable" << std::endl;
        std::cout << "int : +inf"  << std::endl;
        std::cout << "float : +inff" << std::endl;
        std::cout << "double : +inf" << std::endl;
        return ;
    }
   
    while (literal[i])
    {
        if ((literal[i] < '0' || literal[i] > '9') && literal[i] != '.')
            f = 1;
        i++;
    }
    if(literal[i - 1] == 'f')
    {
       literal[i - 1] = 0;
        f = 0;
    }
    if (literal.size() > 15 || std::stol(literal) > 2147483647)
        f = 1;
    if (f == 1)
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible"  << std::endl;
        std::cout << "float : nanf" << std::endl;
        std::cout << "double : nan" << std::endl;
        return ;
    }
    f = 0;
    i = 0;

    if (std::stoi(literal) <= 126 && std::stoi(literal) >= 32)
        std::cout << "char : '" << static_cast<char>(std::stoi(literal)) << "'" << std::endl;
    else
        std::cout << "char : Non displayable" << std::endl;
    std::cout << "int : " << std::stoi(literal) << std::endl;
    while (literal[i])
    {
        if (literal[i] == '.')
            f = 1;
        if (literal[i] == '.' && literal[i + 1] == '0' && literal[i + 2] == 0)
        {
            literal[i] = 0;
            f = 0;
        }
        i++;
    }
    if (f == 0)
    {
        std::cout << "float : " << std::fixed << std::setprecision(1) << std::stof(literal) << "f" << std::endl;
        std::cout << "double : " << std::fixed << std::setprecision(1)  << std::stod(literal) << std::endl;
    }
    else
    {
        std::cout << "float : " << std::stof(literal) << "f" << std::endl;
        std::cout << "double : " << std::stod(literal) << std::endl;
    }
}
