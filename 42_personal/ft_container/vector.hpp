/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:52:39 by sna               #+#    #+#             */
/*   Updated: 2022/05/18 22:09:33 by sna              ###   ########.fr       */
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

			/**
			 * @brief Return iterator to beginning
			 * Returns an iterator pointing to the first element in the vector.
			 */
			iterator begin() {return (_start); };

			/**
			 * @brief Return iterator to beginning
			 * Returns an iterator pointing to the first element in the vector.
			 */
			const_iterator begin() const {return (_start); };

			/**
			 * @brief Return iterator to end
			 * Returns an iterator referring to the past-the-end element
			 * in the vector container.
			 * If the container is empty, this function returns the same as vector::begin.
			 */
			iterator end()
			{
				if (this->empty())
					return (this->begin());
				return (_end);
			};

			/**
			 * @brief Return iterator to end
			 * Returns an iterator referring to the past-the-end element
			 * in the vector container.
			 * If the container is empty, this function returns the same as vector::begin.
			 */
			const_iterator end() const
			{
				if (this->empty())
					return (this->begin());
				return (_end);
			};

			/**
			 * @brief Return reverse iterator to reverse beginning
			 * Returns a reverse iterator pointing to the last element in the vector
			 * (i.e., its reverse beginning).
			 */
			reverse_iterator rbegin() {return (reverse_iterator(this->end())); };

			/**
			 * @brief Return reverse iterator to reverse beginning
			 * Returns a reverse iterator pointing to the last element in the vector
			 * (i.e., its reverse beginning).
			 */
			const_reverse_iterator rbegin() const {return (reverse_iterator(this->end())); };

			/**
			 * @brief Return reverse iterator to reverse end
			 * Returns a reverse iterator pointing to the theoretical element
			 * preceding the first element in the vector (which is considered its reverse end).
			 */
			reverse_iterator rend() {return (reverse_iterator(this->begin())); };

			/**
			 * @brief Return reverse iterator to reverse end
			 * Returns a reverse iterator pointing to the theoretical element
			 * preceding the first element in the vector (which is considered its reverse end).
			 */
			const_reverse_iterator rend() const {return (reverse_iterator(this->begin())); };

			/**
			 * @brief Return size
			 * Returns the number of elements in the vector.
			 */
			size_type size() const {return (this->_end - this->_start); };

			/**
			 * @brief Return maximum size
			 * Returns the maximum number of elements that the vector can hold.
			 */
			size_type max_size() const {return (this->_alloc.max_size()); };

			/**
			 * @brief Change size
			 * Resizes the container so that it contains n elements.
			 * 
			 * @param n
			 * New container size, expressed in number of elements.
			 * Member type size_type is an unsigned integral type.
			 * 
			 * @param val
			 * Object whose content is copied to the added elements
			 * in case that n is greater than the current container size.
			 * If not specified, the default constructor is used instead.
			 */
			void resize(size_type n, value_type val = value_type())
			{
				if (n > this->max_size())
					throw (std::out_of_range("ft::vector"));
				else if (n < this->size())
					while (this->size() > n)
						this->_alloc.destroy(--this->_end);
				else
					this->insert(this->_end, n - this->size(), val);
			};

			/**
			 * @brief Return size of allocated storage capacity
			 * Returns the size of the storage space currently allocated for the vector,
			 * expressed in terms of elements.
			 */
			size_type capacity() const {return (this->_end_capacity - this->_start); };

			/**
			 * @brief Test whether vector is empty
			 * Returns whether the vector is empty (i.e. whether its size is 0).
			 * This function does not modify the container in any way.
			 * To clear the content of a vector, see vector::clear.
			 * 
			 * @return true if the container size is 0, false otherwise.
			 */
			bool empty() const {return (this->size == 0); };

			/**
			 * @brief Request a change in capacity
			 * Requests that the vector capacity be at least enough to contain n elements.
			 * 
			 * @param n
			 * Minimum capacity for the vector.
			 * Note that the resulting vector capacity may be equal or greater than n.
			 * Member type size_type is an unsigned integral type.
			 */
			void reserve(size_type n)
			{
				if (n > this->max_size())
					throw (std::out_of_range("ft::vector"));
				if (this->capacity() == n)
					return ;
				pointer prev_start = this->_start;
				pointer prev_end = this->_end;
				size_type prev_size = this->size();
				size_type prev_capacity = this->capacity();

				this->_start = this->_alloc.allocate(n);
				this->_end_capacity = this->_start + n;
				this->_end = this->_start;
				
				for (pointer idx = prev_start; idx != prev_end; idx++)
					this->_alloc.construct(this->_end++, *idx);
				
				for (size_type len = (prev_end - prev_start); len > 0; len--)
					this->_alloc.destroy(--prev_end);
				
				this->_alloc.deallocate(prev_start, prev_capacity);
			};

			/**
			 * @brief Access element
			 * Returns a reference to the element at position n in the vector container.
			 * 
			 * @param n
			 * Position of an element in the container.
			 * Notice that the first element has a position of 0 (not 1).
			 */
			reference operator[] (size_type n) {return (*(_start + n)); };

			/**
			 * @brief Access element
			 * Returns a reference to the element at position n in the vector container.
			 * 
			 * @param n
			 * Position of an element in the container.
			 * Notice that the first element has a position of 0 (not 1).
			 */
			const_reference operator[] (size_type n) const {return (*(_start + n)); };

			/**
			 * @brief Access element
			 * Returns a reference to the element at position n in the vector.
			 * 
			 * @param n Position of an element in the container.
			 * If this is greater than, or equal to, the vector size,
			 * an exception of type out_of_range is thrown.
			 * Notice that the first element has a position of 0 (not 1).
			 */
			reference at(size_type n)
			{
				if (this->size() <= n)
					throw (std::out_of_range("ft::vector"));
				return (*(_start + n));
			};

			/**
			 * @brief Access element
			 * Returns a reference to the element at position n in the vector.
			 * 
			 * @param n Position of an element in the container.
			 * If this is greater than, or equal to, the vector size,
			 * an exception of type out_of_range is thrown.
			 * Notice that the first element has a position of 0 (not 1).
			 */
			const_reference at(size_type n)
			{
				if (this->size() <= n)
					throw (std::out_of_range("ft::vector"));
				return (*(_start + n));
			};

			/**
			 * @brief Access first element
			 * Returns a reference to the first element in the vector.
			 */
			reference front() {return (*_start); };

			/**
			 * @brief Access first element
			 * Returns a reference to the first element in the vector.
			 */
			const_reference front() const {return (*_start); };

			/**
			 * @brief Access last element
			 * Returns a reference to the last element in the vector.
			 */
			reference back() {return (*(_end - 1)); };

			/**
			 * @brief Access last element
			 * Returns a reference to the last element in the vector.
			 */
			const_reference back() const {return (*(_end - 1)); };
	};
}

#endif