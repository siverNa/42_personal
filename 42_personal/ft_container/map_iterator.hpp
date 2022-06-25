/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:24:25 by sna               #+#    #+#             */
/*   Updated: 2022/06/25 21:42:13 by sna              ###   ########.fr       */
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

			node* find_next()
			{
				node *result = this->_node->parent;
				
				//오른쪽 노드가 있으면 현재 노드 기준 왼쪽 서브트리의 작은 원소 찾기
				if (!this->_node->right->empty())
				{
					result = this->_node->right;
					while (!result->left->empty())
						result = result->left;
					return (result);
				}//오른쪽 노드가 없으면 처음 나오는 왼쪽 자식 노드 찾기
				else if (!this->_node->parent->empty())
				{
					result = this->_node;
					while (!result->parent->empty())
					{
						if (result->is_left())
							return (result->parent);
						result = result->parent;
					}
					result = result->parent;
				}
				return (result);
			};

			node* find_prev()
			{
				node *result = this->_node->parent;

				if (!this->_node->left->empty())
				{
					result = this->_node->left;
					while (!result->right->empty())
						result = result->right;
					return (result);
				}
				else if (!this->_node->parent->empty())
				{
					result = this->_node;
					while (!result->parent->empty())
					{
						if (result->is_right())
							return (result->parent);
						result = result->parent;
					}
					result = result->parent;
				}
				return (result);
			};
		
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

			this_type_iterator& operator++()
			{
				this->_node = this->find_next();
				return (*this);
			};

			this_type_iterator operator++(int)
			{
				this_type_iterator temp(*this);
				this->operator++();
				return (temp);
			};

			this_type_iterator& operator--()
			{
				this->_node = this->find_prev();
				return (*this);
			};

			this_type_iterator operator--(int)
			{
				this_type_iterator temp(*this);
				this->operator--();
				return (temp);
			};
	};
}//namespace ft

#endif