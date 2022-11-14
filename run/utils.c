#include "minishell.h"

static t_env	*ft_lstlast(t_env *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*back;

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