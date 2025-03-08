/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:36:31 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/03/08 22:00:23 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	bit_handler(int SIG)
{
	static int	binary = 0;
	static char	bit = 8;

	bit--;
	if (SIG == SIGUSR2)
		binary |= (1 << bit);
	if (bit == 0)
	{
		write(1, &binary, 1);
		if (binary == 0)
			write(1, "\n", 1);
		bit = 8;
		binary = 0;
	}
}

int	main(void)
{
	ft_printf("PID : < %d >\n", getpid());
	signal(SIGUSR1, bit_handler);
	signal(SIGUSR2, bit_handler);
	while (1)
		pause();
	return (0);
}
