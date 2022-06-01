/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:22:47 by sna               #+#    #+#             */
/*   Updated: 2022/06/01 18:27:00 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

# include "BST_iterator.hpp"
# include "util.hpp"

namespace ft
{
	template <class T, class Compare = ft::less<T>, class Node = ft::BST_Node<T>,
				class Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
	class Binary_Search_Tree
	{
		
	};
}//namespace ft

#endif