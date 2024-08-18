/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:15:21 by smarty            #+#    #+#             */
/*   Updated: 2024/05/16 14:30:05 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        this->list1.push_back(std::stoi(av[i]));
        this->list2.push_back(std::stoi(av[i]));
    }
    std::cout << "constructor called" << std::endl;
}
int PmergeMe::checkList()
{
    for (int i = 0; i < this->list2.size(); i++)
    {
        for (int y = i + 1; y < this->list2.size(); y++)
        {
            if (this->list2[i] == this->list2[y])
            {
                std::cout << "Error : duplicates arguments" << std::endl;
                return (-1);
            }
        }
    }
    return 0;
}
PmergeMe::PmergeMe(PmergeMe &src)
{
    //this->list1 = src.getlist1();
    //this->list2 = src.getlist2();
}

PmergeMe::~PmergeMe()
{
    std::cout << "destructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(PmergeMe &src)
{
    //this->list1 = src.getlist1();
    //this->list2 = src.getlist2();
    return *this;
}

void PmergeMe::FusionDeque(int start, int end, int mid)
{
    std::deque<int> aux;
    int i = start;
    int j = mid;

    while (i < mid && j < end)
    {
        if(this->list2[i] < this->list2[j])
        {
            aux.push_back(this->list2[i]);
            i++;
        }
        if(this->list2[i] > this->list2[j])
        {
            aux.push_back(this->list2[j]);
            j++;
        }
    }
    while (i < mid)
    {
        aux.push_back(this->list2[i]);
        i++;
    }
    while (j < end)
    {
        aux.push_back(this->list2[j]);
        j++;
    }
    std::copy(aux.begin(), aux.end(), this->list2.begin() + start);
}

void PmergeMe::InsertDeque(int start, int end)
 {
    int n = end - start;
    for (int i = start + 1; i < end; i++) {
        int key = this->list2[i];
        int j = i - 1;
        while (j >= start && this->list2[j] > key)
        {
            this->list2[j + 1] = this->list2[j];
            j = j - 1;
        }
        this->list2[j + 1] = key;
    }
}

void PmergeMe::triFusionDeque(int start, int end)
{

    int n = end - start;
    if (n <= 4)
    {
        InsertDeque(start, end);
        return ;
    }
    int mid = start + n / 2;
    triFusionDeque(start, mid);
    triFusionDeque(mid, end);
    FusionDeque(start, end, mid);
}


void PmergeMe::FusionList(int start, int end, int mid)
{
    std::list<int> aux;
    std::list<int>::iterator i = std::next(list1.begin(), start);
    std::list<int>::iterator j = std::next(list1.begin(), mid);
    while (i != std::next(list1.begin(), mid) && j != list1.end())
    {
        if (*i < *j)
        {
            aux.push_back(*i);
            ++i;
        } 
        else
        {
            aux.push_back(*j);
            ++j;
        }
    }
    while (i != std::next(list1.begin(), mid))
    {
        aux.push_back(*i);
        ++i;
    }
    while (j != list1.end())
    {
        aux.push_back(*j);
        ++j;
    }

    std::copy(aux.begin(), aux.end(), std::next(list1.begin(), start));
}

void PmergeMe::InsertList(int start, int end)
{
    for (std::list<int>::iterator it = std::next(list1.begin(), start); it != std::next(list1.begin(), end); ++it)
    {
        int key = *it;
        std::list<int>::iterator j = it;
        while (j != list1.begin() && *(std::prev(j)) > key)
        {
            *j = *std::prev(j);
            *std::prev(j) = key;
            --j;
        }
    }
}

void PmergeMe::triFusionList(int start, int end)
{
    int n = end - start;
    if (n <= 4)
    {
        InsertList(start, end);
        return;
    }
    int mid = start + n / 2;
    triFusionList(start, mid);
    triFusionList(mid, end);
    FusionList(start, end, mid);
}

void PmergeMe::print()
{

    std::cout << "list =\t";
    for (std::list<int>::iterator it = std::next(list1.begin(), 0); it != std::next(list1.begin(), this->list1.size()); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    std::cout << "deque =\t";
    for (int value = 0; value < this->list2.size(); value++) 
    {
        std::cout << this->list2[value] << " ";
    }
    std::cout << std::endl;
}
void PmergeMe::lunch()

{
    std::cout << "before :   "; 
    for (int value = 0; value < this->list2.size(); value++) 
    {
        std::cout << this->list2[value] << " ";
    }
    std::cout << std::endl;
    int start = 0;
    int end = this->list1.size();
    triFusionDeque(start, end);
    triFusionList(start, end);
}

