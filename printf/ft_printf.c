/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:41:18 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/05/14 15:17:09 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_va_arg(const char *s, char *s_check, size_t *l, va_list arg)
{
	if (*s == 's')
	{
		s_check = va_arg(arg, char *);
		if (s_check)
			*l += ft_putstr(s_check);
		else
			*l += ft_putstr("(null)");
	}
	else if (*s == 'c')
		*l += ft_putchar(va_arg(arg, int));
	else if (*s == 'p')
	{
		*l += ft_putstr("0x");
		ft_putnbr_base(l, va_arg(arg, unsigned long), "0123456789abcdef", 'u');
	}
	else if (*s == 'x')
		ft_putnbr_base(l, va_arg(arg, unsigned int), "0123456789abcdef", 'u');
	else if (*s == 'X')
		ft_putnbr_base(l, va_arg(arg, unsigned int), "0123456789ABCDEF", 'u');
	else if (*s == 'u')
		ft_putnbr_base(l, va_arg(arg, unsigned int), "0123456789", 'u');
	else if (*s == 'i' || *s == 'd')
		ft_putnbr_base(l, va_arg(arg, int), "0123456789", 'i');
	else
		*l += ft_putchar(*s);
}

int	ft_printf(const char *s, ...)
{
	size_t	s_len;
	va_list	arg;
	char	*s_check;

	s_check = NULL;
	s_len = 0;
	va_start(arg, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ft_va_arg(s, s_check, &s_len, arg);
		}
		else
			s_len += ft_putchar(*s);
		s++;
	}
	va_end(arg);
	return (s_len);
}
