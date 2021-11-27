#ifndef MINISHELL_PARSE_H

# define MINISHELL_PARSE_H

/*
 * CMD[*1, *2, *3, NULL]
 * TYPE :
 *   1 : redirection
 *   2 :
 * TEXT :
 *   command as it is
 * REDIR_BEFORE :
 * REDIR_AFTER :
 *   1 : <
 *   2 : >
 *   3 : <<
 *   4 : >>
 * IS_BUILTIN :
 *   0 OR 1
 */
/*

cmd < 'pwd' > test.txt
['-s', '-n']
['string']

echo -s -n string


[NULL]
['string', '-s', '-n']

echo string -s -n


echo string
*/

typedef struct s_mini_cmd {
	char				*filename;
	int					redir;
	struct s_mini_cmd	*next_mini;
} t_mini_cmd;

typedef struct s_cmd {
	char				*text;
	char				*cmd;
	char				**options;
	char				is_builtin;
	struct s_mini_cmd	*mini_cmd;
	struct s_cmd		*next_cmd;
	char				*error;
}				t_cmd;

typedef struct s_globl {
	t_cmd				*lst;
	char				*error;
}				t_global;

void			handle_line(char *s, struct imp *env);
t_mini_cmd		*ft_mini_lstlast(t_mini_cmd *lst);
void			ft_mini_addback(t_mini_cmd **head, char *f, int r);

char			**ft_split_wq(char *s, char c, size_t i, size_t j);
int				check_quotes_ind(char *str, size_t len);

void			print_cmd(t_cmd *c);

#endif
