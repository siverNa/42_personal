/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:08:02 by sna               #+#    #+#             */
/*   Updated: 2022/04/11 18:13:38 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "usage: ./convert <input argument>" << std::endl;
		return (1);
	}

	std::cout << std::fixed;
	std::cout.precision(1);
	Convert convert(av[1]);

	convert.toChar();
	convert.toInt();
	convert.toFloat();
	convert.toDouble();

	return (0);
}