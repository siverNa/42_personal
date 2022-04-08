/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:15:16 by sna               #+#    #+#             */
/*   Updated: 2022/04/08 14:27:42 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public Form {
 private:
 public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

	// 드릴 소리를 내고, <target>이 50%의 확률로 성공하면 성공메세지를, 그렇지 않으면 실패라고 알려주십시오.
	void execute(Bureaucrat const & executor) const;
};

#endif