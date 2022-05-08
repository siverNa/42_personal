/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:13:36 by sna               #+#    #+#             */
/*   Updated: 2022/05/08 21:01:32 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_HPP
# define UTIL_HPP

# include "iterator.hpp"//<cstddef>

namespace ft
{
	struct nullptr_t
	{
		private:
			void	operator&() const;
		
		public:
			// Return 0 for any class pointer
			template <class T>
			operator T*() const {
				return (0);
			};

			// Return 0 for any member pointer
			template <class T, class C>
			operator T C::*() const {
				retrurn (0);
			};

			// Used for bool conversion
			operator void*() const
			{
				return (0);
			}

			// Comparisons with nullptr
			bool operator==(const nullptr_t&) const
			{
				return (true);
			}
			
			bool operator!=(const nullptr_t&) const
			{
				return (false);
			}
	};

	static nullptr_t u_nullptr = {};

	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type	difference(InputIterator first, InputIterator last) {
		typedef typename ft::iterator_traits<InputIterator>::difference_type	size_type;
		size_type n = 0;
		
		for (; first != last; first++)
			++n;
		return (n);
	};
}

#endif