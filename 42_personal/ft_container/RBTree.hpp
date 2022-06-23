/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:15:38 by sna               #+#    #+#             */
/*   Updated: 2022/06/23 22:17:17 by sna              ###   ########.fr       */
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

			void swap_one_depth(node_type *&p, node_type *&c)//target, node
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
			RBTree()
				: _size(0),  _comp(comp_type()), _node_alloc(node_allocator_type())
			{
				this->_nil = this->construct_node();
				this->_nil->parent = _nil;
				this->_nil->left = _nil;
				this->_nil->right = _nil;
				this->_root = _nil;
			};

			RBTree(const RBTree& x)
				: _size(0), _comp(comp_type()), _node_alloc(node_allocator_type())
			{
				this->_nil = this->construct_node();
				this->_nil->parent = _nil;
				this->_nil->left = _nil;
				this->_nil->right = _nil;
				this->_root = _nil;
				this->copy(x);
			};

			~RBTree()
			{
				this->clear();
				destroy_node(this->_nil);
			};

			node_type* get_nil() const 
			{
				return (this->_nil);
			};

			size_t get_size() const
			{
				return (this->_size);
			};

			node_type* get_smallest() const
			{
				node_type *result = this->_root;
				while (!result->left->empty())
					result = result->left;
				return (result);
			};

			node_type* get_biggest() const
			{
				node_type *result = this->_root;
				while (!result->right->empty())
					result = result->right;
				return (result);
			};

			node_type* search(const T& value) const
			{
				return (search(this->_root, value));
			};

			node_type* search(node_type* node, const T& value) const
			{
				if (node == this->_nil)
					return (this->_nil);
				else if (same_value(node->get_value(), value))
					return (node);
				else if (_comp(node->get_value(), value))//만약 value가 현재 노드보다 더 크면 오른쪽 탐색
					return (search(node->right, value));
				else//value가 현재 노드보다 작다면 왼쪽 탐색 
					return (search(node->left, value));
			};

			pair<node_type*, bool> insert(const T& value)
			{
				//비어있는 트리이면 들어온 값을 루트 노드로 추가
				if (this->empty())
				{
					this->_root = this->construct_node(value);
					this->_root->parent = _nil;
					this->_root->left = _nil;
					this->_root->right = _nil;
					this->_root->color = BLACK;//루트 노드는 black
					++this->_size;
					this->_nil->parent = this->get_biggest();
					return (pair<node_type*, bool>(this->_root, true));
				}

				//트리가 존재하면, 루트 노드부터 값을 비교하면서 동일한 값이 있는 지 확인
				node_type *current = this->_root;
				node_type *parent = this->_nil;
				while (current != this->nil)
				{
					parent = current;
					if (same_value(value, current->get_value()))//같은 값이 존재하면 false 반환
						return (pair<node_type*, bool>(current, false));
					else if (_comp(value, current->get_value()))//value가 current보다 작으면 왼쪽 탐색
						current = current->left;
					else//value가 current보다 크면 오른쪽 탐색
						current = current->right;
				}
				//여기로 왔다는 건 동일한 value가 없단 뜻이므로 트리에 추가
				current = this->construct_node(value);
				current->parent = parent;
				current->left = this->_nil;
				current->right = this->_nil;
				if (_comp(value, parent->get_value()))
					parent->left = current;
				else
					parent->right = current;
				fix_violation(current);
				++this->_size;
				this->_nil->parent = this->get_biggest();
				return (pair<node_type*, bool>(current, true));
			};

			size_t erase(node_type* target)
			{
				if (this->_nil == target)
					return (0);
				if (!target->is_leaf())//리프 노드가 아니면 왼쪽 또는 오른쪽이랑 스왑하고 삭제
					swap_target(target);
				delete_node(target);
				return (1);
			};

			size_t erase(const T& value)
			{
				return (erase(this->search(value)));
			};

			template <typename InputIterator>
			size_t erase(InputIterator iterator,
						typename ft::enable_if<ft::is_iter<InputIterator>::value>::yes = 1)
			{
				return (erase(iterator.get_pointer()));
			};

			void delete_node(node_type* target)
			{
				//삭제노드가 루트 노드이고, 자식 노드가 없으면 그냥 삭제
				if (target->is_root() && target->is_leaf())
				{
					delete_root();
					return ;
				}
				node_type *child;
				if (target->left->empty())
					child = target->right;
				else
					child = target->left;
				replace_node(target, child);
				if (target->color == BLACK)
				{
					if (child->color == RED)//색이 RED이면 그냥 BLACK으로 바꿔주기만 하면 됨
						child->color = BLACK;
					else
						delete_case1(child);
				}
				this->destroy_node(target);
				--this->_size;
				this->_nil->parent = this->get_biggest();
			};

			void clear()
			{
				clear(this->_root);
				this->_size = 0;
			};

			void clear(node_type* node)
			{
				if (node == this->_nil)
					return ;
				clear(node->left);
				clear(node->right);
				if (node->is_root())
				{
					delete_root();
					return ;
				}
				else if (node->is_left())
					node->parent->left = this->_nil;
				else
					node->parent->right = this->_nil;
				this->destroy_node(node);
			};

			
	};
}//namespace ft

#endif