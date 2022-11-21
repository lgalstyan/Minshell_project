#include "minishell.h"

void	cmd_unset(char *del_env, t_env **env)
{
	t_env	*curr;
	t_env	*delet;

	curr = (*env);
	while (curr->next)
	{
		if (!ft_strcmp(curr->next->key, del_env))
		{
			delet = curr->next;
			if (!curr->next->next)
				curr->next = NULL;
			else
				curr->next = curr->next->next;
			free(delet);
		}
		if (curr->next)
		curr = curr->next;
	}
}
