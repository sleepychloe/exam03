/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:41:01 by yhwang            #+#    #+#             */
/*   Updated: 2022/02/18 14:45:15 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	save[999999];
	char	buff[1];
	char	*line;
	int	i;
	
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[i] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i] == '\n')
			break;
		i++;
	}
	if (save[0] == '\0')
		return (NULL);
	line = malloc(i + 1);
	i = 0;
	while (save[i])
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
