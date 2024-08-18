/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:13:12 by smarty            #+#    #+#             */
/*   Updated: 2024/05/04 18:35:08 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    std::string str = av[1];
    char delim = ' ';
    std::list<std::string> tokens;
    std::istringstream iss(str);
    std::string token;
    while (std::getline(iss, token, delim)) {
        tokens.push_back(token);
    }
    //std::list<std::string>::iterator it;
    //for (it = tokens.begin(); it != tokens.end(); ++it) {
    //    std::cout << *it << std::endl;
    //}
    Rpn calcul(tokens);
    int result = calcul.lunch();
    if (result == -100000)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    std::cout << result << std::endl;
    return 0;
}