/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:50:57 by smarty            #+#    #+#             */
/*   Updated: 2024/04/30 15:32:49 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int abs(int x) {
    return (x < 0) ? -x : x;
}

Span::Span(uintptr_t n) : containers(n, 0), size(n)
{
    std::cout << "constructor called" << std::endl;
}

Span::Span(const Span &src) : size(src.size)
{
   this->containers = src.containers;
}

Span::~Span()
{
    std::cout << "destructor called" << std::endl;
}

void Span::addNumber(int value)
{
    std::vector<int>::iterator it;
    for(it = this->containers.begin(); it != this->containers.end(); ++it)
    {
        if (*it == 0 && *(it + 1) == 0)
        {
                *it = value;
                return ;
        }
    }
    throw isFull();
}
int randomNum(int max)
{
    srand(time(0));
    return rand() % max;
}
void Span::addMoreNumbers()
{
    std::vector<int>::iterator it;
    for(it = this->containers.begin(); it != this->containers.end(); ++it)
    {
        if (*it == 0 && *(it + 1) == 0)
        {
            usleep(500);
            *it = randomNum(this->size);
        }
    }
}


int Span::shortestSpan()
{
    int min_distance = abs(this->containers[0] - this->containers[1]);
    int count = 0;
    for (int i = 0; i < this->containers.size(); i++)
    {
        if (this->containers[i] != 0 || (this->containers[i] == 0 && this->containers[i + 1] != 0 && i + 1 < this->containers.size()))
            count++;
    }
    if (count < 3)
        throw isEmpty();
    for (int i = 0; i < this->containers.size(); i++)
    {
         for (int y = (i + 1); y < this->containers.size(); y++)
        {
            if (abs(this->containers[i] - this->containers[y]) < min_distance)
                min_distance = abs(this->containers[i] - this->containers[y]);
        }
       
    }
    return (min_distance);
}

int Span::longestSpan()
{
    int count = 0;
    for (int i = 0; i < this->containers.size(); i++)
    {
        if (this->containers[i] != 0 || (this->containers[i] == 0 && this->containers[i + 1] != 0 && i + 1 < this->containers.size()))
            count++;
    }
    if (count < 3)
        throw isEmpty();
    int min_value = this->containers[0];
    int max_value = this->containers[0];

    for (int i = 1; i < this->containers.size(); ++i) {
        if (this->containers[i] < min_value) {
            min_value = this->containers[i];
        }
        if (this->containers[i] > max_value) {
            max_value = this->containers[i];
        }
    }
    int min_distance = max_value - min_value;
    return (min_distance);
}

Span &Span::operator=(Span &src)
{
    this->containers = src.containers;
    return *this;
}

void Span::printSpan()
{
    for (int i = 0; i < this->size; i++)
        std::cout << this->containers[i] << std::endl;
}

const char* Span::isEmpty::what() const throw()
{
    return "is empty";
}

const char* Span::isFull::what() const throw()
{
    return "is full";
}




