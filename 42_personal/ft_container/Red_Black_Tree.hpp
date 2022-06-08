/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Red_Black_Tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:12:38 by sna               #+#    #+#             */
/*   Updated: 2022/06/08 19:56:43 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <memory>

# include "util.hpp"
# include "iterator.hpp"
# include "tree_iterator.hpp"
# include "type_trait.hpp"

namespace ft{
	template <class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
	class Red_Black_Tree {
		public:
			typedef T													value_type;
			typedef Compare												value_compare;
			typedef Alloc												allocator_type;

			typedef typename Alloc::template rebind<Node<T> >::other	node_allocator;
			typedef typename node_allocator::pointer					node_pointer;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef std::ptrdiff_t										difference_type;
			typedef std::size_t											size_type;
			typedef ft::tree_iterator<T>								iterator;
			typedef ft::tree_iterator<const T>							const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		
		private:
			allocator_type			_val_alloc;
			node_allocator			_node_alloc;
			value_compare			_compare;
			node_pointer			_nil;
			node_pointer			_header;
			node_pointer			_root;
			size_type				_size;

			bool is_nil(node_pointer node) const {
				return (node == _nil || node == _header);
			};
			
			node_pointer tree_min(node_pointer n) const {
				while (n != ft::u_nullptr && !is_nil(n->left))
					n = n->left;
				return (n);
			};

			node_pointer tree_max(node_pointer n) const {
				while (n != ft::u_nullptr && !is_nil(n->right))
					n = n->right;
				return (n);
			};

			void rotate_right(node_pointer node) {
				node_pointer y;

				y = node->left;
				node->left = y->right;
				if (!is_nil(y->right))
					y->right->parent = node;
				y->parent = node->parent;
				if (node->parent == ft::u_nullptr)
					_root = y;
				else if (node == node->parent->left)
					node->parent->left = y;
				else
					node->parent->right = y;
				y->right = node;
				node->parent = y;
			};

			void rotate_left(node_pointer node) {
				node_pointer y;

				y = node->right;
				node->right = y->left;
				if (!is_nil(y->left))
					y->left->parent = node;
				y->parent = node->parent;
				if (node->parent == ft::u_nullptr)
					_root = y;
				else if (node == node->parent->left)
					node->parent->left = y;
				else
					node->parent->right = y;
				y->left = node;
				node->parent = y;
			};

			node_pointer insert(node_pointer new_node) {
				if (_root == _header)
					_root = new_node;
				else
					insert_to_node(_root, new_node);
				return (new_node);
			};

			node_pointer insert_to_node(node_pointer root, node_pointer new_node) {
				if (_compare(*new_node->value, *root->value))
				{
					if (!is_nil(root->left))
						return (insert_to_node(root->left, new_node));
					root->left = new_node;
				}
				else
				{
					if (!is_nil(root->right))
						return (insert_to_node(root->right, new_node));
					root->right = new_node;
				}
				new_node->parent = root;
				return (new_node);
			};

			node_pointer insert_into_tree(node_pointer new_node, node_pointer where) {
				if (_root == _header)
					_root = new_node;
				else
					insert_to_node(where, new_node);
				return (new_node);
			};

			void insert_fixup(node_pointer node) {
				if (node != _root && node->parent != _root)
				{
					while (node != _root && !node->parent->is_black)
					{
						if (node->parent == node->parent->parent->left)
						{
							node_pointer uncle = node->parent->parent->right;
							if (!uncle->is_black)
							{
								node->parent->is_black = true;
								uncle->is_black = true;
								node->parent->parent->is_black = false;
								node = node->parent->parent;
							}
							else
							{
								if (node == node->parent->right)
								{
									node = node->parent;
									rotate_left(node);
								}
								node->parent->is_black = true;
								node->parent->parent->is_black = false;
								rotate_right(node);
							}
						}
						else
						{
							node_pointer uncle = node->parent->parent->left;
							if (!uncle->is_black)
							{
								node->parent->is_black = true;
								uncle->is_black = true;
								node->parent->parent->is_black = false;
								node = node->parent->parent;
							}
							else
							{
								if (node == node->parent->left)
								{
									node = node->parent;
									rotate_right(node);
								}
								node->parent->is_black = true;
								node->parent->parent->is_black = false;
								rotate_left(node->parent->parent);
							}
						}
					}
				}
				_root->is_black = true;
			};

			void clear_node(node_pointer node) {
				if (node && !is_nil(node))
				{
					clear_node(node->left);
					clear_node(node->right);
					_val_alloc.destroy(node->value);
					_val_alloc.deallocate(node->value, 1);
					_node_alloc.deallocate(node, 1);
				}
			};

			void init_nil_head() {
				_nil = _node_alloc.allocate(1);
				_node_alloc.construct(_nil, Node<T>());
				_nil->is_black = true;
				_nil->is_nil = true;
				_header = _node_alloc.allocate(1);
				_node_alloc.construct(_header, Node<T>());
				_header->value = _val_alloc.allocate(1);
				_val_alloc.construct(_header->value, T());
				_header->is_black = true;
			};

			void transplate(node_pointer where, node_pointer what) {
				if (where == _root)
					_root = what;
				else if (where == where->parent->left)
					where->parent->left = what;
				else
					where->parent->right = what;
				what->parent = where->parent;
			};

			void free_node(node_pointer node) {
				_val_alloc.destroy(node->value);
				_val_alloc.deallocate(node->value, 1);
				_node_alloc.deallocate(node, 1);
			};
		
		public:
			iterator begin() {
				if (_size == 0)
					return (iterator(_header));
				else
					return (iterator(tree_min(_root)));
			};

			const_iterator begin() const {
				if (_size == 0)
					return (const_iterator(_header));
				else
					return (const_iterator(tree_min(_root)));	
			};

			iterator end() {
				return (iterator(_header));
			};

			const_iterator end() const {
				return (const_iterator(_header));
			};

			reverse_iterator rbegin() {
				return (reverse_iterator(end()));
			};

			const_reverse_iterator rend() {
				return (const_reverse_iterator(end()));
			};

			reverse_iterator rend() {
				return (reverse_iterator(begin()));
			};

			const_reverse_iterator rend() {
				return (const_reverse_iterator(begin()));
			};

			pointer create_value(const value_type& value) {
				pointer new_value = _val_alloc.allocate(1);
				_val_alloc.construct(new_value, value);
				return (new_value);
			};

			node_pointer copy_node(node_pointer other) {
				node_pointer new_node = _node_alloc.allocate(1);
				_node_alloc.construct(new_node, Node<T>());
				new_node->is_black = other->is_black;
				new_node->is_nil = other->is_nil;
				if (other->value)
				{
					new_node->value = _val_alloc.allocate(1);
					_val_alloc.construct(new_node->value, *other->value);
				}
				return (new_node);
			};

			/**
			 * @brief 내 노드와 복사받을 노드를 입력받아
			 * 재귀적으로 노드의 값을 복사해옴
			 */
			void copy_child(node_pointer my_node, node_pointer other) {
				if (other->left->is_nil)
					my_node->left = _nil;
				else
				{
					my_node->left = copy_node(other->left);
					my_node->left->patent = my_node;
					copy_child(my_node->left, other->left);
				}
				if (other->right->is_nil)
					my_node->right = _nil;
				else if (other->right->right == ft::u_nullptr)
				{
					my_node->right = _header;
					_header->parent = my_node;
				}
				else
				{
					my_node->right = copy_node(other->right);
					my_node->right->parent = my_node;
					copy_child(my_node->right, other->right);
				}
			};

			node_pointer search(const value_type& value, node_pointer node) const {
				if (!node || is_nil(node))
					return (ft::u_nullptr);
				if (_compare(value, *node->value))//찾으려는 수가 현재노드보다 작으면
					return (search(value, node->left));//왼쪽노드로 탐색
				if (_compare(*node->value, value))//반대의 경우
					return (search(value, node->right));//오른쪽노드로 탐색
				return (node);
			};

			iterator find(const value_type& value) {
				node_pointer find_result = search(value, _root);
				if (find_result == ft::u_nullptr)
					return (end());
				else
					return (iterator(find_result));
			};

			const_iterator find(const value_type& value) const {
				node_pointer find_result = search(value, _root);
				if (find_result == ft::u_nullptr)
					return (end());
				else
					return (const_iterator(find_result));
			};

			ft::pair<iterator, bool> insert(const value_type& value) {
				node_pointer find_value = search(value, _root);
				if (find_value)//이미 있으면 추가안됨
					return (ft::pair<iterator, bool>(iterator(find_value), false));
				node_pointer new_node = _node_alloc.allocate(1);
				_node_alloc.construct(new_node, Node<value_type>(create_value(value)));
				new_node->left = _nil;
				new_node->right = _nil;
				insert_into_tree(new_node, _root);
				ft::pair<iterator, bool> res(iterator(new_node), true);
				insert_fixup(new_node);
				_size++;
				new_node = tree_max(_root);
				new_node->right = _header;
				_header->parent = new_node;
				return (res);
			};

			iterator insert(iterator position, const value_type& value) {
				node_pointer new_node = search(value, _root);
				if (new_node)
					return (iterator(new_node));
				new_node = _node_alloc.allocate(1);
				_node_alloc.construct(new_node, Node<value_type>(create_value(value)));
				new_node->left = _nil;
				new_node->right = _nil;
				if (position == begin())
				{
					if (position != end() && _compare(value, *position))
						insert_into_tree(new_node, tree_min(_root));
					else
						insert_into_tree(new_node, _root);
				}
				else if (position == end())
				{
					if (position != begin() && _compare(*(--position), value))
						insert_into_tree(new_node, _header->parent);
					else
						insert_into_tree(new_node, _root);
				}
				else
					insert_into_tree(new_node, _root);
				insert_fixup(new_node);
				_size++;
				node_pointer max_of_tree = tree_max(_root);
				max_of_tree->right = _header;
				_header->parent = max_of_tree;
				return (iterator(new_node));
			};

			template <class InputIterator>
			void insert(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator >::type first
						, InputIterator last) {
				for (; first != last; ++first)
					insert(*first);
			};

			void erase(iterator pos) {
				node_pointer y = pos.node();
				node_pointer x;
				node_pointer for_free = y;
				bool y_original_is_black = y->is_black;

				if (is_nil(y->left))
				{
					x = y->right;
					transplate(y, y->right);
				}
				else if (is_nil(y->right))
				{
					x = y->left;
					transplate(y, y->left);
				}
				else
				{
					node_pointer z = y;
					y = tree_min(z->right);
					y_original_is_black = y->is_black;
					x = y->right;
					if (y->parent != z)
					{
						transplate(y, y->right);
						y->right = z->right;
						z->right->parent = y;
					}
					transplate(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->is_black = z->is_black;
				}
				free_node(for_free);
				if (y_original_is_black)
					erase_fixup(x);
				_size--;
				_nil->parent = ft::u_nullptr;
				if (_size == 0)
					_root = _header;
				else
				{
					if (_size != 1)
						x = tree_max(_root);
					else
						x = _root;
					x->right = _header;
					_header->parent = x;
				}
			};

			size_type erase(const value_type& value) {
				node_pointer result = search(value, _root);
				if (result)
					erase(iterator(result));
				return (result != ft:u_nullptr);
			};

			void erase(iterator first, iterator last) {
				while (first != last)
					erase(first++);
			};

			void erase_fixup(node_pointer x) {
				node_pointer brother;

				while (x != _root && x->is_black)
				{
					if (x == x->parent->left)
					{
						brother = x->parent->right;
						//case 1
						if (!brother->is_black)
						{
							brother->is_black = true;
							x->parent->is_black = false;
							rotate_left(x->parent);
							brother = x->parent->right;
						}
						//case 2
						if (brother->left->is_black && brother->right->is_black)
						{
							brother->is_black = false;
							x = x->parent;
						}
						else //case 3
						{
							if (brother->right->is_black)
							{
								brother->left->is_black = true;
								brother->is_black = false;
								rotate_right(brother);
								brother = x->parent->right;
							}
							//case 4
							brother->is_black = x->parent->is_black;
							x->parent->is_black = true;
							brother->right->is_black = true;
							rotate_left(x->parent);
							x = _root;
						}
					}
					else
					{
						brother = x->parent->left;
						//case 1
						if (!brother->is_black)
						{
							brother->is_black = true;
							x->parent->is_black = false;
							rotate_right(x->parent);
							brother = x->parent->left;
						}
						//case 2
						if (brother->right->is_black && brother->left->is_black)
						{
							brother->is_black = false;
							x = x->parent;
						}
						else //case 3
						{
							if (brother->left->is_black)
							{
								brother->right->is_black = true;
								brother->is_black = false;
								rotate_left(brother);
								brother = x->parent->left;
							}
							//case 4
							brother->is_black = x->parent->is_black;
							x->parent->is_black = true;
							brother->left->is_black = true;
							rotate_right(x->parent);
							x = _root;
						}
					}
				}
			};

			Red_Black_Tree(const Compare& comp, const allocator_type& a = allocator_type())
				: _val_alloc(a), _node_alloc(node_allocator()), _compare(comp), _root(0), _size(0)
			{
				init_nil_head();
				_root = _header;
			};

			Red_Black_Tree()
				: _val_alloc(allocator_type()), _node_alloc(node_allocator()), _compare(value_compare()), _root(0), _size(0)
			{
				init_nil_head();
				_root = _header;
			};

			Red_Black_Tree(const Red_Black_Tree& src)
				: _compare(src._compare), _root(ft::u_nullptr)
			{
				*this = src;
			};

			template <class InputIterator>
			Red_Black_Tree(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator >::type first,
							InputIterator last, const value_compare& comp, const allocator_type& a = allocator_type())
				: _val_alloc(a), _node_alloc(node_allocator()), _compare(comp)
			{
				init_nil_head();
				_root = _header;
				for (; first != last; first++)
					insert(*first);
			};

			Red_Black_Tree& operator=(const Red_Black_Tree& src)
			{
				if (*this == src)
					return (*this);
				this->_node_alloc = src._node_alloc;
				this->_val_alloc = src._val_alloc;
				this->_compare = src._compare;
				if (this->_root == ft::u_nullptr)
					init_nil_head();
				else
					clear_node(_root);
				if (src._size == 0)
					this->_root = this->_header;
				else
				{
					this->_root = copy_node(src._root);
					copy_child(this->_root, src._root);
				}
				this->_size = src._size;
				return (*this);
			};

			~Red_Black_Tree()
			{
				clear_node(_root);
				_val_alloc.destroy(_header->value);
				_val_alloc.deallocate(_header->value, 1);
				_node_alloc.deallocate(_nil, 1);
				_node_alloc.deallocate(_header, 1);
			};

			size_type size() const {
				return (_size);
			};

			size_type max_size() const {
				return (_val_alloc.max_size());
			};

			bool empty() const {
				return (_size == 0);
			};

			value_compare value_comp() const {
				return (_compare);
			};

			void clear() {
				clear_node(_root);
				_root = _header;
				_header->parent = ft::u_nullptr;
				_size = 0;
			};

			size_type count(const value_type& value) const {
				return (find(value) != end());
			};

			iterator lower_bound(const value_type& value) {
				iterator last = end();
				for (iterator first = begin(); first != last; first++)
				{
					if (!_compare(*first, value))
						return (first);
				}
				return (last);
			};

			const_iterator lower_bound(const value_type& value) {
				const_iterator last = end();
				for (const_iterator first = begin(); first != last; first++)
				{
					if (!_compare(*first, value))
						return (first);
				}
				return (last);
			};

			iterator upper_bound(const value_type& value) {
				iterator last = end();
				for (iterator first = begin(); first != last; first++)
				{
					if (_compare(value, *first))
						return (first);
				}
				return (last);
			};

			const_iterator upper_bound(const value_type& value) {
				const_iterator last = end();
				for (const_iterator first = begin(); first != last; first++)
				{
					if (_compare(value, *first))
						return (first);
				}
				return (last);
			};

			void swap(Red_Black_Tree& other) {
				if (*this == other)
					return ;
				allocator_type	temp_val_alloc = other._val_alloc;
				node_allocator	temp_node_alloc = other._node_alloc;
				value_compare	temp_compare = other._compare;
				node_pointer	temp_nil = other._nil;
				node_pointer	temp_header = other._header;
				node_pointer	temp_root = other._root;
				size_type		temp_size = other._size;

				other._val_alloc = this->_val_alloc;
				other._node_alloc = this->_node_alloc;
				other._compare = this->_compare;
				other._nil = this->_nil;
				other._header = this->_header;
				other._root = this->_root;
				other._size = this->_size;

				this->_val_alloc = temp_val_alloc;
				this->_node_alloc = temp_node_alloc;
				this->_compare = temp_compare;
				this->_nil = temp_nil;
				this->_header = temp_header;
				this->_root = temp_root;
				this->_size = temp_size;
			};

			ft::pair<iterator, iterator> equal_range(const value_type& value) {
				return (ft::make_pair(lower_bound(value), upper_bound(value)));
			};

			allocator_type get_allocator() const {
				return (_val_alloc);
			};
	};

	template<class Content, class Compare, class Alloc>
	bool operator<(const Red_Black_Tree<Content, Compare, Alloc>& lhs, const Red_Black_Tree<Content, Compare, Alloc>& rhs){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class Content, class Compare, class Alloc>
	bool operator>(const Red_Black_Tree<Content, Compare, Alloc>& lhs, const Red_Black_Tree<Content, Compare, Alloc>& rhs){
		return (lhs < rhs);
	}

	template<class Content, class Compare, class Alloc>
	bool operator==(const Red_Black_Tree<Content, Compare, Alloc>& lhs, const Red_Black_Tree<Content, Compare, Alloc>& rhs){
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<class Content, class Compare, class Alloc>
	void swap(const Red_Black_Tree<Content, Compare, Alloc>& lhs, const Red_Black_Tree<Content, Compare, Alloc>& rhs){
		lhs.swap(rhs);
	}
}//namespace ft

#endif