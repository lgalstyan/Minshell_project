#include "minishell.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*back;

	back = *lst;
	if (!(lst))
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		back = ft_lstlast(*lst);
		back->next = new;
	}
}