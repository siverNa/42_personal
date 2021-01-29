/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:56:04 by sna               #+#    #+#             */
/*   Updated: 2021/01/20 17:29:48 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c && c == 0)
		return ((char *)s + i);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t			len;
	char			*temp;
	size_t			i;

	len = ft_strlen(s);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*join_s;
	size_t			s1_len;
	size_t			s2_len;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join_s = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (join_s == 0)
		return (0);
	ft_memcpy(join_s, s1, s1_len);
	ft_memcpy(join_s + s1_len, s2, s2_len);
	join_s[s1_len + s2_len] = 0;
	return (join_s);
}
