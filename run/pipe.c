/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:44:07 by lgalstya          #+#    #+#             */
/*   Updated: 2023/03/21 16:22:36 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close(int (*fd)[2], int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

static void	child_process(t_node *node, int (*fds)[2], int i, int n)
{
	if (i == 0)
		dup2(fds[0][1], 1);
	else if (i == n - 1 && *node->heredoc)
		dup2(fds[i][0], 0);
	else if (i == n - 1)
		dup2(fds[i - 1][0], 0);
	else
	{
		if (i == n - 1 && *node->heredoc)
			dup2(fds[i][0], 0);
		if (i == n - 1)
			dup2(fds[i - 1][0], 0);
		dup2(fds[i][1], 1);
	}
	ft_close(fds, n);
}

static void	ft_filedisc_init(int (*fds)[2], int n)
{
	int	i;

	i = -1;
	while (++i < n - 1)
		pipe(fds[i]);
}

void	ft_wait(int n, t_env **env, int	*pid, int (*fds)[2])
{
	int		ret;
	int		i;
	char	*tmp;

	i = -1;
	tmp = 0;
	while (++i < n - 1)
	{
		waitpid(pid[i], &ret, 0);
		if (WIFEXITED(ret) != 0)
		{
			tmp = ft_itoa(WEXITSTATUS(ret));
			set_exit_code(tmp, env);
			free(tmp);
		}
	}
	free(pid);
	free(fds);
}

typedef struct s_data
{
	int			(*fds)[2];
	int			child;
	int			i;
	int			*pid;
	int			out;
	int			in;
}				t_data;

void	ft_pipe(t_node *node, t_env **envir, int n)
{
	t_data	data;

	data.i = -1;
	data.fds = ft_calloc(sizeof(int *), n - 1);
	data.pid = malloc(sizeof(int) * n);
	data.in = dup(0);
	data.out = dup(1);
	ft_filedisc_init(data.fds, n);
	while (++data.i < n)
	{
		ft_redirs(node);
		data.pid[data.i] = fork();
		ft_error_fork(data.pid[data.i], data.i, node);
		if (data.pid[data.i] == 0)
		{
			child_process(node, data.fds, data.i, n);
			data.child = command_for_pipe(*node, envir);
			free_node_for_pipe(node, data.child);
		}
		node = node->next;
		dup2(data.in, 0);
		dup2(data.out, 1);
	}
	ft_close(data.fds, n);
	ft_wait(n, envir, data.pid, data.fds);
}
