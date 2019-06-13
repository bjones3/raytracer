/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:27:01 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:30:13 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	render(int n)
{
	if (n >= 10 || n <= -10)
	{
		render(n / 10);
		render(n % 10);
	}
	else
	{
		if (n >= 0)
			ft_putchar(n + '0');
		else
			ft_putchar(-1 * n + '0');
	}
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	render(n);
}
