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
