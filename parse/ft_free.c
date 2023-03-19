#include "minishell.h"

void	free_str(char **line)
{
	int	i;

	if (!line)
		return ;
	i = -1;
	while (line[++i])
	{
		if (line[i])
		{
			free(line[i]);
			line[i] = 0;
		}
	}
	free(line);
	line = 0;
}

void	list_free(t_node *list)
{
	t_node	*hook;
	t_node	*data;

	data = list;
	while (data)
	{
		hook = data->next;
		if (data->cmd)
			free_str(data->cmd);
		if (data->infile)
			free_str(data->infile);
		if (data->outfile)
			free_str(data->outfile);
		if (data->append)
			free_str(data->append);
		if (data->heredoc)
			free_str(data->heredoc);
		free(data->readline);
		free(data);
		data = NULL;
		data = hook;
	}
	data = NULL;
}

void	pars_free(t_node **head, char **line)
{
	list_free(*head);
	free(*line);
	*line = 0;
}

int	ft_check_ignore_quotes(char **str, int *i)
{
	while ((*str)[*i] == '"')
	{
		while ((*str)[++*i] != '"')
			;
		if ((*str)[*i])
			++*i;
	}
	while ((*str)[*i] == '\'')
	{
		while ((*str)[++*i] != '\'')
			;
		if ((*str)[*i])
			++*i;
	}
	if (!((*str)[*i]))
		return (1);
	else
		return (0);
}
