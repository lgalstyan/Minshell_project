#include "minishell.h"

void	pluse_equal(char *new_env, t_env **en)
{
	char 	**array;
	t_env	*curr;

	array = ft_split(new_env, '+');
	curr = *en;
	if (!array[1] || !(*array[1]++))
		return ;
	while (curr)
	{
		if (ft_strcmp(curr->key, array[0]))
			return ;
		else
		{
			curr->value = ft_strjoin(curr->value, array[1]);
		}
		curr = curr->next;
	}
}

//hashvarkac choi vor kara "=" i koxqy space lini, zut split a anum = ov
void	equal_only(char *new_env, t_env **en)
{
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
	if (!array[1])
		return ;
	if (!flag)
	{
		new_node = malloc(sizeof(t_env));
		ft_inint_env(array[0], array[1], new_node);
		ft_lstadd_back(en, new_node);
	}
}

void	cmd_export(char *new_env, t_env **en)
{
	if (!new_env)
		return ;
	if (ft_strnstr(new_env, "+=", ft_strlen(new_env)))
		pluse_equal(new_env, en);
	else
		equal_only(new_env, en);
}
