/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:37:01 by sna               #+#    #+#             */
/*   Updated: 2022/05/23 22:05:37 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <cstddef>

# include "util.hpp"
# include "iterator.hpp"

namespace ft {
	template < class Key,										// map::key_type
			class T,											// map::mapped_type
			class Compare = ft::less<Key>,						// map::key_compare
			class Alloc = std::allocator<pair<const Key, T> >	// map::allocator_type
			> class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef pair<const Key, T>								value_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef size_t											size_type;
		
			class value_compare : ft::binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					Compare		comp;
					value_compare (Compare c) : comp(c) {};
				public:
					typedef bool				result_type;
					typedef value_type			first_argument_type;
					typedef value_type			second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					};
			};

	};
}//namespace ft

#endif