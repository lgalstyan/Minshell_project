#include "minishell.h"

void print_list(t_env **node)
{
	t_env	*curr;

	curr = (*node);
	while(curr)
	{
		printf("%s=", curr->key);
		printf("%s\n", curr->value);
		curr = curr->next;
	}
}