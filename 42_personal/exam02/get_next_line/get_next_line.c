#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

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

int		ft_strlen(const char *s)
{
	size_t 		i;
	
	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const char *src, size_t n)
{
	size_t		i;
	unsigned char *d;
	unsigned char *s;

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
	size_t		len;
	size_t		i;
	char		*temp;

	i = 0;
	len = ft_strlen(s);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp == 0)
		return (0);
	while (s[i] != '\0')
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*join_s;
	size_t		s1_len;
	size_t		s2_len;

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

int		get_line(char **line, char *nl_addr, char **rem)
{
	char		*temp;
	
	if (nl_addr)
	{
		nl_addr[0] = '\0';
		*line = ft_strdup(*rem);
		temp = ft_strdup(nl_addr + 1);
		free(*rem);
		*rem = temp;
		return (1);
	}
	if (*rem)
	{
		*line = ft_strdup(*rem);
		free(*rem);
		*rem = NULL;
	}
	else
		*rem = ft_strdup("");
	return (0);
}

int		get_next_line(char **line)
{
	static char	*rem;
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	char		*nl_addr;
	int			rd_len;

	if (!line)
		return (-1);
	if (rem == NULL)
		rem = ft_strdup("");
	while ((nl_addr = ft_strchr(rem, '\n')) == 0 &&
			(rd_len = read(0, buff, BUFFER_SIZE) > 0))
	{
		buff[rd_len] = '\0';
		temp = ft_strjoin(rem, buff);
		free(rem);
		rem = temp;
	}
	if (rd_len < 0)
		return (-1);
	return (get_line(line, nl_addr, &rem));
}
