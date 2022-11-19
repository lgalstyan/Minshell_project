#ifndef MINISHELL
#define MINISHELL

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "commands.h"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

typedef struct s_node
{
	char			**heardock;
	char			**append; //  <<
	char			**infile; // >
	char			**outfile; // <
	char 			**cmd;
	struct s_node	*next;
}			t_node;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct	s_env	*next;
}			t_env;

void	ft_lstadd_back(t_env **lst, t_env *new);
void	switch_commands(t_node node, t_env **en);
void	cmd_pwd();
void	cmd_echo(t_node n, t_env **en);
void	ft_strfind(char  *str, t_env **en);
char	**ft_split(char *s, char c);


#endif
