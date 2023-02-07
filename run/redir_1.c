#include "minishell.h"

void    ft_heredoc()
{
    ini i;

    i = -1;
    if (*node->heredoc)
    {
        while (*node->heredoc[++i])
        {
            if (i == arr_len(node->heredoc) - 1)
                heredoc_redirect(node->heredoc[i], &node);
			else
				heredoc_no_redirect(node->heredoc[i]);
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
			if (i == arr_len(node->infile) - 1)
				infile_redir(node->infile[i], node);
			else
				infile_no_redir(node->infile[i], node);
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
			if (i == arr_len(node->outfile) - 1)
				outfile(node->outfile[i]);
			else
				no_outfile(node->outfile[i]);
		}
	}
}

void	ft_append(t_main *node)
{
	int	i;

	i = -1;
	if (*node->append)
	{
		while (node->append[++i])
		{
			if (i == arr_len(node->append) - 1)
				append_redir(node->append[i]);
			else
				append_no_redir(node->append[i]);
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