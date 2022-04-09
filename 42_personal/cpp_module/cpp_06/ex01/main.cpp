/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:08:02 by sna               #+#    #+#             */
/*   Updated: 2022/04/09 21:03:49 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main(void)
{
	Data test;
	uintptr_t	A;
	Data		*B;

	test.data = "sna";
	A = serialize(&test);
	B = deserialize(A);

	std::cout << "Original : " << &test << std::endl;
	std::cout << "deserialize : " << B << std::endl;

	std::cout << "Original : " << test.data << std::endl;
	std::cout << "deserialize : " << B->data << std::endl;
}