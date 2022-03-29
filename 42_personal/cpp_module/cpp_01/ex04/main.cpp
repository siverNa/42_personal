/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:33:54 by sna               #+#    #+#             */
/*   Updated: 2022/03/29 21:43:29 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int main(int argc, char *argv[])
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string 	output_name;
	std::string		content;
	
	if (argc != 4 || std::strlen(argv[1]) == 0 || std::strlen(argv[2]) == 0 || std::strlen(argv[3]) == 0)
	{
		std::cout << "usage: ./replace <filename> <string_to_find> <string_to_replace>" << std::endl;
		return (1);
	}
	
	output_name = argv[1];
	output_name.append(".replace");

	ifs.open(argv[1]);
	if (ifs.fail())
	{
		std::cout << "Error: fail open <" << argv[1] << ">" << std::endl;
		return (1);
	}

	ofs.open(output_name.c_str());
	if (ofs.fail())
	{
		std::cout << "Error: fail open <" << output_name << ">" << std::endl;
		ifs.close();
		return (1);
	}

	do
	{
		std::getline(ifs, content);
		while (true)
		{
			size_t	idx = content.find(argv[2]);

			if (idx == std::string::npos)
			{
				ofs << content;
				break ;
			}
			ofs << content.substr(0, idx) << argv[3];
			content = content.substr(idx + std::strlen(argv[2]));//2번째 인수가 생략된 경우, 해당 위치부터 끝까지 문자열 취득
		}
		if (ifs.eof())
			break ;
		ofs << std::endl;
	} while (true);
	
	ifs.close();
	ofs.close();

	return (0);
}