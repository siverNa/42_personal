/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:40:16 by sna               #+#    #+#             */
/*   Updated: 2022/04/10 18:17:37 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void iter(T* arr, std::size_t size, void (*f)(T))
{
	for (std::size_t i = 0; i < size; i++)
		f(arr[i]);
}

template <typename T>
void print(T target)
{
	std::cout << target << std::endl;
}

#endif