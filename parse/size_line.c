#include "parser.h"
// #include "minishell.h"

int	ft_infile_count(char *line) // <
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (line && line[++i])
	{
		if (line[i] == '<' && line[i + 1] == '<')
			while (line[i] == '<')
				++i;
		if (line[i] == '<' && line[i + 1] != '<')
			++count;
	}
	return (count);
}

int	ft_outfile_count(char *line) // >
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (line && line[++i])
	{
		if (line[i] == '>' && line[i + 1] == '>')
			while (line[i] == '>')
				++i;
		if (line[i] == '>' && line[i + 1] != '>')
			++count;
	}
	return (count);
}

int	ft_heredoc_count(char *line) // <<
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (line && line[++i])
	{
		if (line[i] == '<' && line[i + 1] == '<')
			++count;
		while (line[i] == '<')
			++i;
	}
	return (count);
}

int	ft_append_count(char *line) // >>
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (line && line[++i])
	{
		if (line[i] == '>' && line[i + 1] == '>')
			++count;
		while (line[i] == '>')
			++i;
	}
	return (count);
}

int	ft_all_redir_size(t_node *node)
{
	int	res;

	res = 0;
	res += node->counts.s_append;
	res += node->counts.s_heredoc;
	res += node->counts.s_infile;
	res += node->counts.s_outfile;
	return (res);
}

int	ft_size_all(char *str)
{
	int	i;
	int	count;
	int	f1;
	int	f2;
	int	f3;

	i = 0;
	f1 = 0;
	f2 = 0;
	f3 = 0;
	count = 0;
	while (str && str[i])
	{
		ignore_quotes(str);
		while (!is_meta(str[i]) && i++)
			f1 = 1;
		while (str && str[i] == '<' && i++)
			f2 = 1;
		while (str && str[i] == '>' && i++)
			f3 = 1;
		while(str && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		{
			if ((f1 == 1 && count++ && (f1 = 0)) || (f2 == 1 && count++ && (f2 = 0))
				|| (f3 == 1 && count++ && (f3 = 0)))
				;
			i++;
		}
			i++;
	}
	return (count);
}