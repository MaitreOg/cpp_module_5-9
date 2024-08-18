/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:57:55 by smarty            #+#    #+#             */
/*   Updated: 2024/05/04 16:25:00 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

class BitcoinExchange
{
private:
    std::vector<std::string> c_date;
    std::vector<float> c_erate;
public :
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange &src);
    ~BitcoinExchange();
    BitcoinExchange &operator=(BitcoinExchange &src);
    void print_graph();
    void apply_value(char **av);
    float price(std::string date);
    class badInput : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    class notPositive : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    class tooLarge : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};


#endif