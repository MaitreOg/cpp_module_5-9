/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:15:49 by smarty            #+#    #+#             */
/*   Updated: 2024/05/16 14:13:39 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <deque>
#include <list>
#include <algorithm>

class PmergeMe
{
private:
    std::list<int> list1;
    std::deque<int> list2;
public :
    PmergeMe(char **av);
    PmergeMe(PmergeMe &src);
    ~PmergeMe();
    PmergeMe &operator=(PmergeMe &src);
    void FusionDeque(int start, int end, int mid);
    void triFusionDeque(int start, int end);
    void InsertDeque(int start, int end);
    void FusionList(int start, int end, int mid);
    void triFusionList(int start, int end);
    void InsertList(int start, int end);
    void lunch();
    void print();
    int checkList();
};


#endif