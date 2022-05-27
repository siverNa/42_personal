/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:24:25 by sna               #+#    #+#             */
/*   Updated: 2022/05/27 20:57:11 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "util.hpp"
# include "iterator.hpp"
# include "random_access_iterator.hpp"

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
		
};

#endif