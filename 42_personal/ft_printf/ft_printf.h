/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:37:15 by sna               #+#    #+#             */
/*   Updated: 2021/02/11 18:07:13 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define TYPE		"cspdiuxX%"
# define F_MINUS	1
# define F_ZERO		2
# define F_WIDTH	4
# define F_PREC		8

typedef struct	s_form
{
	unsigned int	flag;
	int				width;
	int				prec;
	char			type;
	int				nbr_sign;
	int				nbr_base;
}				t_form;

/*
** ft_printf.c function
*/

int				print_type(va_list ap, t_form *form);
void			check_width_and_prec(va_list ap, char *format,
		t_form *form, int i);
void			check_form(va_list ap, char *format, t_form *form, int i);
int				process_format(va_list ap, char *format);
int				ft_printf(const char *format, ...);

/*
** ft_printf_util.c function
*/

void			init_form(t_form *form);
int				ft_nbrlen(unsigned long long nbr, t_form *form);
char			*ft_baseset(char type);

/*
** ft_printf_char.c function
*/

int				print_width_len(t_form *form, int f_len);
int				print_char(int c, t_form *form);

/*
** ft_printf_string.c function
*/

char			*str_to_buff(char *str, int prec_len, int s_len);
int				put_str_width(char **buff, t_form *form);
int				print_string(char *str, t_form *form);

/*
** ft_printf_number.c function
*/

int				put_pointer_nbr(char **n_buff);
int				put_minus(t_form *form, char **n_buff);
int				put_minus2(t_form *form, char **n_buff, int n_len);
int				put_str_prec(unsigned long long nbr, t_form *form,
		char **n_buff);
int				print_number(unsigned long long nbr, t_form *form);

#endif
