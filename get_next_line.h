/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:12:26 by rnarciso          #+#    #+#             */
/*   Updated: 2022/12/27 17:16:24 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>	// to use the tester main
# include <sys/stat.h>	// |
# include <fcntl.h>		// v

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

// main functions
char		*get_next_line(int fd);
char		*read_and_get_line(int fd, char *backup);
char		*correcting_the_line(char *backup);
char		*backup_update(char *backup);

// Just a leaks remover tired of cleaning the goddam code.
// Valgrind aint worth sh#t - https://valgrind.org/docs/manual/quick-start.html
char		*memory_leak_destroyer_fu(char *s);

// auxiliary functions
ssize_t		ft_strlen(const char *string);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif