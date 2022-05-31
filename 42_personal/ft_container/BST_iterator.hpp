/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:20:10 by sna               #+#    #+#             */
/*   Updated: 2022/05/31 23:50:12 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BST_ITERATOR_HPP
# define BST_ITERATOR_HPP

# include "iterator.hpp"
# include "random_access_iterator.hpp"
# include "util.hpp"

namespace ft {
	template <typename T, class Compare>
	class BST_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef T				value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference			reference;
	
		protected:
			T*		_node;
			T*		_last_node;
			Compare	_comp;
		
		public:
			BST_iterator(const Compare& comp = Compare())
			: _node(), _last_node(), _comp(comp)
			{};

			BST_iterator(T* node_p, T* last_node, const Compare& comp = Compare())
			: _node(node_p), _last_node(last_node), _comp(comp)
			{};

			BST_iterator(const BST_iterator& copy)
			: _node(copy._node), _last_node(copy._last_node), _comp()
			{};

			virtual ~BST_iterator() {};
			
			BST_iterator& operator=(const BST_iterator& copy)
			{
				if (*this == copy)
					return (*this);
				this->_node = copy._node;
				this->_last_node = copy._last_node;
				this->_comp = copy._comp;
				return (*this);
			}

			bool operator==(const BST_iterator& bst_it)
			{return (this->_node == bst_it._node); };

			bool operator!=(const BST_iterator& bst_it)
			{return (this->_node != bst_it._node); };

			reference operator*() const
			{return (this->_node->value); };

			pointer operator->() const
			{return (&(operator*())); };

			/**
			 * @brief 전위 증가 연산자
			 */
			BST_iterator& operator++()
			{
				T* cur = _node;

				if (_node->right == _last_node)
				{
					cur = _node->parent;
					while (cur != _last_node && _comp(cur->value.first, _node->value.first))
						cur = cur->parent;
					_node = cur;
				}
				else if (cur == _last_node)
					_node = _last_node->right;
				else
				{
					cur = _node->right;
					if (cur == _last_node->parent && cur->right == _last_node)
						_node = cur;
					else
					{
						while (cur->left != _last_node)
							cur = cur->left;
					}
					_node = cur;
				}
				return (*this);
			};

			/**
			 * @brief 후위 증가 연산자
			 */
			BST_iterator operator++(int)
			{
				BST_iterator temp(*this);
				operator++();
				return (temp);
			};

			/**
			 * @brief 전위 감소 연산자
			 */
			BST_iterator& operator--()
			{
				T* cur = _node;

				if (_node->left == _last_node)
				{
					cur = _node->parent;
					while (cur != _last_node && !_comp(cur->value.first, _node->value.first))
						cur = cur->parent;
					_node = cur;
				}
				else if (cur == _last_node)
					_node = _last_node->right;
				else
				{
					cur = _node->left;
					if (cur == _last_node->parent && cur->left == _last_node)
						_node = cur;
					else
					{
						while (cur->right != _last_node)
							cur = cur->right;
					}
					_node = cur;
				}
				return (*this);
			};

			/**
			 * @brief 후위 감소 연산자
			 */
			BST_iterator operator--(int)
			{
				BST_iterator temp(*this);
				operator--();
				return (temp);
			};
	};

	template <typename T, class Compare>
	class BST_const_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef T				value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference			reference;
		
		protected:
			T*		_node;
			T*		_last_node;
			Compare	_comp;
		
		public:
			BST_const_iterator(const Compare& comp = Compare())
				: _node(), _last_node(), _comp(comp)
			{};

			BST_const_iterator(T* node_p, T* last_node, const Compare& comp = Compare())
				: _node(node_p), _last_node(last_node), _comp(comp)
			{};

			BST_const_iterator(const BST_const_iterator& copy)
				: _node(copy._node), _last_node(copy._last_node), _comp()
			{};

			BST_const_iterator(const BST_iterator<T, Compare>& copy)
				: _node(copy._node), _last_node(copy._last_node), _comp()
			{};

			virtual ~BST_const_iterator() {};

			BST_const_iterator& operator=(const BST_const_iterator& copy)
			{
				if (*this == copy)
					return (*this);
				this->_node = copy._node;
				this->_last_node = copy._last_node;
				this->_comp = copy._comp;
				return (*this);
			}

			bool operator==(const BST_const_iterator& bst_it)
			{return (this->_node == bst_it._node); };

			bool operator!=(const BST_const_iterator& bst_it)
			{return (this->_node != bst_it._node); };

			reference operator*() const
			{return (this->_node->value); };

			pointer operator->() const
			{return (&(operator*())); };

			/**
			 * @brief 전위 증가 연산자
			 */
			BST_const_iterator& operator++()
			{
				T* cur = _node;

				if (_node->right == _last_node)
				{
					cur = _node->parent;
					while (cur != _last_node && _comp(cur->value.first, _node->value.first))
						cur = cur->parent;
					_node = cur;
				}
				else if (cur == _last_node)
					_node = _last_node->right;
				else
				{
					cur = _node->right;
					if (cur == _last_node->parent && cur->right == _last_node)
						_node = cur;
					else
					{
						while (cur->left != _last_node)
							cur = cur->left;
					}
					_node = cur;
				}
				return (*this);
			};

			/**
			 * @brief 후위 증가 연산자
			 */
			BST_const_iterator operator++(int)
			{
				BST_const_iterator temp(*this);
				operator++();
				return (temp);
			};

			/**
			 * @brief 전위 감소 연산자
			 */
			BST_const_iterator& operator--()
			{
				T* cur = _node;

				if (_node->left == _last_node)
				{
					cur = _node->parent;
					while (cur != _last_node && !_comp(cur->value.first, _node->value.first))
						cur = cur->parent;
					_node = cur;
				}
				else if (cur == _last_node)
					_node = _last_node->right;
				else
				{
					cur = _node->left;
					if (cur == _last_node->parent && cur->left == _last_node)
						_node = cur;
					else
					{
						while (cur->right != _last_node)
							cur = cur->right;
					}
					_node = cur;
				}
				return (*this);
			};

			/**
			 * @brief 후위 감소 연산자
			 */
			BST_const_iterator operator--(int)
			{
				BST_const_iterator temp(*this);
				operator--();
				return (temp);
			};
	};

}//namespace ft

#endif