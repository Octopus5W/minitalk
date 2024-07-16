/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:26:17 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/05/14 15:22:12 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
int		ft_printf(const char *s, ...);
size_t	ft_putstr(char *s);
int		ft_putchar(int c);
void	ft_putnbr_base(size_t *l_nbr, size_t nbr, char *base, char type);

#endif
