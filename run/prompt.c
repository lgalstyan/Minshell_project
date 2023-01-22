/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:16:22 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/22 12:31:09 by lgalstya         ###   ########.fr       */
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

int	prompt(t_node node, t_env **envir)
{
	char	*cmd;
	char	*path;
	int		st;
	int		exec_status;
	int		pid;
	char	**ch_env;

	st = 0;
	printf("cmd1=%s_end\n", node.cmd[0]);
	if (node.cmd[1])
		printf("cmd2=%s_end\n", node.cmd[1]);	
	ch_env = list_to_char(*envir);
	if (is_builtin(node.cmd[0]))
		st = builtin(node, envir);
	else
	{
		pid = fork();
		if (!pid)
		{
			path = search_list(*envir, "PATH");
			cmd = accses_to_exec(node.cmd[0], path);
			exec_status = execve(cmd, node.cmd, ch_env);
			if (exec_status == -1)
				printf("Syntax error\n");
		}
		wait(0);
	}
	return (st);
}
