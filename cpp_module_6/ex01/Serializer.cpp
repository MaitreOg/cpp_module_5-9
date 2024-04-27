/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:35:25 by smarty            #+#    #+#             */
/*   Updated: 2024/04/24 22:40:35 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "constructor called" << std::endl;
}
Serializer::Serializer(Serializer &src)
{
    *this = src;
    std::cout << "copy constructor called" << std::endl;
}
Serializer::~Serializer(void)
{
    std::cout << "destructor called" << std::endl;
}
Serializer &Serializer::operator=(Serializer &src)
{
    std::cout << "constructor called" << std::endl;
    return src;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}