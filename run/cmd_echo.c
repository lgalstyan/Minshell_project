#include "minishell.h"
// find all values of varable and change. 
// static void var_init(char *str)
// {

// 	printf("%s", str);
// }

int	check_valid(char c)
{
	if(c == '_' || (c > 47 && c < 58) || 
			(c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}

void var_values(char *str, t_env *en)
{
	// printf("Ayoooooooooo\n");
	// printf("%s_", str);
	while (en)
	{
		// printf("\n%s_%s_", en->key, str);
		// printf("%d", ft_strcmp(en->key, str));
		if (!ft_strcmp(en->key, str))
		{
			printf("%s", en->value);
		}
		en = en->next;
	}
}

void	ft_strfind(char  *str, t_env **en)
{
	int	i;
	int start;
	char *word;

	i = 0;
	while(str[i])
	{
		if(str[i] == '$')
		{
			// printf("$/ start, %d \n", i);
			i++;
			start = i;
			while (check_valid(str[i]))
				i++;
			word = ft_substr(str, start, i - start);
			// printf("%s", word);
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
	// char	*tmp;
	
	flag = 1;
	if (!ft_strcmp(node.cmd[1], "-n"))
		flag = 2;
	ft_strfind(node.cmd[flag], en);
	if (flag == 1)
		printf("\n");
}






	
	// //printf("%s", ft_strnstr(node.cmd[flag], "$", ft_strlen(node.cmd[flag])));
	// //if(!ft_strnstr(node.cmd[flag], "$", ft_strlen(node.cmd[flag])))
	// //{
	// //	var_init(node.cmd[flag]);
	// //}
	// else
	// {
	// 	printf("%s", node.cmd[flag]);
	// }