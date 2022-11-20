#include "minishell.h"



void	cmd_export(char *new_env, t_env **en)
{
	//hashvarkac choi vor kara "=" i koxqy space lini, zut split a anum = ov
	char 	**array;
	t_env	*new_node;
	t_env	*curr;
	int flag = 0;

	array = ft_split(new_env, '=');
	curr = *en;
	while (curr)
	{
		if (!ft_strcmp(curr->key, array[0]))
		{
			curr->value = array[1];
			flag = 1;
		}
		curr = curr->next;
	}
	if (!new_env || !array[1])
		return ;
	if (!flag)
	{
		new_node = malloc(sizeof(t_env));
		ft_inint_env(array[0], array[1], new_node);
		ft_lstadd_back(en, new_node);
	}
}