/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_node.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:20:10 by sna               #+#    #+#             */
/*   Updated: 2022/06/22 13:59:23 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_NODE_HPP
# define RBTREE_NODE_HPP

# include <memory>

namespace ft {
	enum rb_color
	{
		RED,
		BLACK
	};

	template <typename T, typename Alloc = std::allocator<T> >
	struct rb_node
	{
		public:
			T			*value;
			rb_node		*left;
			rb_node		*right;
			rb_node		*parent;
			rb_color	color;
			Alloc		alloc;

			rb_node()
				: value(NULL), left(NULL), right(NULL), parent(NULL), color(BLACK), alloc(Alloc())
			{};

			rb_node(const T& val)
				: value(NULL), left(NULL), right(NULL), parent(NULL), color(RED), alloc(Alloc())
			{
				this->value = alloc.allocate(1);
				alloc.construct(this->value, val);
			};

			rb_node(const rb_node& obj)
				: value(NULL), left(NULL), right(NULL), parent(NULL), color(RED), alloc(Alloc())
			{
				if (!(obj.value == NULL))
				{
					this->value = alloc.allocate(1);
					alloc.construct(this->value, obj.get_value());
				}
			};

			~rb_node()
			{
				if (this->value != NULL)
				{
					alloc.destroy(this->value);
					alloc.deallocate(this->value, 1);
				}
			};

			T& get_value() const
			{
				return (*this->value);
			};

			bool empty() const
			{
				if (this->value == NULL)
					return (true);
				return (false);
			};

			bool is_root() const
			{
				if (this->parent->empty())
					return (true);
				return (false);
			};

			bool is_left() const
			{
				if (this->parent->left == this)
					return (true);
				else
					return (false);
			};

			bool is_right() const
			{
				if (this->parent->right == this)
					return (true);
				else
					return (false);
			};

			bool is_leaf() const
			{
				if (this->left->empty() && this->right->empty())
					return (true);
				return (false);
			};

			rb_node* sibling()//형제 노드
			{
				if (this == this->parent->left)//현재 자신이 왼쪽이라면
					return (this->parent->right);//형제 노드는 오른쪽
				else//자신이 오른쪽이면
					return (this->parent->left);//형제 노드는 왼쪽
			};

			bool operator<(const rb_node& obj) const
			{
				return (*(this->value) < *obj.value);
			};

			bool operator>(const rb_node& obj) const
			{
				return (*this > obj);
			};

			bool operator==(const rb_node& obj) const
			{
				return (*(this->value) == *obj.value);
			};
	};
}//namespace ft

#endif