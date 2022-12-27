/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:37:54 by rnarciso          #+#    #+#             */
/*   Updated: 2022/12/27 17:17:59 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_strlen(const char *string)
{
	ssize_t	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
		i++;
	return (i);
}

// will check for the first ocurrence of c
// and return the whole line
char	*ft_strchr(const char *str, int c)
{
	ssize_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str);
		i++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

// this will put together the contents on s1 with the contents on s2
char	*ft_strjoin(char *s1, char *s2)
{
	ssize_t			i;
	ssize_t			i2;
	char			*res;

	i = -1;
	i2 = 0;
	if (!s1 && s2)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	while (s2[i2])
		res[i++] = s2[i2++];
	res[i] = '\0';
	free(s1);
	return (res);
}

// this will be the pivotal aux funct as it updates the backlog
// and removes the extra from the read lines.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			i_2;
	size_t			i_3;
	char			*res;
	char			*ptr;

	i = ft_strlen(s);
	if (start > i)
		len = 0;
	if (len > i - start)
		len = i - start;
	ptr = ((res = (char *)malloc((len * sizeof(char)) + 1)));
	if (!s || !ptr)
		return (NULL);
	i_2 = 0;
	i_3 = 0;
	while (s[i_2])
	{
		if (i_2 >= start && i_3 < len)
			res[i_3++] = s[i_2];
		i_2++;
	}
	res[i_3] = '\0';
	return (res);
}
