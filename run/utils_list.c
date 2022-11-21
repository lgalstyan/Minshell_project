#include "minishell.h"

char	search_list(t_env *env, char* key)
{
	while (env)
	{
		if (!ft_strcmp(env->key, key))
		{
			return (*env->value);
		}
		env = env->next;
	}
	return (0);
}

void	delete_list(t_env **env)
{
	t_env	*tmp;

	while (*env)
	{
		tmp = (*env);
		(*env) = (*env)->next;
		free(tmp);
	}
	// free(env);
	return ;
}