/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:16:22 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/21 17:25:33 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*accses_to_exec(char *cmd, char *path)
{
	int		i;
	char	**token;
	char	*cmd_accs;

	i = 0;
	token = ft_split(path, ':');
	cmd = ft_strjoin("/", cmd);
	while (token[i])
	{
		cmd_accs = ft_strjoin(token[i], cmd);
		if (access(cmd_accs, 0) == 0)
		{
			return (cmd_accs);
		}
		i++;
	}
	return (cmd);
}

// int is_builtin(char *cmd)
// {
// 	if (!(ft_strcmp(cmd, "echo")) || !(ft_strcmp(cmd, "pwd"))
// 		|| !(ft_strcmp(cmd, "unset")) || !(ft_strcmp(cmd, "exit"))
// 		|| !(ft_strcmp(cmd, "cd")) || !(ft_strcmp(cmd, "export"))
// 		|| !(ft_strcmp(cmd, "env")))
// 		return (1);
// 	return (0);
// }

int	prompt(t_node node, t_env **envir, char **env)
{
	char	*cmd;
	char	*path;
	int		st;
	int		exec_status;
	int		pid;

	st = 0;
	if (is_builtin(node.cmd[0]))
		st = builtin(node, envir);
	else
	{
		pid = fork();
		if (!pid)
		{
			path = search_list(*envir, "PATH");
			printf("%s\n", path);
			cmd = accses_to_exec(node.cmd[0], path);
			exec_status = execve(cmd, node.cmd, env);
			if (exec_status == -1)
				printf("Syntax error\n");
		}
		wait(0);
	}
	return (st);
}
