#include "minishell.h"

// void    ft_pipe(t_node *node, t_env **envir)
// {
//     // int     fd[2];
//     pid_t   child;
//     t_node  *curr;
//     // int list_size;

//     // list_size = ft_lstsize(node);
//     curr = node;
//     printf("->hello<-\n");
//     if (!curr->next)
//             prompt(*curr, envir);
//     else
//     {
// 	    while (curr)
//         {
//             child = fork();
//             if (child == -1)
//             {
//                 perror("fork");
//                 exit(1);
//             }
//             if (child == 0)
//             {
//                 prompt(*curr, envir);
//             }
//             curr = curr->next;
//         }
//     }
// }