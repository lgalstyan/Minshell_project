#include "minishell.h"

void exit_minishell(t_env **en)
{
	delete_list(en);
	exit(0);
}