/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:57:57 by smarty            #+#    #+#             */
/*   Updated: 2024/05/04 16:17:14 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange* btc = new BitcoinExchange();
    btc->apply_value(av);

    //btc->print_graph();
    delete btc;
    return 0;
}