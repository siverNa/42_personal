/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:08:02 by sna               #+#    #+#             */
/*   Updated: 2022/04/10 00:47:56 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	for (int i = 0; i < 3; i++)
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		std::cout << std::endl;
		delete base;
	}
	return (0);
}