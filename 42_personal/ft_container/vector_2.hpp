/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:52:39 by sna               #+#    #+#             */
/*   Updated: 2022/06/21 17:07:13 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_2_HPP
# define VECTOR_2_HPP

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
			typedef const T										const_value_type;
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
			typedef typename allocator_type::difference_type				difference_type;
			/**
			 * @brief an unsigned integral type that can represent
			 * any non-negative value of difference_type
			 */
			typedef typename allocator_type::size_type						size_type;
		
		private:
			pointer			_node;
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;
			
			void realloc(size_type n)
			{
				pointer new_node = _alloc.allocate(n);

				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(new_node + i, _node[i]);
					_alloc.destroy(_node + i);
				}
				_node = new_node;
				_capacity = n;
			}

			void push(size_type idx, const value_type &val)
			{
				(*this)[idx] = val;
			}
		
		public:
			/**
			 * @brief  empty container constructor (default constructor)
			 * Constructs an empty container, with no elements.
			 */
			explicit vector(const allocator_type& alloc = allocator_type())
				: _node(0), _alloc(alloc), _size(0), _capacity(0)
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
				: _alloc(alloc), _size(n), _capacity(n)
			{
				_node = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_node + i, val);
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
				_size = 0;

				for (InputIterator i = first; i != last; i++)
					_size++;

				for (_capacity = 1; _capacity < _size;)
					_capacity *= 2;
				
				_node = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++, first++)
					_alloc.construct(_node + i, *first);
			};

			/**
			 * @brief copy constructor
			 * Constructs a container with a copy of each of the elements in x,
			 * in the same order.
			 */
			vector (const vector& x)
				: _node(x._node), _alloc(x._alloc), _size(x._size), _capacity(x._capacity)
			{
				_node = _alloc.allocate(_capacity);
				size_type i = 0;

				for (const_iterator it = x.begin(); it != x.end(); it++)
					_alloc.construct(_node + i++, *it);
			};

			/**
			 * @brief Vector destructor
			 * Destroys the container object.
			 * 
			 * This destroys all container elements,
			 * and deallocates all the storage capacity allocated
			 * by the vector using its allocator.
			 */
			virtual ~vector()
			{
				this->clear();
				if (_capacity != 0)
					_alloc.deallocate(_node, _capacity);
				_size = 0;
				_capacity = 0;
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
				if (_capacity < x._size)
					this->reserve(x._size);
				this->_alloc = x._alloc;
				this->_size = x._size;
				size_type i = 0;
				for (const_iterator it = x.begin(); it != x.end(); it++)
					_alloc.construct(_node + i++, *it);
				return (*this);
			};

			/**
			 * @brief Return iterator to beginning
			 * Returns an iterator pointing to the first element in the vector.
			 */
			iterator begin() {return (iterator(_node)); };

			/**
			 * @brief Return iterator to beginning
			 * Returns an iterator pointing to the first element in the vector.
			 */
			const_iterator begin() const {return (const_iterator(_node)); };

			/**
			 * @brief Return iterator to end
			 * Returns an iterator referring to the past-the-end element
			 * in the vector container.
			 * If the container is empty, this function returns the same as vector::begin.
			 */
			iterator end() {return (iterator(_node + _size)); };

			/**
			 * @brief Return iterator to end
			 * Returns an iterator referring to the past-the-end element
			 * in the vector container.
			 * If the container is empty, this function returns the same as vector::begin.
			 */
			const_iterator end() const {return (const_iterator(_node + _size)); };

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
			const_reverse_iterator rbegin() const {return (const_reverse_iterator(this->end())); };

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
			const_reverse_iterator rend() const {return (const_reverse_iterator(this->begin())); };

			/**
			 * @brief Return size
			 * Returns the number of elements in the vector.
			 */
			size_type size() const {return (this->_size); };

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
				if (n >= _size)
				{
					if (n > _capacity)
						realloc(n + 5);
					this->insert(this->end(), n - _size, val);
				}
				else
					this->erase(this->begin() + n, this->end());
			};

			/**
			 * @brief Return size of allocated storage capacity
			 * Returns the size of the storage space currently allocated for the vector,
			 * expressed in terms of elements.
			 */
			size_type capacity() const {return (this->_capacity); };

			/**
			 * @brief Test whether vector is empty
			 * Returns whether the vector is empty (i.e. whether its size is 0).
			 * This function does not modify the container in any way.
			 * To clear the content of a vector, see vector::clear.
			 * 
			 * @return true if the container size is 0, false otherwise.
			 */
			bool empty() const {return (this->size() == 0); };

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
				if (n > _capacity)
					realloc(n);
			};

			/**
			 * @brief Access element
			 * Returns a reference to the element at position n in the vector container.
			 * 
			 * @param n
			 * Position of an element in the container.
			 * Notice that the first element has a position of 0 (not 1).
			 */
			reference operator[] (size_type n) {return (*(_node + n)); };

			/**
			 * @brief Access element
			 * Returns a reference to the element at position n in the vector container.
			 * 
			 * @param n
			 * Position of an element in the container.
			 * Notice that the first element has a position of 0 (not 1).
			 */
			const_reference operator[] (size_type n) const {return (*(_node + n)); };

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
				if (n < 0 || this->size() <= n)
					throw (std::out_of_range("ft::vector"));
				return (*(_node + n));
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
			const_reference at(size_type n) const
			{
				if (n < 0 || this->size() <= n)
					throw (std::out_of_range("ft::vector"));
				return (*(_node + n));
			};

			/**
			 * @brief Access first element
			 * Returns a reference to the first element in the vector.
			 */
			reference front() {return (*(this->begin())); };

			/**
			 * @brief Access first element
			 * Returns a reference to the first element in the vector.
			 */
			const_reference front() const {return (*(this->begin())); };

			/**
			 * @brief Access last element
			 * Returns a reference to the last element in the vector.
			 */
			reference back()
			{
				if (this->size() == 0)
					return (*_node);
				return (*(this->end() - 1));
			};

			/**
			 * @brief Access last element
			 * Returns a reference to the last element in the vector.
			 */
			const_reference back() const
			{
				if (this->size() == 0)
					return (*_node);
				return (*(this->end() - 1));
			};

			/**
			 * @brief Assign vector content
			 * range (1)
			 * Assigns new contents to the vector, replacing its current contents,
			 * and modifying its size accordingly.
			 * 
			 * @tparam InputIterator
			 * @param first the first element in the range.
			 * @param last the last element in the range.
			 */
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = u_nullptr)
			{
				size_type n = 0;
				for (InputIterator it = first; it != last; it++)
					n++;
				this->clear();
				this->reserve(n);
				size_type i = 0;
				for (InputIterator it = first; it != last; it++)
					_alloc.construct(_node + i++, *it);
				_size = n;
			};

			/**
			 * @brief Assign vector content
			 * fill (2)
			 * Assigns new contents to the vector, replacing its current contents,
			 * and modifying its size accordingly.
			 * 
			 * @param n New size for the container.
			 * @param val Value to fill the container with.
			 * Each of the n elements in the container will be initialized to a copy of this value.
			 */
			void assign (size_type n, const value_type& val)
			{
				this->clear();
				this->reserve(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_node + i, val);
				_size = n;
			};

			/**
			 * @brief Add element at the end
			 * Adds a new element at the end of the vector, after its current last element.
			 * The content of val is copied (or moved) to the new element.
			 * 
			 * @param val Value to be copied (or moved) to the new element.
			 */
			void push_back (const value_type& val) { insert(this->end(), val); };

			/**
			 * @brief Delete last element
			 * Removes the last element in the vector,
			 * effectively reducing the container size by one.
			 * This destroys the removed element.
			 */
			void pop_back() {erase(--(this->end())); };

			/**
			 * @brief Insert elements
			 * single element (1)
			 * The vector is extended by inserting new elements before the element at the specified position,
			 * effectively increasing the container size by the number of elements inserted.
			 * 
			 * @param position Position in the vector where the new elements are inserted.
			 * @param val Value to be copied (or moved) to the inserted elements.
			 */
			iterator insert (iterator position, const value_type& val)
			{
				size_type locate = position - this->begin();
				if (_size + 1 > _capacity)
					reserve(std::max(_size * 2, _size + 1));
				position = this->begin() + locate;
				insert(position, 1, val);
				return (position);
			};

			/**
			 * @brief Insert elements
			 * fill (2)	
			 * The vector is extended by inserting new elements before the element at the specified position,
			 * effectively increasing the container size by the number of elements inserted.
			 * 
			 * @param position Position in the vector where the new elements are inserted.
			 * @param n Number of elements to insert. Each element is initialized to a copy of val.
			 * @param val Value to be copied (or moved) to the inserted elements.
			 */
			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type locate = position - this->begin();
				if (n == 0 || locate < 0)
					return ;
				if (_size + n > _capacity)
					reserve(std::max(_size * 2, _size + n));
				position = this->begin() + locate;
				if (!this->empty())
				{
					for (size_type i = _size; i > locate; i--)
					{
						_alloc.construct(_node + i + n - 1, _node[i - 1]);
						_alloc.destroy(_node + i - 1);
					}
				}
				for (size_type i = locate; i < locate + n; i++)
					_alloc.construct(_node + i, val);
				_size += n;
			};

			/**
			 * @brief Insert elements
			 * range (3)
			 * The vector is extended by inserting new elements before the element at the specified position,
			 * effectively increasing the container size by the number of elements inserted.
			 * 
			 * @param position Position in the vector where the new elements are inserted.
			 * @param first the first element in the range.
			 * @param last the last element in the range.
			 */
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = u_nullptr)
			{
				size_type n = ft::difference(first, last);
				size_type position_idx = position - this->begin();
				size_type locate_count = this->end() - position;
				size_type locate_back = this->size() + n - 1;
				
				this->resize(this->_size + n);
				for (size_type i = 0; i < locate_count; i++)
					this->push(locate_back - i, (*this)[locate_back - n - i]);
				while (first != last)
					this->push(position_idx++, *first++);
			};

			/**
			 * @brief Erase elements
			 * Removes from the vector either a single element (position)
			 * or a range of elements ([first,last)).
			 * 
			 * @param position Iterator pointing to a single element to be removed from the vector.
			 */
			iterator erase (iterator position)
			{
				return (this->erase(position, position + 1));
			};

			/**
			 * @brief Erase elements
			 * Removes from the vector either a single element (position)
			 * or a range of elements ([first,last)).
			 * 
			 * @param first the first element in the range.
			 * @param last the last element in the range.
			 */
			iterator erase (iterator first, iterator last)
			{
				if (this->empty() || last == this->end())
					return (this->end());
				if (last <= first)
					return (last);
				difference_type dist = last - first;
				for (iterator it = first; it != last; it++)//구간 할당 해제
					_alloc.destroy(it.operator->());
				for (iterator it = last; it != end(); it++)//비어있는 구간 채워넣으면서 뒤쪽 할당 해제
				{
					_alloc.construct((it - dist).operator->(), *it);
					_alloc.destroy(it.operator->());
				}
				_size -= dist;
				return (first);
			};

			/**
			 * @brief Swap content
			 * Exchanges the content of the container by the content of x,
			 * which is another vector object of the same type. Sizes may differ.
			 * 
			 * @param x Another vector container of the same type 
			 * (i.e., instantiated with the same template parameters, T and Alloc)
			 * whose content is swapped with that of this container.
			 */
			void swap (vector& x)
			{
				if (x == *this)
					return ;
				ft::swap(this->_alloc, x._alloc);
				ft::swap(this->_node, x._node);
				ft::swap(this->_size, x._size);
				ft::swap(this->_capacity, x._capacity);
			};

			/**
			 * @brief Clear content
			 * Removes all elements from the vector (which are destroyed),
			 * leaving the container with a size of 0.
			 */
			void clear ()
			{
				this->erase(this->begin(), this->end());
				_size = 0;
			};

			/**
			 * @brief Get allocator
			 * Returns a copy of the allocator object associated with the vector.
			 */
			allocator_type get_allocator() const {return (this->_alloc); };
	};

	/**
	 * @brief Relational operators for vector
	 * Performs the appropriate comparison operation between the vector containers lhs and rhs.
	 * 
	 * The equality comparison (operator==) is performed by first comparing sizes, 
	 * and if they match, the elements are compared sequentially using operator==, 
	 * stopping at the first mismatch (as if using algorithm equal).
	 * ->
	 * 상등 비교는 요소의 개수와 모든 요소의 값이 일치할 때 같은 것으로 판단한다. 
	 * 벡터가 생성되어 있는 메모리 위치나 추가로 할당되어 있는 여유분은 벡터의 실제 내용이 아니므로 상등 비교의 대상이 아니다.
	 * 들어 있는 내용만 같다면 같은 벡터로 취급된다.
	 */
	template <class T, class Alloc>
  	bool operator== (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};

	template <class T, class Alloc>
 	bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	};

	/**
	 * @brief Relational operators for vector
	 * Performs the appropriate comparison operation between the vector containers lhs and rhs.
	 * 
	 * The less-than comparison (operator<) behaves as if using algorithm lexicographical_compare,
	 * which compares the elements sequentially using operator< in a reciprocal manner
	 * (i.e., checking both a<b and b<a) and stopping at the first occurrence.
	 * ->
	 * 대소를 비교할 때는 대응되는 각 요소들을 일대일로 비교하다가
	 * 최초로 다른 요소가 발견되었을 때 두 요소의 대소를 비교한 결과를 리턴한다. 
	 * 만약 한쪽 벡터의 길이가 더 짧아 먼저 끝을 만났다면 아직 끝나지 않은 벡터가 더 큰 것으로 판별한다.
	 * 이런 식으로 비교하는 것을 사전식 비교라고 하는데 상식과도 일치한다.
	 */
	template <class T, class Alloc>
	bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template <class T, class Alloc>
	bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	};

	template <class T, class Alloc>
	bool operator>  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (rhs < lhs);
	};

	template <class T, class Alloc>
	bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	};

	/**
	 * @brief Exchange contents of vectors
	 * The contents of container x are exchanged with those of y.
	 * Both container objects must be of the same type (same template parameters),
	 * although sizes may differ.
	 */
	template <class T, class Alloc>
	void swap (vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
		x.swap(y);
	};
}//namespace ft

#endif