#include "minishell.h"

int	check_valid(char c)
{
	if (c == '_' || (c > 47 && c < 58)
		|| (c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}

void	var_values(char *str, t_env *en)
{
	while (en)
	{
		if (!ft_strcmp(en->key, str))
			printf("%s", en->value);
		en = en->next;
	}
}

void	ft_strfind(char *str, t_env **en)
{
	int		i;
	int		start;
	char	*word;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (!str[i + 1] || (is_space(str[i]) && i++))
				printf("$");
			if (str[++i] == '?' && i++)
			{
				print_exit_code();
				printf("%s", str + i);
				return ;
			}
			start = i;
			while (str[i] && check_valid(str[i]))
				i++;
			word = ft_substr(str, start, i - start);
			var_values(word, *en);
		}
		else
		{
			printf("%c", str[i]);
			++i;
		}
	}
}