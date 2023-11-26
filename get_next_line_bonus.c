/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:25:34 by daleliev          #+#    #+#             */
/*   Updated: 2023/11/06 09:25:41 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_read(char **nl, char *save, int fd)
{
	ssize_t		read_size;

	read_size = BUFFER_SIZE;
	while (!ft_search_n(save) && read_size == BUFFER_SIZE)
	{
		read_size = read(fd, save, BUFFER_SIZE);
		if (read_size <= 0)
		{
			if (read_size == -1)
			{
				save[0] = '\0';
				free(*nl);
				return (NULL);
			}
			break ;
		}
		save[read_size] = '\0';
		ft_add_save_to_nl(nl, save);
	}
	return (*nl);
}

char	*get_next_line(int fd)
{
	static char	save[FD_LIMIT][BUFFER_SIZE] = {};
	char		*nl;

	nl = NULL;
	if (save[0] || ft_search_n(save[fd]))
	{
		ft_add_save_to_nl(&nl, save[fd]);
		fd_clean_nl(&nl);
		ft_clean_save(save[fd]);
		return (nl);
	}
	else if (save[fd][0])
	{
		ft_add_save_to_nl(&nl, save[fd]);
		ft_clean_save(save[fd]);
	}
	if (!ft_read(&nl, save[fd], fd))
		return (NULL);
	fd_clean_nl(&nl);
	ft_clean_save(save[fd]);
	return (nl);
}

/*
int	main()
{
	int	fd;
	
	fd = open("file.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//		printf("%s", get_next_line(fd));

}*/
