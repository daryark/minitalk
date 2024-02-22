/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:51:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/22 23:13:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	get_signal(int bit, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;
	static int	tmp_pid;

	(void)context;
	c |= (bit == SIGUSR2);
	if (++i == 8)
	{
		if (c == END_OF_SIGNAL)
			exit (EXIT_SUCCESS);
		else
			ft_printf ("%c", c);
		c = 0;
		i = 0;
	}
	else
		c <<= 1;
	if (tmp_pid != info->si_pid)
	{
		kill(info->si_pid, SIGUSR2);
		tmp_pid = info->si_pid;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = get_signal;
	sa.sa_flags = 0;
	sigemptyset (&sa.sa_mask);
	ascii_draw_minitalk (getpid());
	sigaction (SIGUSR1, &sa, NULL);
	sigaction (SIGUSR2, &sa, NULL);
	while (1)
		pause ();
	return (0);
}
