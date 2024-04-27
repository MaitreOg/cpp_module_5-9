/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:22:21 by smarty            #+#    #+#             */
/*   Updated: 2024/04/24 22:44:54 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data* src = new Data;
    Data* dest;
    src->value = 42;
    std::cout << src << std::endl;
    dest = Serializer::deserialize(Serializer::serialize(src));
    std::cout << dest << std::endl;
    std::cout << dest->value << std::endl;
    return 0;
}