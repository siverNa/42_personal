/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:24:25 by sna               #+#    #+#             */
/*   Updated: 2022/06/21 22:31:30 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <memory>

# include "iterator.hpp"
//# include "RBTree_node.hpp"

namespace ft {
	template <typename T, typename Pointer = T*, typename Reference = T&,
	typename Category = ft::random_access_iterator_tag, typename Distance = std::ptrdiff_t>
	class map_iterator
	{
		
	};
}//namespace ft

#endif