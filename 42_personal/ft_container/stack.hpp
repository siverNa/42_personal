/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 00:06:56 by sna               #+#    #+#             */
/*   Updated: 2022/05/21 23:38:21 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack {
		public:
			/**
			 * @brief value_type
			 * The first template parameter (T)
			 */
			typedef T					value_type;
			/**
			 * @brief container_type
			 * The second template parameter (Container)	
			 */
			typedef Container			container_type;
			/**
			 * @brief size_type	
			 * an unsigned integral type
			 */
			typedef unsigned int		size_type;

		protected:
			container_type				c_t;

		public:
			/**
			 * @brief Construct stack
			 * Constructs a stack container adaptor object.
			 */
			explicit stack (const container_type& ctnr = container_type())
			{
				c_t = ctnr;
			};

			
	};

};//namespace ft


#endif