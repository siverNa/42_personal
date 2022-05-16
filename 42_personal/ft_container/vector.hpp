/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:52:39 by sna               #+#    #+#             */
/*   Updated: 2022/05/16 23:37:56 by sna              ###   ########.fr       */
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
# include "algorithm.hpp"
# include "type_trait.hpp"

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
		
		public:
			/**
			 * @brief  empty container constructor (default constructor)
			 * Constructs an empty container, with no elements.
			 */
			explicit vector(const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _start(u_nullptr), _end(u_nullptr), _end_capacity(u_nullptr)
			{};

			/**
			 * @brief fill constructor
			 * Constructs a container with n elements. Each element is a copy of val.
			 * 
			 * @param n Initial container size
			 * (i.e., the number of elements in the container at construction).
			 * Member type size_type is an unsigned integral type.
			 * 
			 * @param val Value to fill the container with.
			 *  Each of the n elements in the container will be initialized to a copy of this value.
			 * 	Member type value_type is the type of the elements in the container, 
			 * 	defined in vector as an alias of its first template parameter (T).
			 */
			explicit vector(size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type())
				: _alloc(alloc)
			{
				// allocate : 초기화되지 않은 메모리 공간을 할당하여 그 시작 주소를 반환하는 함수
				_start = _alloc.allocate(n);
				_end = _start;
				_end_capacity = _start + n;
				while (n--)
				{
					//construct : 초기화되지 않은 공간에 요소를 저장하는 함수
					//1번째 요소가 가리키는 주소에 2번째 요소를 저장
					_alloc.construct(_end, val);
					_end++;
				}
			};

			/**
			 * @brief range constructor 
			 * Constructs a container with as many elements as the range [first,last),
			 * with each element constructed from its corresponding element in that range,
			 * in the same order.
			 */
			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = u_nullptr)
				: _alloc(alloc)
			{
				size_type n = ft::difference(first, last);
				_start = _alloc.allocate(n);
				_end = _start;
				_end_capacity = _start + n;
				while (n--)
				{
					_alloc.construct(_end, *first++);
					_end++;
				}
			};

			/**
			 * @brief copy constructor
			 * Constructs a container with a copy of each of the elements in x,
			 * in the same order.
			 */
			vector (const vector& x)
				: _alloc(x._alloc), _start(u_nullptr), _end(u_nullptr), _end_capacity(u_nullptr)
			{
				size_type n = x.size();
				_start = _alloc.allocate(n);
				_end = _start;
				_end_capacity = _start + n;
				pointer temp = x._start;
				while (n--)
				{
					_alloc.construct(_end, *temp++);
					_end++;
				}
			};

			/**
			 * @brief Vector destructor
			 * Destroys the container object.
			 * 
			 * This destroys all container elements,
			 * and deallocates all the storage capacity allocated
			 * by the vector using its allocator.
			 */
			~vector()
			{
				this->clear();
				this->_alloc.deallocate(this->_start, this->capacity());
			};

			/**
			 * @brief Assign content 
			 * Assigns new contents to the container, 
			 * replacing its current contents, and modifying its size accordingly.
			 * 
			 * Copies all the elements from x into the container.
			 * The container preserves its current allocator, 
			 * which is used to allocate storage in case of reallocation.
			 */
			vector& operator= (const vector& x)
			{
				if (x == *this)
					return (*this);
				this->clear();
				this->insert(this->_start, x.begin(), x.end());
				return (*this);
			};
	};
}

#endif