/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:51:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/19 14:02:05 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int error_check (int ac, char **av)
{
    if (ac != 3 && av[0])
        ft_printf ("hello world");
    return (0);
}

int main(int ac, char **av)
{
    // __pid_t serv_pid;

    if (!error_check (ac, av))
    {
        ft_printf("hello world");
    }
        // printf("pid: %d\n", (int)serv_pid);
    return (0);
}