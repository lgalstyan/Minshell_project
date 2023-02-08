#include "minishell.h"

void    ft_heredoc(t_node *node)
{
    int i;

    i = -1;
    if (*node->heredoc)
    {
        while (node->heredoc[++i])
        {
            if (i == ft_arrlen(node->heredoc) - 1)
                heredoc(node->heredoc[i]);
			else
				heredoc_not(node->heredoc[i]);
        }
    }

}

void	ft_infile(t_node *node)
{
	int	i;

	i = -1;
	if (*node->infile)
	{
		while (node->infile[++i])
		{
			if (i == ft_arrlen(node->infile) - 1)
				cmd_infile(node->infile[i], 0);
			else
				cmd_infile(node->infile[i], 1);
		}
	}
}

void	ft_outfile(t_node *node)
{
	int	i;

	i = -1;
	if (*node->outfile)
	{
		while (node->outfile[++i])
		{
			if (i == ft_arrlen(node->outfile) - 1)
				cmd_outfile(node->outfile[i], 1);
			else
				cmd_outfile(node->outfile[i], 0);
		}
	}
}

void	ft_append(t_node *node)
{
	int	i;

	i = -1;
	if (*node->append)
	{
		while (node->append[++i])
		{
			if (i == ft_arrlen(node->append) - 1)
				cmd_append(node->append[i], 1);
			else
				cmd_append(node->append[i], 0);
		}
    }
}	

void    ft_redirs(t_node *node)
{
    ft_heredoc(node);
	ft_infile(node);
	ft_outfile(node);
	ft_append(node);

}