/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:50:06 by smarty            #+#    #+#             */
/*   Updated: 2024/04/26 14:55:11 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template<typename T, typename Y>
void Iter(T* a, Y b, void (*func)(T));
template<typename T>
void print_tab(T a);
#endif