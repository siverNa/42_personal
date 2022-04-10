/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:00:28 by sna               #+#    #+#             */
/*   Updated: 2022/04/10 20:42:56 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

/*
** 템플릿을 정의할 땐, 헤더를 벗어날 수 없음.
** 템플릿의 특징으로, '컴파일 시에 모든 연산이 끝난다.' 인데,
** 이와 같은 특성이 cpp 파일의 컴파일 과정과 차이가 있기 때문에 정의를 분리할 수 없음
*/
template <typename T>
class Array {
 private:
	unsigned int	_size;
	T				*_arr;
 public:
	//기본생성자 : 비어있는 배열 생성
	Array()
	{
		_size = 0;
		_arr = new T[0];
	};

	//기본생성자(unsigned int n) : 크기 n의 배열 생성
	Array(unsigned int n)
	{
		_size = n;
		_arr = new T[n];
	};

	//복사 생성자
 	Array(const Array& obj)
	{
		_size = obj._size;
		_arr = new T[obj._size];
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = obj[i];
	};

	//소멸자
	~Array()
	{
		delete[] _arr;
		_arr = NULL;
		_size = 0;
	};

	Array& operator=(const Array& obj)
	{
		delete[] _arr;
		_arr = NULL;

		_size = obj._size;
		_arr = new T[obj._size];
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = obj[i];
	};

	//연산자[] 재정의
	T& operator[](unsigned int i)
	{
		if (i >= _size)
			throw Array::OutOfArrRange();
		return (_arr[i]);
	};

	//연산자[] 재정의
	const T& operator[](unsigned int i) const
	{
		if (i >= _size)
			throw Array::OutOfArrRange();
		return (_arr[i]);
	};

	//멤버함수 size, 배열의 size 반환
	unsigned int size(void) const
	{
		return (_size);
	};

	class OutOfArrRange : public std::exception {
		public:
			const char *what(void) const throw()
			{
				return ("Out Of Range Exception.");
			}
	};
};

#endif