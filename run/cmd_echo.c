#include "minishell.h"

void cmd_echo()
{
	int c = 0; 
	int cr;
  	while (c != EOF) 
    { 
      	printf("\n Enter input: "); 
      	c = getchar(); 
      	cr = getchar();
      	putchar(c); 
    }
}