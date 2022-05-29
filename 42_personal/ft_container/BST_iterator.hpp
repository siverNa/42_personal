/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:20:10 by sna               #+#    #+#             */
/*   Updated: 2022/05/29 20:08:35 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BST_ITERATOR_HPP
# define BST_ITERATOR_HPP

# include "iterator.hpp"
# include "random_access_iterator.hpp"

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
	};
}//namespace ft

#endif