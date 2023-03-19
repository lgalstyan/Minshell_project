#include "minishell.h"

void	ignore_single_quotes(char *str, int *i)
{
	if (str[*i] == '\'')
	{
		while (str[++*i] && str[*i] != '\'')
			++*i;
	}
	if (!str[*i])
		return ;
}

void	ignore_double_quotes(char *str, int *i)
{
	if (str[*i] == '\"')
	{
		while (str[++*i] && str[*i] != '\"')
			++*i;
	}
	if (!str[*i])
		return ;
}

int	dollarlen(char *s, int i)
{
	int	len;

	len = 0;
	while (s && s[i] && s[i + len]
		&& !ft_strchr(METACHARACTERS, s[i + len] && s[i + len] != '\"'
			&& s[i + len] != '\''))
	{
		++len;
		if (s[i + len] == '$')
			break ;
	}
	return (len);
}

char	*if_changes(char *cmd, t_env **env, int i)
{
	int		len;
	char	*strrrr;
	char	*str;

	strrrr = 0;
	str = 0;
	len = dollarlen(cmd, i);
	str = ft_substr(cmd, i + 1, len - 1);
	strrrr = ft_strdup(cmd);
	if (cmd)
		free(cmd);
	cmd = ft_fill(strrrr, i, i + len,
			replace(strrrr, i + 1, i + len - 1, *env));
	free(str);
	str = 0;
	strrrr = 0;
	return (cmd);
}

char	*change(char *str, t_env **en, int i)
{
	while (str && str[i] && str[i + 1])
	{
		if (str[i] && str[i] == '$' && (str[i + 1] == '_'
				|| str[i + 1] == '\"' || str[i + 1] == '\''
				|| ft_isalpha(str[i + 1]) || str[i + 1] == '?'))
		{
			str = if_changes(str, en, i);
		}
		if (!str || str[i] == '\0')
			break ;
		++i;
	}
	return (str);
}
