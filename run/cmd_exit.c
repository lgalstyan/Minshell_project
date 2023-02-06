/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:59:01 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 17:34:27 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	exit_normal(char **cmd)
{
	long long	dig;

	dig = ft_atoi(cmd[1]);
	if (dig < 0)
	{
		ft_putstr_fd("exit\n", 2);
		exit_code = 256 - (dig * (-1)) % 256;
		exit(256 - (dig * (-1)) % 256);
	}
	else
	{
		ft_putstr_fd("exit\n", 2);
		exit_code = dig % 256;
		exit(dig % 256);
	}
}

void	cmd_exit(char **cmd)
{
	if (!cmd[1])
	{
		ft_putstr_fd("exit\n", 2);
		exit(exit_code);
	}
	if (cmd[1] && (!(ft_isdigit(cmd[1][0]) || cmd[1][0] == '-')
		|| (ft_strlen(cmd[1]) == 19 && (cmd[1][ft_strlen(cmd[1]) - 1] == '8'
		|| cmd[1][ft_strlen(cmd[1]) - 1] == '9'))))
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: :exit: numeric argument required\n", 2);
		exit_code = 255;
		exit(exit_code);
	}
	if (cmd[2])
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: :exit: too many arguments: \n", 2);
		exit_code = 1;
		return ;
	}
	exit_normal(cmd);
}
// void	cmd_exit(char **cmd)
// {
// 	int	dig;
// 	dig = 255;
// 	if (cmd[1] && (ft_isdigit(cmd[1][0]) || cmd[1][0] == '-'))
// 	{
// 		dig = ft_atoi(cmd[1]) % 256;
// 		printf("exit\n");
// 		exit(dig);
// 	}
// 	else if (cmd[1])
// 	{
// 		printf("exit\n");
// 		printf("minishell: :exit: %s: numeric argument required\n", cmd[1]);
// 		exit(0);
// 	}
// 	else
// 	{
// 		printf("exit\n");
// 		exit(0);
// 	}
// }
