/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:15:38 by sna               #+#    #+#             */
/*   Updated: 2022/06/22 18:23:53 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>

# include "RBTree_node.hpp"
# include "RBTree_iterator.hpp"
/*
** Red-Black-tree 규칙
** 1. 루트(_root) 노드는 블랙.
** 2. 노드 색은 레드 아니면 블랙.
** 3. 모든 외부 노드(External Node)는 블랙.
** 4. 모든 외부 노드의 경우 루트(_root)부터 외부 노드까지 방문하는 블랙 노드의 수가 같다.
** 5. 레드 노드는 두 개가 연속해서 등장할 수 없다.
*/
namespace ft {
	template <typename T, typename Compare = ft::less<T>, typename Alloc = std::allocator<T> >
	class RBTree
	{
		public:
			typedef T																	value_type;
			typedef Compare																comp_type;
			typedef Alloc																allocator_type;
			typedef ft::rb_node<value_type>												node_type;
			typedef typename Alloc::template rebind<node_type>::other 					node_allocator_type;
			typedef RBTree_iterator<value_type, value_type*, value_type&>				iterator;
			typedef RBTree_iterator<value_type, const value_type*, const value_type&>	const_iterator;

		private:
			node_type				*_root;
			node_type				*_nil;
			size_t					_size;
			comp_type				_comp;
			node_allocator_type		_node_alloc;

			node_type* construct_node()
			{
				node_type* result = this->_node_alloc.allocate(1);
				this->_node_alloc.construct(result, node_type());
				return (result);
			};
			
			node_type* construct_node(const value_type& val)
			{
				node_type* result = this->_node_alloc.allocate(1);
				this->_node_alloc.construct(result, node_type(val));
				return (result);
			};

			void destroy_node(node_type* node)
			{
				this->_node_alloc.destroy(node);
				this->_node_alloc.deallocate(node, 1);
			};

			bool same_value(const value_type &a, const value_type &b) const
			{
				return (!_comp(a, b) && !_comp(b, a));
			};

			bool empty() const
			{
				return (this->_root == this->_nil);
			};

			void swap_target(node_type* target)
			{
				node_type *node;
				if (target->left != this->_nil)
					node = get_left_biggest_node(target->left);
				else
					node = get_right_smallest_node(target->right);
				if (node->parent == target)
					swap_one_depth(target, node);
				else //노드가 타겟에서 2depth 이상 떨어져 있을 경우.
					swap_over_one_depth(target, node);
			};

			void swap_over_one_depth(node_type *&high, node_type *&low)
			{
				node_type *temp_l = high->left;
				node_type *temp_r = high->right;
				node_type *temp_p = high->parent;

				//high를 low 위치로 이동
				high->parent = low->parent;
				if (low->is_left())
					low->parent->left = high;
				else
					low->parent->right = high;
				high->left = low->left;
				if (!low->left->empty())
					low->left->parent = high;
				high->right = low->right;
				if (!low->right->empty())
					low->right->parent = high;

				//low를 high 위치로 이동
				low->parent = temp_p;
				if (temp_p->left == high)
					temp_p->left = low;
				else if (temp_p->right == high)
					temp_p->right = low;
				low->left = temp_l;
				if (!temp_l->empty())
					temp_l->parent = low;
				low->right = temp_r;
				if (!temp_r->empty())
					temp_r->parent = low;
				//색 바꾸기
				swap_color(high->color, low->color);
				//치환한게 루트이면 루트 바꿔주기
				if (low->parent->empty())
					this->_root = low;
			};

			void swap_one_depth(node_type *&p, node_type *&c)
			{
				node_type *temp_p = p->parent;
				node_type *temp_l = p->left;
				node_type *temp_r = p->right;

				if (c->sibling() != this->_nil)
					c->sibling()->parent = c;
				if (c->is_left())
					temp_l = p;
				else
					temp_r = p;

				if (p->is_left())
					p->parent->left = c;
				else if (p->is_right())
					p->parent->right = c;
				p->parent = c;
				p->left = c->left;
				if (!p->left->empty())
					p->left->parent = p;
				p->right = c->right;
				if (!p->right->empty())
					p->right->parent = p;

				c->parent = temp_p;
				c->left = temp_l;
				c->right = temp_r;
				swap_color(p->color, c->color);
				if (c->parent->empty())
					this->_root = c;
			};

			void rotate_left(node_type *&pt)
			{
				node_type *pt_right = pt->right;

				pt->right = pt_right->left;
				if (pt->right != this->_nil)
					pt->right->parent = pt;

				pt_right->parent = pt->parent;
				if (pt->parent == this->_nil)
					this->_root = pt_right;
				else if (pt == pt->parent->left)
					pt->parent->left = pt_right;
				else
					pt->parent->right = pt_right;
				pt_right->left = pt;
				pt->parent = pt_right;
			};

			void rotate_right(node_type *pt)
			{
				node_type *pt_left = pt->left;

				pt->left = pt_left->right;
				if (pt->left != this->_nil)
					pt->left->parent = pt;

				pt_left->parent = pt->parent;
				if (pt->parent == this->_nil)
					this->_root = pt_left;
				else if (pt == pt->parent->left)
					pt->parent->left = pt_left;
				else
					pt->parent->right = pt_left;

				pt_left->right = pt;
				pt->parent = pt_left;
			};

			void swap_color(rb_color &a, rb_color &b)
			{
				rb_color temp;
				temp = a;
				a = b;
				b = temp;
			};

			void delete_root()
			{
				this->destroy_node(this->_root);
				this->_root = this->_nil;
				--this->_size;
				this->_nil->parent = this->get_biggest();
			};

			//insert후 틀어진 rb_tree 규칙에 맞게 노드 조정
			void fix_violation(node_type *current)
			{
				node_type *parent_pt = this->_nil;
				node_type *grand_parent_pt = this->_nil;

				while ((current != this->_root) && (current->color != BLACK)
						&& (current->parent->color == RED))
				{
					parent_pt = current->parent;
					grand_parent_pt = current->parent->parent;

					/*  Case : A
						Parent of pt is left child
						of Grand-parent of pt */
					if (parent_pt == grand_parent_pt->left)
					{
						node_type *uncle_pt = grand_parent_pt->right;
						/* Case : 1
							The uncle of pt is also red
							Only Recoloring required */
						if (uncle_pt != this->_nil && uncle_pt->color == RED)
						{
							grand_parent_pt->color = RED;
							parent_pt->color = BLACK;
							uncle_pt->color = BLACK;
							current = grand_parent_pt;
						}
						else
						{
							/* Case : 2
								current is right child of its parent
								Left-rotation required */
							if (current == parent_pt->right)
							{
								this->rotate_left(parent_pt);
								current = parent_pt;
								parent_pt = current->parent;
							}

							/* Case : 3
								current is left child of its parent
								Right-rotation required */
							this->rotate_right(grand_parent_pt);
							swap_color(parent_pt->color,
										grand_parent_pt->color);
							current = parent_pt;
						}
					}
					/* Case : B
						Parent of current is right child
						of Grand-parent of current */
					else
					{
						node_type *uncle_pt = grand_parent_pt->left;

						/*  Case : 1
							The uncle of current is also red
							Only Recoloring required */
						if ((uncle_pt != this->_nil) && (uncle_pt->color == RED))
						{
							grand_parent_pt->color = RED;
							parent_pt->color = BLACK;
							uncle_pt->color = BLACK;
							current = grand_parent_pt;
						}
						else
						{
							/* Case : 2
								current is left child of its parent
								Right-rotation required */
							if (current == parent_pt->left)
							{
								this->rotate_right(parent_pt);
								current = parent_pt;
								parent_pt = current->parent;
							}
							/* Case : 3
								current is right child of its parent
								Left-rotation required */
							this->rotate_left(grand_parent_pt);
							this->swap_color(parent_pt->color,
										grand_parent_pt->color);
							current = parent_pt;
						}
					}
				}
				this->_root->color = BLACK;
			};

			node_type *get_left_biggest_node(node_type *left)
			{
				while (left->right != this->_nil)
					left = left->right;
				return (left);
			};

			node_type *get_right_smallest_node(node_type *right)
			{
				while (right->left != this->_nil)
					right = right->left;
				return (right);
			};

			node_type *get_next_node(node_type *position) const
			{
				iterator itr(position);
				++itr;
				return (itr.get_ptr());
			};


			void replace_node(node_type* target, node_type* child)
			{
				child->parent = target->parent;
				if (target->parent->left == target)
					target->parent->left = child;
				else if (target->parent->right == target)
					target->parent->right = child;
			};

			void delete_case1(node_type *target)
			{
				if (!target->parent->empty())
					delete_case2(target);
			};

			void delete_case2(node_type *target)
			{
				node_type *s = target->sibling();

				if (s->color == RED)
				{
					target->parent->color = RED;
					s->color = BLACK;
					if (target == target->parent->left)
						rotate_left(target->parent);
					else
						rotate_right(target->parent);
				}
				delete_case3(target);
			};

			void delete_case3(node_type *target)
			{
				node_type *s = target->sibling();

				if ((target->parent->color == BLACK) &&
					(s->color == BLACK) &&
					(s->left->color == BLACK) &&
					(s->right->color == BLACK))
				{
					s->color = RED;
					delete_case1(target->parent);
				}
				else
					delete_case4(target);
			};

			void delete_case4(node_type *target)
			{
				node_type *s = target->sibling();

				if ((target->parent->color == RED) &&
					(s->color == BLACK) &&
					(s->left->color == BLACK) &&
					(s->right->color == BLACK))
				{
					s->color = RED;
					target->parent->color = BLACK;
				}
				else
					delete_case5(target);
			};

			void delete_case5(node_type *target)
			{
				node_type *s = target->sibling();

				if  (s->color == BLACK)
				{
					if ((target == target->parent->left) &&
						(s->right->color == BLACK) &&
						(s->left->color == RED))
					{
						s->color = RED;
						s->left->color = BLACK;
						rotate_right(s);
					}
					else if ((target == target->parent->right) &&
						(s->left->color == BLACK) &&
						(s->right->color == RED))
					{
						s->color = RED;
						s->right->color = BLACK;
						rotate_left(s);
					}
				}
				delete_case6(target);
			};

			void delete_case6(node_type *target)
			{
				node_type *s = target->sibling();

				s->color = target->parent->color;
				target->parent->color = BLACK;

				if (target == target->parent->left) {
					s->right->color = BLACK;
					rotate_left(target->parent);
				} else {
					s->left->color = BLACK;
					rotate_right(target->parent);
				}
			};
		
		public:

	};
}//namespace ft

#endif