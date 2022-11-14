#include "minishell.h"
// find all values of varable and change. 
static void var_init(char *str)
{

	printf("%s", str);
}

// char *ft_strfind(char  *str, char c)
// {
// 	int	i;
// 	int start;
// 	char *word;

// 	word = malloc(100);
// 	i = 0;
// 	while(str[i])
// 	{
// 		if(str[i] == c)
// 		{
// 			start = i + 1;
// 			while(str[i] == ' ' || str[i] == '\t')
// 				i++;
// 			if(ft_substr(str, start, i - start + 1))
// 				;
// 		}
// 		else
// 		{
// 			printf("%c", str[i]);
// 		}
// 		++i;
// 	}
// 	return 0;
// }

void cmd_echo(t_node node)
{
	int flag;
	
	flag = 1;
	if (!ft_strcmp(node.cmd[1], "-n"))
		flag = 2;
	//if (!ft_strfind(node.cmd[flag], '$'))
	if(!ft_strnstr(node.cmd[flag], "$", ft_strlen(node.cmd[flag])))
	{
		var_init(node.cmd[flag]);
	}
	else
	{
		printf("%s", node.cmd[flag]);
	}
	if (flag == 2)
		printf("\n");
}