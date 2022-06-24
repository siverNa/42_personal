/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:24:25 by sna               #+#    #+#             */
/*   Updated: 2022/06/24 23:27:01 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <memory>

# include "iterator.hpp"
# include "RBTree_node.hpp"

namespace ft {
	template <typename T, typename Pointer = T*, typename Reference = T&,
	typename Category = ft::random_access_iterator_tag, typename Distance = std::ptrdiff_t>
	class map_iterator
	{
		public:
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::reference			reference;
			typedef typename ft::iterator_traits<T>::const_reference	const_reference;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::const_pointer		const_pointer;
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::bidirectional_iterator_tag				iterator_categoty;
			typedef typename ft::rb_node<T>								node;
			typedef map_iterator<T, T*, T&>								iterator;
			typedef map_iterator<T, const T*, const T&>					const_iterator;
			typedef map_iterator<T, Pointer, Reference>					this_type_iterator;
		
		private:
			node* _node;
		
		public:
			map_iterator(node* node) : _node(node) {};

			map_iterator(const map_iterator& obj) {*this = obj; };

			template <typename T2, typename P2, typename R2>
			map_iterator& operator=(const map_iterator<T2, P2, R2>& rhs)
			{
				if (this != &rhs)
					this->_node = rhs._node;
				return (*this);
			};

			virtual ~map_iterator() {};

			template <typename T2, typename P2, typename R2, typename C2>
			bool operator==(const map_iterator<T2, P2, R2, C2>& rhs) {
				return (_node == rhs._node);
			}

			template <typename T2, typename P2, typename R2, typename C2>
			bool operator!=(const map_iterator<T2, P2, R2, C2>& rhs) {
				return (_node != rhs._node);
			}

			reference operator*()
			{
				return (this->_node->get_value());
			};

			const_reference operator*() const
			{
				return (this->_node->get_value());
			};

			pointer operator->()
			{
				return (&(this->_node->get_value()));
			};

			const_pointer operator->() const
			{
				return (&(this->_node->get_value()));
			};
	};
}//namespace ft

#endif