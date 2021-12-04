#include "../minishell.h"

void	print_cmd(t_cmd *c)
{
	if (!c)
		printf("NULL\n--------------\n\n");
	else
	{
		printf("\n\n--------------\n");
		printf("full command   : [%s]\n", c->text);
		printf("command name   : [%s]\n", c->cmd);
		printf("is implemented : [%d]\n", c->is_builtin);
		if (c->options)
		{
			printf("options are\n");
			for (int i = 0; c->options[i]; i++)
			{
				printf("\t%d [%s]\n", i+1, c->options[i]);
			}
		}
		if (c->mini_cmd)
		{
			printf("redirections are\n");
			while (c->mini_cmd)
			{
				printf("\t[%d]\n", c->mini_cmd->redir);
				printf("\t[%s]\n", c->mini_cmd->filename);
				printf("\t[%i]\n", c->mini_cmd->ambig);
				c->mini_cmd = c->mini_cmd->next_mini;
			}
		}
		printf("\n--------------\n\n");
		printf("exit status : %s\n", g_global->error);
		printf("\n--------------\n\n");
	}
}

t_mini_cmd	*ft_mini_lstlast(t_mini_cmd *lst)
{
	if (lst)
		while (lst->next_mini)
			lst = lst->next_mini;
	return (lst);
}

void	ft_mini_addback(t_mini_cmd **head, char *f, int r, int a)
{
	t_mini_cmd	*last;
	t_mini_cmd	*new;

	new = malloc(sizeof(t_mini_cmd));
	new->filename = ft_strdup(f);
	new->redir = r;
	new->ambig = a;
	new->next_mini = NULL;

	if (head && new)
	{
		if (*head)
		{
			last = ft_mini_lstlast(*head);
			last->next_mini = new;
		}
		else
			*head = new;
	}
}
