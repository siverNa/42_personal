/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:20:10 by sna               #+#    #+#             */
/*   Updated: 2022/05/27 22:07:49 by sna              ###   ########.fr       */
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
		typedef T				value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference			reference;
	};
}//namespace ft

#endif