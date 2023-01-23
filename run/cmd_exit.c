/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:59:01 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/23 12:12:07 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_exit(char **cmd)
{
	int	dig;
	
	dig = 255;
	if (cmd[1] && (ft_isdigit(cmd[1][0]) || cmd[1][0] == '-'))
	{
		dig = ft_atoi(cmd[1]) % 256;
		printf("exit\n");
		exit(dig);
	}
	else if (cmd[1])
	{
		printf("exit\n");
		printf("minishell: :exit: %s: numeric argument required\n", cmd[1]);
		exit(0);
	}
	else
	{
		printf("exit\n");
		exit(0);
	}
}
