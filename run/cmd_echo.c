#include "minishell.h"

int	check_valid(char c)
{
	if(c == '_' || (c > 47 && c < 58) || 
			(c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}

void var_values(char *str, t_env *en)
{
	while (en)
	{
		if (!ft_strcmp(en->key, str))
			printf("%s", en->value);
		en = en->next;
	}
}

void	ft_strfind(char  *str, t_env **en)
{
	int	i;
	int start;
	char *word;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if(str[i] == '$')
		{
			i++;
			start = i;
			while (check_valid(str[i]))
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

//echo " Hello my name is $SHELL $a

void cmd_echo(t_node node, t_env **en)
{
	int		flag;
	
	flag = 1;
	if (!node.cmd[1])
	{
		printf("\n");
		return ;
	}
	if (!ft_strcmp(node.cmd[1], "-n"))
	{
		flag = 2;
		if (!node.cmd[2])
			return ;
	}
	ft_strfind(node.cmd[flag], en);
	if (flag == 1)
		printf("\n");
}