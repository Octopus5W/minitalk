/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:18:35 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/05/14 15:20:16 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i])
	{
		while (base[i])
		{
			j = i + 1;
			if (!base[1] || base[i] == '+' || base[i] == '-')
				return (0);
			while (base[j])
			{
				if (base[i] == base[j])
					return (0);
				j++;
			}
			i++;
		}
	}
	else
		return (0);
	return (i);
}

void	ft_putnbr_base(size_t *l_nbr, size_t nbr, char *base, char type)
{
	if (ft_check_base(base) && type == 'u')
	{
		if (nbr >= ft_strlen(base))
			ft_putnbr_base(l_nbr, nbr / ft_strlen(base), base, type);
		write(1, &base[nbr % ft_strlen(base)], 1);
		(*l_nbr)++;
	}
	else if (ft_check_base(base))
	{
		if ((int)nbr == -2147483648)
			(*l_nbr) += ft_putstr("-2147483648");
		else
		{
			if ((int)nbr < 0)
			{
				(*l_nbr) += ft_putstr("-");
				nbr *= -1;
			}
			if ((int)nbr >= (int)ft_strlen(base))
				ft_putnbr_base(l_nbr, (int)nbr / ft_strlen(base), base, type);
			write(1, &base[(int)nbr % ft_strlen(base)], 1);
			(*l_nbr)++;
		}
	}
}
