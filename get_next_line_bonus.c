/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:36:34 by rnarciso          #+#    #+#             */
/*   Updated: 2022/12/27 17:18:32 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// just to be cautious, Valgrind isn't that good.
char	*memory_leak_destroyer_fu(char *s)
{
	free(s);
	s = NULL;
	return (NULL);
}

// this will check if there is an existing '\n'
// during the reading, and return the whole read
// if it found the '\n' char
char	*read_and_get_line(int fd, char *backup)
{
	ssize_t		bytes;
	char		*buffer;

	bytes = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes > 0 && !ft_strchr(backup, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			if (backup && ft_strchr(backup, '\0'))
				free(backup);
			free(buffer);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = 0;
		backup = ft_strjoin(backup, buffer);
	}
	memory_leak_destroyer_fu(buffer);
	return (backup);
}

// this will cleanse the read and returned line from the previous function
// making it only the first line
char	*correcting_the_line(char *backup)
{
	char	*updated_line;
	int		stop;

	stop = 0;
	if (ft_strlen(backup) == 0)
		return (NULL);
	while (backup[stop] != '\n' && backup[stop])
		stop++;
	updated_line = ft_substr(backup, 0, (stop + 1));
	if (!updated_line)
		return (memory_leak_destroyer_fu(updated_line));
	return (updated_line);
}

// this will update the backup, by adding only the extra
// that was previously ignored on the correct line
char	*backup_update(char *backup)
{
	int		stop;
	char	*updated_backup;

	stop = 0;
	while (backup[stop] != '\n' && backup[stop])
		stop++;
	if (!backup[stop] || backup[1] == '\0')
		return (memory_leak_destroyer_fu(backup));
	updated_backup = ft_substr(backup, (stop + 1),
			(ft_strlen(backup) - stop));
	if (!updated_backup)
		return (memory_leak_destroyer_fu(updated_backup));
	free(backup);
	return (updated_backup);
}

// main function
char	*get_next_line(int fd)
{
	char		*correct_line;
	static char	*backup[FD_MAX];

	if (fd > FD_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(backup[fd], '\n') && backup[fd])
	{
		correct_line = correcting_the_line(backup[fd]);
		backup[fd] = backup_update(backup[fd]);
		return (correct_line);
	}
	backup[fd] = read_and_get_line(fd, backup[fd]);
	if (!backup[fd])
	{
		memory_leak_destroyer_fu(backup[fd]);
		return (NULL);
	}
	correct_line = correcting_the_line(backup[fd]);
	backup[fd] = backup_update(backup[fd]);
	return (correct_line);
}
/*
int	main(void)
{
	int		fd;
	int		i;
	char	*string;

	i = 6;
	fd = open("test.txt", O_RDONLY);
	if (fd <= -1)
		return (0);
	while (i != 0)
	{
		string = get_next_line(fd);
		printf("%s", string);
		free(string);
		--i;
	}
	close(fd);
	return (0);
}
*/