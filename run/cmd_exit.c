/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:59:01 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/22 16:36:20 by lgalstya         ###   ########.fr       */
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
		exit(dig);
	}
	else if (cmd[1])
	{
		printf("exit: %s: numeric argument required\n", cmd[1]);	
	}
	else
	{
		exit(0);
	}
}
