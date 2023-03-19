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

void	exit_normal(char *str)
{
	long long	num;

	num = 0;
	if (check_longlongd(str))
	{
		num = ft_atoi(str);
		if (num < 0)
		{
			ft_putstr_fd("exit\n", 2);
			exit(256 - (num * (-1) % 256));
		}
		else if (num >= 0)
		{
			ft_putstr_fd("exit\n", 2);
			exit(num % 256);
			g_exit_code = num % 256;
		}
	}
	else
	{
		ft_putstr_fd("minishell: :exit: numeric argument required\n", 2);
		ft_putstr_fd("exit\n", 2);
		exit(255);
	}
	free(str);
}

void	cmd_exit(char **cmd, t_env **en)
{
	char	*str;

	if (!cmd[1])
	{
		ft_putstr_fd("exit\n", 2);
		exit(get_exit_code(en));
	}
	if (cmd[1] && !ft_isdigit(cmd[1]))
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: :exit: numeric argument required\n", 2);
		set_exit_code("255", en);
		exit(get_exit_code(en));
	}
	if (cmd[2] && ft_isdigit(cmd[1]))
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: :exit: too many arguments: \n", 2);
		set_exit_code("1", en);
		return ;
	}
	str = ft_cat_str(cmd[1]);
	exit_normal(str);
}
