/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:12:38 by sna               #+#    #+#             */
/*   Updated: 2022/06/22 17:33:26 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

# include <iostream>

# include "iterator.hpp"
# include "util.hpp"
# include "type_trait.hpp"
# include "algorithm.hpp"
# include "RBTree_node.hpp"

namespace ft {
	template <typename T, typename Pointer = T*, typename Reference = T&,
			typename Category = ft::bidirectional_iterator_tag, typename Distance = std::ptrdiff_t>
	class RBTree_iterator
	{
		public:
			typedef T											value_type;
			typedef Pointer										pointer;
			typedef Reference									reference;
			typedef ft::rb_node<value_type>						node;
			typedef node*										node_pointer;
			typedef Distance									difference_type;
			typedef Category									iterator_category;
			typedef RBTree_iterator<T, Pointer, Reference>		this_type_iterator;
			typedef RBTree_iterator<T, T*, T&>					iterator;
			typedef RBTree_iterator<T, const T*, const T&>		const_iterator;

		private:
			node_pointer _pointer;

			node_pointer find_next()
			{
				node_pointer result = this->_pointer->parent;

				if (!this->_pointer->right->empty())//오른쪽 원소가 있으면 그 원소의 가장 작은 값 가져오기
				{
					result = this->_pointer->right;
					while(!result->left->empty())
						result = result->left;
					return (result);
				}
				else if (!this->_pointer->parent->empty())//오른쪽 원소가 없으면 left child인 result까지 올라가기
				{
					result = this->_pointer;
					while (!result->parent->empty())
					{
						if (result->is_left())
							return (result->parent);
						result = result->parent;
					}
					result = result->parent;//없으면 null 반환
				}
				return (result);
			};

			node_pointer find_prev()
			{
				node_pointer result = this->_pointer->parent;

				if (!this->_pointer->left->empty())//왼쪽 트리 중 가장 큰 원소 가져오기
				{
					result = this->_pointer->left;
					while (!result->right->empty())
						result = result->right;
					return (result);
				}
				else if (!this->_pointer->parent->empty())
				{
					result = this->_pointer;
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
			RBTree_iterator()
				: _pointer(NULL) {};

			RBTree_iterator(const node_pointer p)
				: _pointer(p) {};
			
			RBTree_iterator(const iterator& obj)
				: _pointer(obj.get_pointer()) {};
			
			~RBTree_iterator() {};

			template <typename T2, typename P2, typename R2>
			const this_type_iterator& operator=(const RBTree_iterator<T2, P2, R2>& rbt)
			{
				this->_pointer = rbt.get_pointer();
				return (*this);
			};

			reference operator*() const
			{
				return (this->_pointer->get_value());
			};

			pointer operator&() const
			{
				return (&(this->_pointer->get_value()));
			};

			this_type_iterator& operator++()
			{
				this->_pointer = this->find_next();
				return (*this);
			};

			this_type_iterator operator++(int)
			{
				this_type_iterator temp(*this);
				this->operator++();
				return (temp);
			}

			this_type_iterator& operator--()
			{
				this->_pointer = this->find_prev();
				return (*this);
			};

			this_type_iterator operator--(int)
			{
				this_type_iterator temp(*this);
				this->operator--();
				return (temp);
			}

			template <typename T2, typename A, typename B, typename C>
			bool operator==(const RBTree_iterator<T2, A, B, C>& right) const
			{
				return (this->_pointer == right.get_pointer());
			};

			template <typename T2, typename A, typename B, typename C>
			bool operator!=(const RBTree_iterator<T2, A, B, C>& right) const
			{
				return (this->_pointer != right.get_pointer());
			};

			node_pointer get_pointer() const
			{
				return (this->_pointer);
			};
	};
}//namespace ft

#endif