/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:49:22 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/21 23:06:17 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	sent_text_by_bits(char *s, pid_t serv_pid)
{
	int		b_i;
	char	tmp_c;

	while (*s)
	{
		b_i = 8;
		tmp_c = *s;
		while (b_i-- > 0)
		{
			tmp_c = *s >> b_i;
			if (tmp_c % 2 == 0)
				kill (serv_pid, SIGUSR1);
			else
				kill (serv_pid, SIGUSR2);
			usleep(42);
		}
		s++;
	}
}

int	main(int ac, char **av)
{
	pid_t	serv_pid;

	if (ac != 3)
	{
		ft_printf ("%sError: Wrong format! %s\n\n \
			%sPlease follow the structure%s:\n\n\
			./client (1)<PID> (2)\"Message\"\
			\n\n-—  (1) int pid\n\n\
			——  (2) any length text in double quotes\n\n",
			RED, RESET_COLOR, YELLOW, RESET_COLOR);
		return (0);
	}
	serv_pid = ft_atoi(av[1]);
	if (kill(serv_pid, 0))
	{
		ft_printf("%sError: PID is not valid\n%s", RED, RESET_COLOR);
		return (0);
	}
	sent_text_by_bits (av[2], serv_pid);
	return (0);
}

// kill(pid_t pid, int process_num); 
// so when kill(pid, 0); - it is actually non existant num of signal, 
// used to check if pid is valid and has rights to work with it.
// returns -1 on error, 0 on success