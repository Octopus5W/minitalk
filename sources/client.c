#include "../include/minitalk.h"

int	ft_atoi(const char *s)
{
	int	nb;

	nb = 0;
	if (!s || !*s)
		return (-1);
	while ((*s >= 7 && *s <= 13) || *s == 32)
		s++;
	while (*s >= '0' && *s <= '9')
	{
		nb = nb * 10 + (*s - 48);
		s++;
	}
	if (!*s)
		return (nb);
	else
		return (-1);
}

int	send_sig_char(int c, int pid)
{
	int	bit;
	int	check;

	bit = 8;
	while (bit-- > 0)
	{
		if (c & (1 << bit))
			check = kill(pid, SIGUSR2);
		else
			check = kill(pid, SIGUSR1);
		if (check == -1)
			return (-1);
		usleep(550);
	}
	return (c);
}

int	main(int ac, char *av[])
{
	int	pid;
	int	check;
	int	i;

	i = 0;
	pid = ft_atoi(av[1]);
	if (ac == 3 && pid > 0)
	{
		if (!(av[2][0]))
			return (write(2, "Tu n'envoies pas de message.\n", 29), -1);
		check = send_sig_char(av[2][i++], pid);
		while (check > 0)
			check = send_sig_char(av[2][i++], pid);
		if (check == 0)
			return (write(2, "Message envoyé!\n", 16), 0);
		else
			return (write(2,
					"Une erreur est survenue pendant l'envoie du message.\n",
					53), -1);
	}
	else if (ac != 3)
		return (write(2, "Nombre d'argument incorrecte.\n", 30), -1);
	else
		return (write(2, "PID incorrecte.\n", 16), -1);
	return (0);
}