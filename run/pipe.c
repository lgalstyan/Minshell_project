#include "minishell.h"

void    ft_pipe(t_node *node, t_env **envir)
{
    // int     fd[2];
	// int		*fd_arrays;
    pid_t   child;
    t_node  *curr;
	int	i = 0;
    curr = node;
	// fd_arrays = malloc(sizeof(t_));
    if (!curr->next)
        prompt(*curr, envir);
    else
    {
	    while (curr && i < 2)
        {
            child = fork();
            if (child == -1)
            {
                perror("fork");
                exit(1);
            }
            if (child == 0)
            {
                prompt(*curr, envir);
            }
            curr = curr->next;
			i++;
        }
    }
}