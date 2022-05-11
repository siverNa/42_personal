/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:52:39 by sna               #+#    #+#             */
/*   Updated: 2022/05/11 22:45:41 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <cstddef>

# include "util.hpp"
# include "iterator.hpp"
# include "random_access_iterator.hpp"

namespace ft {

	/**
	 * @brief Vectors are sequence containers representing arrays that can change in size.
	 * 
	 * @tparam T : Type of the elements.
	 * @tparam Alloc : Type of the allocator object
	 * used to define the storage allocation model.
	 */
	template <typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public: 
			/**
			 * @brief The first template parameter (T)
			 */
			typedef T 											value_type;
			/**
			 * @brief The first template parameter (T)
			 */
			typedef T const										const_value_type;
			/**
			 * @brief The second template parameter (Alloc),
			 * defaults to: allocator<value_type>
			 */
			typedef Alloc 										allocator_type;
			/**
			 * @brief allocator_type::reference
			 * 	for the default allocator: value_type&
			 */
			typedef typename allocator_type::reference			reference;
			/**
			 * @brief allocator_type::const_reference
			 * 	for the default allocator: const value_type&
			 */
			typedef typename allocator_type::const_reference	const_reference;
			/**
			 * @brief allocator_type::pointer
			 * 	for the default allocator: value_type*
			 */
			typedef typename allocator_type::pointer			pointer;
			/**
			 * @brief allocator_type::const_pointer
			 * 	for the default allocator: const value_type*
			 */
			typedef typename allocator_type::const_pointer		const_pointer;

			/**
			 * @brief a random access iterator to value_type
			 */
			typedef typename ft::random_access_iterator<value_type>			iterator;
			/**
			 * @brief a random access iterator to const value_type
			 */
			typedef typename ft::random_access_iterator<const_value_type>	const_iterator;
			/**
			 * @brief reverse_iterator<iterator>
			 */
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			/**
			 * @brief reverse_iterator<const_iterator>
			 */
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			/**
			 * @brief 	a signed integral type, 
			 * identical to: iterator_traits<iterator>::difference_type
			 */
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			/**
			 * @brief an unsigned integral type that can represent
			 * any non-negative value of difference_type
			 */
			typedef typename allocator_type::size_type						size_type;
		
		private:
			allocator_type	_alloc;
			pointer			_start;
			pointer			_end;
			pointer			_end_capacity;
	};
}

#endif