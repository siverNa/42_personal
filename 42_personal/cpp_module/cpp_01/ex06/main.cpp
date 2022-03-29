/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:34:49 by sna               #+#    #+#             */
/*   Updated: 2022/03/30 00:58:13 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl H;

	if (argc != 2)
		std::cout <<"usage: ./harlFilter <Level>" << std::endl;
	else
		H.complain(argv[1]);

	return (0);
}