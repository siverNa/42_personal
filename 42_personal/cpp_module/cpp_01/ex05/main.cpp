/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:18:04 by sna               #+#    #+#             */
/*   Updated: 2022/03/29 22:50:39 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl H;

    H.complain("DEBUG");
    H.complain("INFO");
    H.complain("WARNING");
    H.complain("ERROR");

    return (0);
}