/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:51:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/18 18:51:41 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int error_check (int ac, char **av)
{
    if (ac != 3)
        ft_printf ();
}

int main(int ac, char **av)
{
    __pid_t serv_pid;

    if (!error_check (ac, av))
    {

    }
        printf("pid: %d\n", (int)serv_pid);
    return (0);
}