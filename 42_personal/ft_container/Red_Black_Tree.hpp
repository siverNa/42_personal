/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Red_Black_Tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:12:38 by sna               #+#    #+#             */
/*   Updated: 2022/06/05 20:51:46 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <memory>

# include "util.hpp"
# include "iterator.hpp"
# include "tree_iterator.hpp"

namespace ft{
	template <class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
	class Red_Black_Tree {
		public:
			typedef T													value_type;
			typedef Compare												value_compare;
			typedef Alloc												allocator_type;

			typedef typename Alloc::template rebind<Node<T> >::other	node_allocator;
			typedef typename node_allocator::pointer					node_pointer;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef std::ptrdiff_t										difference_type;
			typedef std::size_t											size_type;
			typedef ft::tree_iterator<T>								iterator;
			typedef ft::tree_iterator<const T>							const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		
		private:
			allocator_type			_val_alloc;
			node_allocator			_node_alloc;
			value_compare			_compare;
			node_pointer			_nil;
			node_pointer			_header;
			node_pointer			_root;
			size_type				_size;

			bool is_nil(node_pointer node) const {
				return (node == _nil || node == _header);
			};
			
			node_pointer tree_min(node_pointer n) const {
				while (n != ft::u_nullptr && !is_nil(n->left))
					n = n->left;
				return (n);
			};

			node_pointer tree_max(node_pointer n) const {
				while (n != ft::u_nullptr && !is_nil(n->right))
					n = n->right;
				return (n);
			};

			void rotate_right(node_pointer node) {
				node_pointer y;

				y = node->left;
				node->left = y->right;
				if (!is_nil(y->right))
					y->right->parent = node;
				y->parent = node->parent;
				if (node->parent == ft::u_nullptr)
					_root = y;
				else if (node == node->parent->left)
					node->parent->left = y;
				else
					node->parent->right = y;
				y->right = node;
				node->parent = y;
			};

			void rotate_left(node_pointer node) {
				node_pointer y;

				y = node->right;
				node->right = y->left;
				if (!is_nil(y->left))
					y->left->parent = node;
				y->parent = node->parent;
				if (node->parent == ft::u_nullptr)
					_root = y;
				else if (node == node->parent->left)
					node->parent->left = y;
				else
					node->parent->right = y;
				y->left = node;
				node->parent = y;
			};

			node_pointer insert(node_pointer new_node) {
				if (_root == _header)
					_root = new_node;
				else
					insert_to_node(_root, new_node);
				return (new_node);
			};

			node_pointer insert_to_node(node_pointer root, node_pointer new_node) {
				if (_compare(*new_node->value, *root->value))
				{
					if (!is_nil(root->left))
						return (insert_to_node(root->left, new_node));
					root->left = new_node;
				}
				else
				{
					if (!is_nil(root->right))
						return (insert_to_node(root->right, new_node));
					root->right = new_node;
				}
				new_node->parent = root;
				return (new_node);
			};

			node_pointer insert_into_tree(node_pointer new_node, node_pointer where) {
				if (_root == _header)
					_root = new_node;
				else
					insert_to_node(where, new_node);
				return (new_node);
			};

			void insert_fixup(node_pointer node) {
				if (node != _root && node->parent != _root)
				{
					while (node != _root && !node->parent->is_black)
					{
						if (node->parent == node->parent->parent->left)
						{
							node_pointer uncle = node->parent->parent->right;
							if (!uncle->is_black)
							{
								node->parent->is_black = true;
								uncle->is_black = true;
								node->parent->parent->is_black = false;
								node = node->parent->parent;
							}
							else
							{
								if (node == node->parent->right)
								{
									node = node->parent;
									rotate_left(node);
								}
								node->parent->is_black = true;
								node->parent->parent->is_black = false;
								rotate_right(node);
							}
						}
						else
						{
							node_pointer uncle = node->parent->parent->left;
							if (!uncle->is_black)
							{
								node->parent->is_black = true;
								uncle->is_black = true;
								node->parent->parent->is_black = false;
								node = node->parent->parent;
							}
							else
							{
								if (node == node->parent->left)
								{
									node = node->parent;
									rotate_right(node);
								}
								node->parent->is_black = true;
								node->parent->parent->is_black = false;
								rotate_left(node->parent->parent);
							}
						}
					}
				}
				_root->is_black = true;
			};

			void clear_node(node_pointer node) {
				if (node && !is_nil(node))
				{
					clear_node(node->left);
					clear_node(node->right);
					_val_alloc.destroy(node->value);
					_val_alloc.deallocate(node->value, 1);
					_node_alloc.deallocate(node, 1);
				}
			};

			void init_nil_head() {
				_nil = _node_alloc.allocate(1);
				_node_alloc.construct(_nil, Node<T>());
				_nil->is_black = true;
				_nil->is_nil = true;
				_header = _node_alloc.allocate(1);
				_node_alloc.construct(_header, Node<T>());
				_header->value = _val_alloc.allocate(1);
				_val_alloc.construct(_header->value, T());
				_header->is_black = true;
			};

			void transplate(node_pointer where, node_pointer what) {
				if (where == _root)
					_root = what;
				else if (where == where->parent->left)
					where->parent->left = what;
				else
					where->parent->right = what;
				what->parent = where->parent;
			};

			void free_node(node_pointer node) {
				_val_alloc.destroy(node->value);
				_val_alloc.deallocate(node->value, 1);
				_node_alloc.deallocate(node, 1);
			};
		
		public:
			
	};
}//namespace ft

#endif