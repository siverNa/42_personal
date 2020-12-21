/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:52:18 by sna               #+#    #+#             */
/*   Updated: 2020/10/26 17:28:12 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int rev;
	int temp;

	rev = 0;
	while (rev < --size)
	{
		temp = tab[rev];
		tab[rev] = tab[size];
		tab[size] = temp;
		rev++;
	}
}
