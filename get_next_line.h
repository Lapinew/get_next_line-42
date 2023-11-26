/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:32:21 by daleliev          #+#    #+#             */
/*   Updated: 2023/11/12 13:05:39 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	ft_clean_save(char *save);
char	*fd_clean_nl(char **nl);
void	ft_add_save_to_nl(char **nl, char *save);
int		ft_check_rs(int read_size, char **save);
int		ft_search_n(char *str);
int		ft_strlen(char	*str);
void	*ft_read(char **nl, char *save, int fd);

#endif
