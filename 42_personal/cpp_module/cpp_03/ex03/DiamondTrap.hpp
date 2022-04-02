/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:29:46 by sna               #+#    #+#             */
/*   Updated: 2022/04/02 19:30:48 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

/*
** 다중 상속을 받을 땐, 기본 클래스를 그 아래 클래스가 가상 상속 받아야함
** 기본 클래스가 가상 상속으로 지정되면 클래스 B, C가 동시에 상속받는 A가 하나만 존재하게 됨
** 가상 상속시, 기본 클래스의 인스턴스를 가리키는 포인터 vbptr를 생성하고 메모리 제일 아래에 위치시킴
** 이 vbptr을 클래스 B, C가 참조하게 함으로써 클래스 A의 인스턴스가 한번만 생성됨.
*/

class DiamondTrap: public FragTrap, public ScavTrap {
 private:
	std::string _name;
 public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& obj);
	~DiamondTrap(void);
	DiamondTrap& operator=(const DiamondTrap& obj);

	void	whoAmI(void);
	using 	ScavTrap::attack;
};

#endif