/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_draw_minitalk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:41:01 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/22 19:43:11 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ascii_draw_minitalk(pid_t serv_pid)
{
	ft_printf("%s\n✨———————————————————————————————————————————", MAGENTA);
	ft_printf("✣———————————————————————————————————————————————————✨\n");
	ft_printf("%s\n      ☻       ☻    ☻ ☻   ☻ ☻      ☻ ☻   ☻ ☻  ", YELLOW);
	ft_printf(" ☻ ☻ ☻ ☻ ☻ ☻     ☻ ☻ ☻ ☻     ☻ ☻       ☻ ☻    ☻    ");
	ft_printf("\n     ☻ ☻     ☻ ☻   ☻ ☻   ☻ ☻ ☻    ☻ ☻   ☻ ☻    ");
	ft_printf("   ☻ ☻       ☻ ☻     ☻ ☻   ☻ ☻       ☻ ☻  ☻      ");
	ft_printf("\n✨   ☻ ☻ ☻ ☻ ☻ ☻   ☻ ☻   ☻ ☻  ☻   ☻ ☻   ☻ ☻  %s", MAGENTA);
	ft_printf("✣%s    ☻ ☻       ☻ ☻ ☻ ☻ ☻ ☻   ☻ ☻       ☻ ☻ ☻        ✨  ",
		YELLOW);
	ft_printf("\n     ☻ ☻     ☻ ☻   ☻ ☻   ☻ ☻    ☻ ☻ ☻   ☻ ☻    ");
	ft_printf("   ☻ ☻       ☻ ☻     ☻ ☻   ☻ ☻       ☻ ☻  ☻      ");
	ft_printf("\n     ☻ ☻     ☻ ☻   ☻ ☻   ☻ ☻      ☻ ☻   ☻ ☻    ");
	ft_printf("   ☻ ☻       ☻ ☻     ☻ ☻   ☻ ☻ ☻ ☻   ☻ ☻    ☻    \n");
	ft_printf("%s\n✨———————————————————————————————————————————", MAGENTA);
	ft_printf("✣———————————————————————————————————————————————————✨");
	ft_printf("%s\n\n\t\t\t\t\tPID = %d\t\n", GREEN, serv_pid);
	ft_printf("%s\t\t\t\t✨ ────────────────────── ✨\n\n%s", MAGENTA,
		RESET_COLOR);
}
