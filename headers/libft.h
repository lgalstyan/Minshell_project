#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
int		ft_strlcpy(char *dst, char *src, int l);
char	*ft_strnstr(char *str, char *to_find, int len);
// char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strdup(char *src);
int		ft_isdigit(char c);
char	*run_ft_strdup(char *src);
char	*ft_itoa(int n);
 
#endif