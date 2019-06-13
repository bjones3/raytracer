/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 23:11:56 by bjones            #+#    #+#             */
/*   Updated: 2017/10/12 15:44:06 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>

static t_list	*get_file(int fd)
{
	static t_list	*file_list;
	t_list			*tmp;

	tmp = file_list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", 1);
	tmp->content_size = fd;
	ft_lstadd(&file_list, tmp);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	t_list	*file;
	int		ret;

	if (fd < 0 || line == NULL || read(fd, *line, 0) < 0)
		return (-1);
	file = get_file(fd);
	ret = 1;
	while (!ft_strchr(file->content, '\n') && ret > 0)
	{
		if (!(*line = ft_memalloc(BUFF_SIZE + 1)))
			return (-1);
		ret = read(fd, *line, BUFF_SIZE);
		file->content = ft_strjoin_free(file->content, *line);
	}
	if (!*(char *)file->content)
		return (0);
	*line = ft_strcpy_until(file->content, '\n');
	file->content = ft_strcpy_after_free(file->content, '\n');
	return (1);
}
