#include "minishell.h"

int ft_lst_size(t_env *env)
{
	int i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return(i);
}

char	**list_to_char(t_env *env)
{
	int i;
	char **res;
	res = malloc(sizeof(char *) * ft_lst_size(env) + 1);
	i = 0;
	while (env)
	{
		if(env->key)
		res[i] = ft_strjoin(env->key, "=");
		if(env->value)
		res[i] = ft_strjoin(res[i], env->value);
		i++;
		env = env->next;
	}
	return(res);
}

