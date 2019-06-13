/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:23:07 by bjones            #+#    #+#             */
/*   Updated: 2018/01/26 00:37:16 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static double	ft_atof2(t_atof e, char *num)
{
	while (*num != '\0')
	{
		if (*num >= '0' && *num <= '9')
		{
			if (e.in_fract)
			{
				e.fract_part = e.fract_part * 10 + (*num - '0');
				e.fract_divisor *= 10;
			}
			else
				e.int_part = e.int_part * 10 + (*num - '0');
		}
		else if (*num == '.')
		{
			if (e.in_fract)
				return (e.sign * (e.int_part + e.fract_part / e.fract_divisor));
			else
				e.in_fract = 1;
		}
		else
			return (e.sign * (e.int_part + e.fract_part / e.fract_divisor));
		++num;
	}
	return (e.sign * (e.int_part + e.fract_part / e.fract_divisor));
}

double			ft_atof(char *num)
{
	t_atof	e;

	if (!num || !*num)
		return (0);
	e.int_part = 0;
	e.fract_part = 0;
	e.fract_divisor = 1;
	e.sign = 1;
	e.in_fract = 0;
	if (*num == '-')
		e.sign = -1;
	if (*num == '+' || *num == '-')
		++num;
	return (ft_atof2(e, num));
}
