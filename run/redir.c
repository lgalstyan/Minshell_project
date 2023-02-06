/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:42:54 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 17:42:56 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

// void	cmd_infile(char *file, int flag)
// {
// 	int	fd;

// 	fd = open(file, O_RDONLY, 0644);
// 	if (fd < 0)
// 		perror("minishell : no such file or directori");
// 	if (flag == 1)
// 		dup2(fd, 0);
// 	close(fd);
// }

// void	cmd_outfile(char *file, int flag)
// {
// 	int	fd;

// 	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	if (flag == 1)
// 		dup2(fd, 1);
// 	close(fd);
// }

// void	cmd_append(char *file, int flag)
// {
// 	int	fd;

// 	fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
// 	if (flag == 1)
// 		dup2(fd, 1);
// 	close(fd);
// }

// void	ft_print_hered(char *line, int fd)
// {
// 	write(fd, line, pars_ft_strline(line));
// 	write(fd, "\n", 1);
// 	free(line);
// 	line = NULL;
// }

// // void	ft_heredoc(int	fd, char *file, int flag)
// // {
// // 	if (flag == 1)
// // 	{
// // 		close();
// // 		dup
// // 	}
// // }

// void	cmd_heredoc(char *str)
// {
// 	int		fd;
// 	char	*file;
// 	char	*line;

// 	file = ft_strjoin(".", file);
// 	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
// 	while (1)
// 	{
// 		line = readline("> ");
// 		if (!ft_strcmp(line, str))
// 			break;
// 		ft_print_hered(line, fd);
// 	}
// 	dup2(fd, 1);
// 	close(fd);
// }
