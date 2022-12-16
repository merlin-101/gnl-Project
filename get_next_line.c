/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:15:17 by rnarciso          #+#    #+#             */
/*   Updated: 2022/12/16 05:25:56 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

/* 
this function will get and search for the
line with the first '\n', while preventing errors
*/

static	char	*list_checker(int fd, char *buff, char *backup)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	while (bytes != '\0')
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (0);
		else if (bytes == 0)
			break ;
		buff[bytes] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buff);
		free(temp);
		temp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (backup);
}

/*
this function will remove the extra strings that appear after the '\n'
by counting the lenght of the string before the '\n' appears.
*/

static	char	*ultimate_deletion(char *backup)
{
	size_t	counter;
	char	*s;

	counter = 0;
	while (backup[counter] != '\n' && backup[counter])
		counter++;
	if (!backup[counter] || backup[1] == '\0')
		return (NULL);
	s = ft_substr(backup, counter + 1, (ft_strlen(backup) - counter));
	if (*s == '\0')
	{
		free(s);
		s = NULL;
	}
	backup[counter + 1] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*backup;

	if ((BUFFER_SIZE <= 0) || (fd < 0))
		return (0);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	line = list_checker(fd, buff, backup);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	backup = ultimate_deletion(line);
	return (line);
}

/*
int	main(void)
{
	int		fd;
	char	*string;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (printf("failed to read\n") == -1);
	string = get_next_line(fd);
	printf("%s", string);
	close(fd);
	free(string);
	return (0);
}
*/