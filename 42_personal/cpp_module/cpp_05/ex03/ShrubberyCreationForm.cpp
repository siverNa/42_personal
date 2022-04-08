/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:50:06 by sna               #+#    #+#             */
/*   Updated: 2022/04/08 13:22:58 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("none", "ShrubberyCreationForm", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form(target, "ShrubberyCreationForm", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : Form(obj)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	this->Form::operator=(obj);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == false)
		throw IsNotSignedException();
	if (getExecGrade() < executor.getGrade())
		throw ExecGradeTooLowException();
	
	std::string fileName = getTarget().append("_shrubbery");
	std::ofstream ofs(fileName.c_str());
	if (ofs.is_open() == false)
	{
		std::cout << "Error: fail open <" << fileName << ">" << std::endl;
		return ;
	}
	ofs <<	"-----------,------------------\n"
			"--------,,,,,,,,,,,,-,,,------\n"
			"---,,,,,,,,,,,..,,,,,,,,,,,---\n"
			",,,,,,,,.....,........,,,,,,,,\n"
			",,,,,,.,...................,,,\n"
			",,,,,.,......................,\n"
			",,..............~:~~::~.......\n"
			",..........   -~!;;;:.:~......\n"
			".........    ~:;;~!:;!    ....\n"
			".......      -;;~:!!;:;     ..\n"
			" .           ~;;!;;!;~;.      \n"
			"             ~:!!!!=;*;,      \n"
			"             ~~=;!$=!!::      \n"
			".            .;*:-! ;*:,      \n"
			".            ,-   :           \n"
			",                 !           \n"
			".                             \n"
			";;:~~~~~~~-~~~~~:::~~-~~~~:~::\n"
			"*;;;::::::;:::::~~::::::::::::\n"
			"!;;;;:;;;;::::;::::::::;:::;::\n";
	ofs.close();
}