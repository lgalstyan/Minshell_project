/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:06:25 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/15 16:21:23 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	put_in(t_node *node, char *str, int s)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(str);
	while (str[s] && s < l)
	{
		if (str[s] && str[s] != ' ')
		{
			printf("str+s = %s\n", str+s);
			node->infile[i] = ft_strdup(str + s);
			printf("infile[%d] = %s\n", i, node->infile[i]);
			s += ft_strlen(node->infile[i]);
		}
		if (str[s] != ' ' && str[s])
		{
			ft_strcpy(node->infile[i], str + s);
			write(1, &*node->infile[i], 1);
			s += ft_strlen(node->infile[i]);
		}
		else
			return(s);;
		++i;
		++s;
	}
	return (s);
}


int	put_out(t_node *node, char *str, int s)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(str);
	node->outfile = malloc(sizeof(char *));
	while (str[s] && s < l)
	{
		if (str[s] && str[s] != ' ')
		{
			printf("str+s = %s\n", str+s);
			if(node->outfile[i] && str + s)
				printf("baby\n");
			node->outfile[i] = ft_strdup(str + s);
			printf("outfile[%d] = %s\n", i, node->outfile[i]);
			s += ft_strlen(node->outfile[i]);
		}
		if (str[s] != ' ' && str[s])
		{
			ft_strcpy(node->outfile[i], str + s);
			write(1, &*node->outfile[i], 1);
			s += ft_strlen(node->outfile[i]);
		}
		else
			return(s);;
		++i;
		++s;
	}
	return (s);
}


int	put_hd(t_node *node, char *str, int s)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(str);
	node->heardock = malloc(sizeof(char *));
	while (str[s] && s < l)
	{
		if (str[s] && str[s] != ' ')	
		{
			printf("str+s = %s\n", str+s);
			node->heardock[i] = ft_strdup(str + s);
			printf("heardock[%d] = %s\n", i, node->heardock[i]);
			s += ft_strlen(node->heardock[i]);
		}
		if (str[s] != ' ' && str[s])
		{
			ft_strcpy(node->heardock[i], str + s);
			write(1, &*node->heardock[i], 1);
			s += ft_strlen(node->heardock[i]);
		}
		else
			return(s);;
		++i;
		++s;
	}
	return (s);
}


int	put_ap(t_node *node, char *str, int s)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(str);
	node->append = malloc(sizeof(char *));
	while (str[s] && s < l)
	{
		if (str[s] && str[s] != ' ')	
		{
			printf("str+s = %s\n", str+s);
			node->append[i] = ft_strdup(str + s);
			printf("append[%d] = %s\n", i, node->append[i]);
			s += ft_strlen(node->append[i]);
		}
		if (str[s] != ' ' && str[s])
		{
			ft_strcpy(node->append[i], str + s);
			write(1, &*node->append[i], 1);
			s += ft_strlen(node->append[i]);
		}
		else
			return(s);
		++i;
		++s;
		}
	return (s);
}
