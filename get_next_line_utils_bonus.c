/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 05:42:17 by rnarciso          #+#    #+#             */
/*   Updated: 2022/12/16 05:45:37 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				len;
	int				i;
	int				i2;
	char			*res;

	i = 0;
	i2 = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		res[i + i2] = s2[i2];
		i2++;
	}
	res[i + i2] = '\0';
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i_1;
	size_t			i_2;
	char			*res;

	res = (char *)malloc(sizeof(*s) * len + 1);
	if (!s || !res)
		return (NULL);
	i_1 = 0;
	i_2 = 0;
	while (s[i_1])
	{
		if (i_1 >= start && i_2 < len)
			res[i_2++] = s[i_1];
		i_1++;
	}
	res[i_2] = '\0';
	return (res);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;
	int		i2;

	i = 0;
	i2 = ft_strlen(src);
	ptr = (char *)malloc(sizeof(*src) * (i2 + 1));
	while (i < i2)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
