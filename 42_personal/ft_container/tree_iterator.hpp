/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:24:25 by sna               #+#    #+#             */
/*   Updated: 2022/06/02 23:16:21 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "util.hpp"
# include "iterator.hpp"
# include "random_access_iterator.hpp"

namespace ft {
	template <class Value>
	struct Node {
		private:
			Value		*value;
			Node		*parent;
			Node		*left;
			Node		*right;
			bool		is_black;
			bool		is_nil;
		
		public:
			explicit Node(Value *src_val = 0 )
				: value(src_val), parent(0), left(0), right(0), is_black(false), is_nil(false)
			{};

			Node(Node const &other)
			{
				this->value = other.value;
				this->parent = other.parent;
				this->left = other.left;
				this->right = other.right;
				this->is_black = other.is_black;
				this->is_nil = other.is_nil;
				return (*this);
			};

			Node& operator=(const Node& other)
			{
				this->value = other.value;
				this->parent = other.parent;
				this->left = other.left;
				this->right = other.right;
				this->is_black = other.is_black;
				this->is_nil = other.is_nil;
				return (*this);
			};

			virtual ~Node() {};
	};

	template <typename T>
	class tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
		public:
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category		iterator_category;
			typedef typename ft::iterator_traits<T*>::value_type									value_type;
			typedef typename ft::iterator_traits<T*>::difference_type								difference_type;
			typedef typename ft::iterator_traits<T*>::pointer										pointer;
			typedef typename ft::iterator_traits<T*>::reference										reference;
			typedef Node<typename ft::remove_const<value_type>::type >*								node_pointer;

		private:
			node_pointer	_node;

			node_pointer tree_min(node_pointer n) const {
				while (n->left != ft::u_nullptr && !n->left->is_nil)
					n = n->left;
				return (n);
			};

			node_pointer tree_max(node_pointer n) const {
				while (!n->right->is_nil)
					n = n->right;
				return (n);
			};
		
		public:
			tree_iterator() {};

			tree_iterator(void *node) : _node(static_cast<node_pointer>(node)) {};

			tree_iterator(const tree_iterator<typename ft::remove_const<value_type>::type >& other) {*this = other; };

			tree_iterator& operator=(const tree_iterator<typename ft::remove_const<value_type>::type >& other)
			{
				this->_node = other.get_node();
				return (*this);
			};

			reference operator*() const {
				return (*(_node->value));
			};

			pointer operator->() const {
				return (_node->value);
			};

			/**
			 * @brief 전위 증가 연산자
			 */
			tree_iterator& operator++() {
				if (_node->right && !_node->right->is_nil)
					_node = tree_min(_node->right);
				else
				{
					node_pointer p = _node->parent;
					while (p != ft::u_nullptr && _node == p->right)
					{
						_node = p;
						p = p->parent;
					}
					_node = p;
				}
				return (*this);
			};

			tree_iterator operator++(int) {
				tree_iterator<value_type> temp = *this;
				if (!_node->right->is_nil)
					_node = tree_min(_node->right);
				else
				{
					node_pointer p = _node->parent;
					while (p != ft::u_nullptr && _node = p->right)
					{
						_node = p;
						p = p->parent;
					}
					_node = p;
				}
				return (temp);
			};

			tree_iterator& operator--() {
				if (_node->left && !_node->left->is_nil)
					_node = tree_max(_node->left);
				else
				{
					node_pointer p = _node->parent;
					while (p != ft::u_nullptr && _node == p->left)
					{
						_node = p;
						p = p->parent;
					}
					_node = p;
				}
				return (*this);
			};

			tree_iterator oparator--(int) {
				tree_iterator<value_type> temp = *this;
				if (_node->left && !_node->left->is_nil)
					_node = tree_max(_node->left);
				else
				{
					node_pointer p = _node->parent;
					while (p != ft::u_nullptr && _node == p->left)
					{
						_node = p;
						p = p->parent;
					}
					_node = p;
				}
				return (temp);
			};

			node_pointer get_node() const {return (_node); };
	};

	template <typename T1, typename T2>
	bool operator==(const tree_iterator<T1>& lhs, const tree_iterator<T2>& rhs)
	{
		return (lhs.get_node() == rhs.get_node());
	}

	template <typename T1, typename T2>
	bool operator!=(const tree_iterator<T1>& lhs, const tree_iterator<T2>& rhs)
	{
		return (lhs.get_node() != rhs.get_node());
	}
}//namespace ft

#endif