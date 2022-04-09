/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:32:49 by sna               #+#    #+#             */
/*   Updated: 2022/04/09 20:49:36 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization() {}
Serialization::Serialization(const Serialization& obj) {}
Serialization::~Serialization() {}
Serialization& Serialization::operator=(const Serialization& obj) {}

/*
** reinterpret_cast<바꿀 타입>(대상)
** 임의의 포인터 타입끼리 변환을 허용하는 캐스트 연산자
** (대상) 에 해당하는 것을 <바꿀 타입>으로 비트 단위로 바꿈
** uintptr_t : 포인터의 주소를 저장하는데, intptr_t 타입의 부호없는 버전
*/

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}