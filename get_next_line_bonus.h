/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:30:34 by ael-krid          #+#    #+#             */
/*   Updated: 2024/01/22 17:30:44 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
 # define BUFFER_SIZE 12
 #endif
#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <limits.h>
# include <stdlib.h>
#include <unistd.h>
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_bzero(char *s, size_t n);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

#endif
