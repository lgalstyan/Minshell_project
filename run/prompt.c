/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:16:22 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/25 15:37:03 by tyenokya         ###   ########.fr       */
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
	if (cmd[0] != '.')
		cmd = ft_strjoin("/", cmd);
	while (token[i])
	{
		cmd_accs = ft_strjoin(token[i], cmd);
		if (access(cmd_accs, 0) == 0)
			return (cmd_accs);
		i++;
	}
	return (cmd);
}

void	not_found_error(char *cmd, t_env **en)
{
	ft_putstr_fd("minishell: Command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	set_exit_code("127", en);
	exit (127);
}

static int	child_proc(t_node node, t_env **envir, char **ch_env)
{
	char	*path;
	char	*cmd;
	int		ret;

	rl_catch_signals = 0;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_IGN);
	ret = 0;
	path = search_list(*envir, "PATH");
	cmd = accses_to_exec(node.cmd[0], path);
	if (node.cmd[0][0] == '/' || node.cmd[0][0] == '.')
		ret = execve(node.cmd[0], node.cmd, ch_env);
	else
		ret = execve(cmd, node.cmd, ch_env);
	if (ret == -1)
		not_found_error(node.cmd[0], envir);
	return (ret);
}

void	status_wait(int status, int exec_status, t_env **en)
{
	if (WIFEXITED(status) && exec_status == 0)
		set_exit_code(ft_itoa(WEXITSTATUS(status)), en);
}

int	commands(t_node node, t_env **envir)
{
	int		exec_status;
	int		pid;
	int		status;
	char	**ch_env;

	exec_status = 0;
	ch_env = list_to_char(*envir);
	ft_redirs(&node);
	printf("💜\n");
	if (is_builtin(node.cmd[0]))
		exec_status = builtin(node, envir);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			exec_status = child_proc(node, envir, ch_env);
			if (exec_status < 0)
			{
				set_exit_code("127", envir);
				exit(127);
			}
		}
		wait(&status);
		status_wait(status, exec_status, envir);
		signal(SIGINT, &handler);
		signal(SIGQUIT, SIG_IGN);
	}
	return (exec_status);
}
