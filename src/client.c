/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:49:22 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/20 02:22:28 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void    sent_text_by_bits (char *s, __pid_t serv_pid)
{
    int     b_i;
    char    tmp_c;

    while (*s++)
    {
        b_i = 8;
        tmp_c = *s;
        while (--b_i > 0)
        {
            tmp_c = *s >> b_i;
            if (tmp_c % 2 == 0)
                kill (serv_pid, SIGUSR1);
            else
                kill (serv_pid, SIGUSR2);
            usleep(100);
        }

    }
}

int main(int ac, char **av)
{
    __pid_t serv_pid;

    if (ac != 3)
    {
        ft_printf ("Error: Wrong format! Please follow the structure: ./client (1)<PID> (2)\"Message\"\n(1) - int pid\n(2) - any length text in double quotes\n");
        return (0);
    }
    serv_pid = ft_atoi(av[1]);
    if (kill(serv_pid, 0))
    {
        ft_printf("Error: PID is not valid\n");
        return (0);
    }
    ft_sent_text_by_bits (av[2], serv_pid);
    return (0);
}

// kill(pid_t pid, int process_num); 
// so when kill(pid, 0); - it is actually non existant num of signal, used to check if pid is valid and has rights to work with it.
// returns -1 on error, 0 on success