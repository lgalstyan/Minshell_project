/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:26:33 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/09 16:26:33 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_quit(int sig)
// {
// 	(void)sig;
// 	exit(1);
// }
// void handler(int sig)
// {
// 	(void)sig;
// 	//write(1,"\n",1);
// 	// rl_done = 1;
// 	write(1,"\n",1);
// 	//rl_clear_visible_line();
// 	rl_replace_line("",0);
// 	rl_on_new_line();
// 	rl_redisplay();

// }
void	handler(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	rl_done = 1;
}
