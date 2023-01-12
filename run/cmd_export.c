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
	if (!array[1]){
		array[1] = "";
	}
	if (!flag)
	{
		new_node = malloc(sizeof(t_env));
		ft_inint_env(array[0], array[1], new_node);
		ft_lstadd_back_env(en, new_node);
	}
}

void	pluse_equal(char **array, t_env **en)
{
	int		flag;
	t_env	*curr;

	flag = 0;
	curr = *en;
	if (!array[1])
		array[1] = "";
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
		printf("hello_%s_\n", array[1]);
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

static void	add_only(char *array, t_env **en)
{
	t_env	*new_node;
	t_env	*curr;
	int		flag = 0;

	curr = *en;
	while (curr)
	{
		if (!ft_strcmp(curr->key, array))
			flag = 1;
		curr = curr->next;
	}
	if (!flag)
	{
		new_node = malloc(sizeof(t_env));
		ft_inint_env(array, NULL, new_node);
		ft_lstadd_back_env(en, new_node);
	}
}

static int	check_pluse_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' && str[i + 1] != '=')
			return (0);
		i++;
	}
	return (1);
}

void	cmd_export(t_node new_env, t_env **en)
{
	char	**array;

	if (!new_env.cmd[1])
	{
		sortList(en);
		return ;
	}
	if(!check_valid_identif(new_env.cmd[1]) || (new_env.cmd[1][0] > 47 && new_env.cmd[1][0] < 58))
	{
		printf("export: `%s': not a valid identifier\n", new_env.cmd[1]);
		return ;
	}
	else if (ft_strnstr(new_env.cmd[1], "+=", ft_strlen(new_env.cmd[1])))
	{
		if (!check_pluse_equal(new_env.cmd[1]))
		{
			printf("export: `%s': not a valid identifier\n", new_env.cmd[1]);
			return ;
		}
		array = ft_split_export(new_env.cmd[1], '+');
		array[1]++;
		pluse_equal(array, en);
	}
	else if (ft_strnstr(new_env.cmd[1], "=", ft_strlen(new_env.cmd[1])))
	{
		array = ft_split_export(new_env.cmd[1], '=');
		equal_only(array, en);
	}
	else
	{
		add_only(new_env.cmd[1], en);
	}
}
//export a => env NULL, export => declare -x a
//export a=1=1=1=1
//export a=23 b=54 c=98
//errorneric el a++=2, ete demic tiv 
