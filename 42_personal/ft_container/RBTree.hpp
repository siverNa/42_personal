/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:15:38 by sna               #+#    #+#             */
/*   Updated: 2022/06/22 17:48:53 by sna              ###   ########.fr       */
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
		
	};
}//namespace ft

#endif