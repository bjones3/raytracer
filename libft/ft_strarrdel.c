/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 20:06:15 by bjones            #+#    #+#             */
/*   Updated: 2017/10/16 20:08:33 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strarrdel(char ***as)
{
	char	**tmp;
	int		i;

	tmp = *as;
	i = -1;
	while (tmp[++i] != NULL)
		ft_strdel(&tmp[i]);
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}
