#include "minishell.h"

void	ft_close(int (*fd)[2], int len)
{
	int	i;

	i = 0;
	while(i < len)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

int nd_len(t_node *node)
{
	int res =0;
	while (node)
	{
		node = node->next;
		res++;
	}
	return(res);	
}

void    ft_pipe(t_node *node, t_env **envir)
{
	int		(*fds)[2];
    int   child;
	int	i;
	(void)envir;
	i = -1;
	fds = ft_calloc(sizeof(int*),  node->counts.s_pipe);
	while (++i < node->counts.s_pipe)
		pipe(fds[i]);
	i = 0;
	int n = nd_len(node);
		//printf("i : %d\n",nd_len(node));
	while (i < n)
	{
		child = fork();
		if (child == -1)
        {
            perror("fork");
            exit(1);
        }
		if (child == 0)
		{
			if (i == 0)
				dup2(fds[i][1], 1);
			else if (i == node->counts.s_pipe )
				dup2(fds[i - 1][0], 0);
			else
			{
				dup2(fds[i - 1][0], 0);
				dup2(fds[i][1], 1);
			}
			ft_close(fds, node->counts.s_pipe);
			prompt(*node, envir);
			exit(1);
		}
		i++;
		node = node->next;
	}
	ft_close(fds, node->counts.s_pipe);
	while(wait(0) != -1)
		;
}