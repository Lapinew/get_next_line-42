/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:36:29 by daleliev          #+#    #+#             */
/*   Updated: 2023/11/06 11:36:31 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char	*str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_search_n(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (++i);
		i++;
	}
	if (str[i] == '\n')
		return (++i);
	return (0);
}

void	ft_add_save_to_nl(char **nl, char *save)
{
	char	*swap;
	int		i;
	int		j;

	swap = malloc((ft_strlen(*nl) + ft_strlen(save) + 1) * sizeof(char));
	if (!swap)
		return ;
	i = 0;
	if (*nl)
	{
		while ((*nl)[i])
		{
			swap[i] = (*nl)[i];
			i++;
		}
	}
	j = 0;
	while (save[j])
		swap[i++] = save[j++];
	swap[i] = '\0';
	free(*nl);
	*nl = swap;
}

char	*fd_clean_nl(char **nl)
{
	char	*swap;
	int		i;

	i = 0;
	while ((*nl)[i] && (*nl)[i] != '\n')
		i++;
	if (i == 0 && (*nl)[i] != '\n')
	{
		free(*nl);
		return (NULL);
	}
	if ((*nl)[i] == '\n')
		i++;
	swap = malloc((i + 1) * sizeof(char));
	if (!swap)
		return (NULL);
	i = -1;
	while ((*nl)[++i] && (*nl)[i] != '\n')
		swap[i] = (*nl)[i];
	if ((*nl)[i] == '\n')
		swap[i++] = '\n';
	swap[i] = '\0';
	free(*nl);
	*nl = swap;
	return (*nl);
}

void	ft_clean_save(char *save)
{
	int		i;
	int		j;
	int		len_save;

	len_save = ft_strlen(save);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	if (i == len_save)
	{
		save[0] = '\0';
		return ;
	}
	j = 0;
	while (i < len_save)
	{
		save[j] = save[i];
		i++;
		j++;
	}
	save[j] = '\0';
}
