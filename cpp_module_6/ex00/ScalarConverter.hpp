/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:51:01 by smarty            #+#    #+#             */
/*   Updated: 2024/04/23 22:58:26 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class   ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter &src);
    ~ScalarConverter(void);
    ScalarConverter &operator=(ScalarConverter &src);
public:
    static void convert(std::string literal);
};

#endif