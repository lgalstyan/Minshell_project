/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:16:22 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/20 16:16:39 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*accses_to_exec(char *cmd, char *path)
{
	int		i;
	char	**token;
	char	*cmd_accs;

	i = -1;
	write(1, "Hello malmlo\n", 13);
	token = ft_split(path, ':');
	write(1, "after  Hello malmlo\n", 13);
	while (token[++i])
	{
		cmd_accs = ft_strjoin(token[i], cmd);
		if (access(cmd_accs, 0))
			return (cmd_accs);
	}
	return (cmd);
}

int	prompt(t_node node, t_env **envir, char **env)
{
	char	*cmd;
	char	*path;
	int		st;

	st = 0;
	st = builtin(node, envir);
	path = search_list(*envir, node.cmd[0]);
	if (!path)
		printf("path-y chka\n");
	if (path)
	{
		cmd = accses_to_exec(node.cmd[0], path);
		execve(cmd, node.cmd, env);
	}
	return (st);
}
