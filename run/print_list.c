#include "minishell.h"

void print_list(t_env **node)
{
	while(*(node))
	{
		printf("%s=", (*node)->key);
		printf("%s\n", (*node)->value);
		(*node) = (*node)->next;
	}
}