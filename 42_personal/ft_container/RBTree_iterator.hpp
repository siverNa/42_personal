/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:12:38 by sna               #+#    #+#             */
/*   Updated: 2022/06/22 15:44:53 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

# include <iostream>

# include "iterator.hpp"
# include "util.hpp"
# include "type_trait.hpp"
# include "algorithm.hpp"

namespace ft {
	template <typename T, typename Pointer = T*, typename Reference = T&,
			typename Category = ft::bidirectional_iterator_tag, typename Distance = std::ptrdiff_t>
	class RBTree_iterator
	{
		
	};
}//namespace ft

#endif