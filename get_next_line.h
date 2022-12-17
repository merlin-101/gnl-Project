/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:16:09 by rnarciso          #+#    #+#             */
/*   Updated: 2022/12/17 00:23:53 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h> //extra libs for testing purposes
# include <sys/stat.h> // |
# include <fcntl.h>	  //  |
# include <stdio.h>	 //   |

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char		*get_next_line(int fd);
int			ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *str, int c);
char		*ft_strcpy(char *dest, char	*src);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif