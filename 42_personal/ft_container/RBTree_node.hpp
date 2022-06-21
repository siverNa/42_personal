/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_node.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:20:10 by sna               #+#    #+#             */
/*   Updated: 2022/06/21 23:30:50 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_NODE_HPP
# define RBTREE_NODE_HPP

# include <memory>

namespace ft {
	enum rb_color
	{
		RED,
		BLACK
	};

	template <typename T, typename Alloc = std::allocator<T> >
	struct rb_node
	{
		public:
			T			*value;
			rb_node		*left;
			rb_node		*right;
			rb_node		*parent;
			rb_color	color;
			Alloc		alloc;

			
	};
}//namespace ft

#endif