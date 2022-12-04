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

static void print_list_added(t_env **node)
{
	t_env	*curr;

	curr = (*node);
	while(curr)
	{
		printf("declare -x %s=", curr->key);
		printf("\"%s\"\n", curr->value);
		curr = curr->next;
	}
}

void sortList(t_env **env)
{
    t_env	*current = *env;
	t_env	*index = NULL;  
    char	*temp;  
      
    if(env == NULL)
        return;  
    while(current != NULL) {  
        index = current->next;  
        while(index != NULL) { 
            if(ft_strcmp(current->key, index->key) > 0)
			{  
                temp = current->key;  
                current->key = index->key;  
                index->key = temp;  
            }  
            index = index->next;  
        }  
        current = current->next;       
    }
	print_list_added(env);
}