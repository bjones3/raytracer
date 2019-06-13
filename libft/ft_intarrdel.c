/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 20:07:59 by bjones            #+#    #+#             */
/*   Updated: 2017/10/16 20:09:15 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_intarrdel(int ***ai, int len)
{
	int	**tmp;
	int i;

	tmp = *ai;
	i = -1;
	while (++i < len)
		ft_intdel(&tmp[i]);
	if (ai && *ai)
	{
		free(*ai);
		*ai = NULL;
	}
}
