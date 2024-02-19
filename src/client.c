/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:49:22 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/18 19:22:22 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int error_check (int ac, char **av)
{
    int i;

    i = 0;
    if (ac != 3 && ++i && av[0])
        ft_printf ("Error: Wrong format! Please follow the structure: ./client <PID> \"Message text in double quotes\"");
    return (i);
}

int main(int ac, char **av)
{
    // __pid_t serv_pid;

    if (!error_check (ac, av))
    {
        ft_printf("hello world");
    }
        // ft_printf("pid: %d\n", (int)serv_pid);
    return (0);
}