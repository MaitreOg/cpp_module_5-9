/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:57:53 by smarty            #+#    #+#             */
/*   Updated: 2024/05/04 16:27:31 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    int i = 0;
    int pos;
    std::string line;

    std::ifstream file("cpp_09/data.csv");
    if (!file.is_open()) 
    {
        std::cerr << "open file failed." << std::endl;
        return ;
    }

    std::getline(file, line);
    while (std::getline(file, line))
    {
        pos = (line.find(',') + 1);
        this->c_erate.push_back(std::stof(line.substr(pos)));
    }
    file.close();



    std::ifstream file2("cpp_09/data.csv");
    if (!file2.is_open()) 
    {
        std::cerr << "open file failed." << std::endl;
        return ;
    }
    std::getline(file2, line);
    while (std::getline(file2, line))
    {
        pos = 0;
        while (line[pos] != ',')
            pos++;
        line = line.substr(0, pos);
        this->c_date.push_back(line);
    }
    this->c_date.push_back("end_file");
    file2.close();
}
BitcoinExchange::BitcoinExchange(BitcoinExchange &src)
{
    *this = src;
}
BitcoinExchange::~BitcoinExchange()
{

}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &src)
{
    *this = src;
    return *this;
}

float BitcoinExchange::price(std::string date)
{
    int Y = std::stoi(date.substr(0, 4));
    int M = std::stoi(date.substr(5, 7));
    int D = std::stoi(date.substr(8, 10)); 
    for (int i = 0; i < this->c_date.size(); ++i) {
        int Y2 = std::stoi(this->c_date[i].substr(0, 4));
        int M2 = std::stoi(this->c_date[i].substr(5, 7)); // Indices du mois
        int D2 = std::stoi(this->c_date[i].substr(8, 10)); // Indices du jour
        if (Y == Y2) {
            if (M == M2) {
                if (D == D2) {
                    return this->c_erate[i];
                }
                else if (D < D2) {
                    return this->c_erate[i - 1];
                }
            } 
            else if (M < M2) {
                return this->c_erate[i - 1];
            }
        } 
        else if (Y < Y2) {
            return this->c_erate[i - 1];
        }
    }
    return 0;
}   


void BitcoinExchange::apply_value(char **av)
{
    std::string line;
    std::string value;
    int pos;
    int ok;
    std::ifstream file(av[1]);
    if (!file.is_open()) 
    {
        std::cerr << "open file failed." << std::endl;
        return ;
    }
    std::getline(file, line);
    while (std::getline(file, line))
    {
        ok = 1;
        int Y = std::stoi(line.substr(0, 4));
        int M = std::stoi(line.substr(5, 7));
        int D = std::stoi(line.substr(8, 10));
        try{
            if (M > 12 || D > 31 || Y < 2009)
            {
                ok = 0;
                throw badInput();
            }
        }
        catch (const BitcoinExchange::badInput& e)
        {
            std::cerr << "Error: " << e.what()  << " " << line.substr(0, 10) << std::endl;
        } 
        for(int i = 0; i < 10; i++)
        {
            if (i != 4 && i != 7)
            {
                try{
                    if (!(line[i] >= '0' && line[i] <= '9'))
                    {
                        ok = 0;
                        throw badInput();
                    }
                }
                catch (const BitcoinExchange::badInput& e)
                {
                std::cerr << "Error: " << e.what() << " " << line.substr(0, 10) << std::endl;
                }
            }
            else
            {
                try{
                    if (line[i] != '-')
                    {
                        ok = 0;
                        throw badInput();
                    }
                }
                catch (const BitcoinExchange::badInput& e)
                {
                    std::cerr << "Error: " << e.what() << " " << line.substr(0, 10) << std::endl;
                }
            }
        }
        pos = line.find('|') + 1;
        value = line.substr(pos);
        try{
            if (std::stof(value) < 0 && ok == 1) 
            {
                ok = 0;
                throw notPositive();
            }
        }
        catch (const BitcoinExchange::notPositive& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        try{
            if (std::stof(value) > 1000 && ok == 1) 
            {
                ok = 0;
                throw tooLarge();
            }
        }
        catch (const BitcoinExchange::tooLarge& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        if (ok == 1)
        {
            std::cout << line.substr(0, 10) << " => " << line.substr(pos) << " = " << this->price(line.substr(0, 10)) *  std::stof(line.substr(pos)) << std::endl;
        }
    }
    
}

void BitcoinExchange::print_graph()
{
    std::vector<std::string>::iterator ite;
    std::vector<float>::iterator it;
    ite = this->c_date.begin();
    it = this->c_erate.begin();
   for (int i = 0; i < 1613; i++)
    {
        std::cout << this->c_date[i] << "\t" << this->c_erate[i] << std::endl;
        it++;
        ite++;
    }
}

const char* BitcoinExchange::badInput::what() const throw()
{
    return " bad input";
}

const char* BitcoinExchange::notPositive::what() const throw()
{
    return " not a positive number";
}

const char* BitcoinExchange::tooLarge::what() const throw()
{
    return "too large a number";
}