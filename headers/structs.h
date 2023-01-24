#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_size
{
	int			s_infile;	//<
	int			s_outfile;	//>
	int			s_heredoc;	//<<
	int			s_append;	//>>
}				t_size;

typedef struct s_node
{
	t_size			counts;
	char			*readline;
	char			**heredoc;
	char			**append;
	char			**infile;
	char			**outfile;
	char			**cmd;
	int				*redir;
	struct	s_node	*next;
}					t_node;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}			t_env;

#endif