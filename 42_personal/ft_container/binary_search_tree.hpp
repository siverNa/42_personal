/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:22:47 by sna               #+#    #+#             */
/*   Updated: 2022/06/01 19:12:15 by sna              ###   ########.fr       */
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
		public:
			/* first template argument */
			typedef T											value_type;
			/* BST type */
			typedef Binary_Search_Tree							BST;
			/* reference to the BST type */
			typedef BST&										BST_reference;
			/* Node type */
			typedef	Node										node_type;
			/* pointer to the Node type */
			typedef Node*										node_pointer;
			/* Node allocator */
			typedef Node_Alloc									node_alloc;
			/* iterator on stored Node */
			typedef ft::BST_iterator<Node, Compare>				iterator;
			/* const iterator on stored Node */
			typedef ft::BST_const_iterator<Node, Compare>		const_iterator;
			/* size type(based size_t) */
			typedef size_t										size_type;
		
		private:
			node_pointer		_last_node;
			node_alloc			_node_alloc;

			node_pointer BST_get_lower_node(node_pointer root)
			{
				while (root != _last_node && root->left != _last_node)
					root = root->left;
				return (root);
			}

			node_pointer BST_get_higher_node(node_pointer root)
			{
				while (root != _last_node && root->right != _last_node)
					root = root->right;
				return (root);
			}

			void replaceNode_in_Parent(node_pointer node, node_pointer new_node)
			{
				if (node->parent != _last_node)
				{
					if (_last_node->parent == node)
						_last_node->parent = new_node;
					if (node == node->parent->left)
						node->parent->left = new_node;
					else
						node->parent->right = new_node;
				}
			}

		public:
			Binary_Search_Tree(const node_alloc& node_alloc_start = node_alloc())
				: _no
	};
}//namespace ft

#endif