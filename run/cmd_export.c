#include "minishell.h"

//hashvarkac choi vor kara "=" i koxqy space lini, zut split a anum = ov
void	equal_only(char **array, t_env **en)
{
	t_env	*new_node;
	t_env	*curr;
	int		flag = 0;

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

void	pluse_equal(char **array, t_env **en)
{
	int		flag;
	t_env	*curr;

	flag = 0;
	curr = *en;
	if (!array[1])
		return ;
	while (curr)
	{
		if (!ft_strcmp(curr->key, array[0]))
		{
			curr->value = ft_strjoin(curr->value, array[1]);
			flag = 1;
		}
		curr = curr->next;
		if (flag)
			return ;
		if (!curr && !flag)
			equal_only(array, en);
	}
}

int	check_valid_identif(char *str)
{
	int		i;
	char	**array;

	i = 0;
	if (ft_strnstr(str, "+=", ft_strlen(str)))
	{
		array = ft_split(str, '+');
		++i;
	}
	else
		array = ft_split(str, '=');
	while (array[0][i])
	{
		if(!check_valid(array[0][i]))
			return (0);
		++i;
	}
	return 1;
}

void	cmd_export(char *new_env, t_env **en)
{
	char	**array;

	if (!new_env)
		return ;
	if(!check_valid_identif(new_env))
	{
		printf("export: `%s': not a valid identifier\n", new_env);
		return ;
	}
	if (ft_strnstr(new_env, "+=", ft_strlen(new_env)))
	{
		array = ft_split(new_env, '+');
		array[1]++;
		pluse_equal(array, en);
	}
	else
	{
		array = ft_split(new_env, '=');
		equal_only(array, en);
	}
}
