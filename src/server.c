/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:51:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/22 01:36:54 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	get_signal(int bit)
{
	static char	c;
	static int	i;

	c |= (bit == SIGUSR2);
	if (++i == 8)
	{
		if (c == END_OF_SIGNAL)
			ft_printf ("\n\n\n");
		else
			ft_printf ("%c", c);
		c = 0;
		i = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = get_signal;
	sa.sa_flags = 0;
	sigemptyset (&sa.sa_mask);
	ascii_draw_minitalk (getpid());
	sigaction (SIGUSR1, &sa, NULL);
	sigaction (SIGUSR2, &sa, NULL);
	while (1)
		pause ();
	return (0);
}

//sa.sa_flags - specify various options and behaviors related
// to signal handling (restart, stop, blocking...)
// default flags may be set other way so its always better
// to annulate them if not needed.

//sigemtyset - clears the set of all signals, 
//ensuring that no signal is blocked/masked. so to work with
// SIGUSER1 and SIGUSER2 signals after that.