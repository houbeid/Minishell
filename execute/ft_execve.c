#include "../minishell.h"

/*char	ft_free_first(char *first, char *str)
{
	if (first == 0)
		return (str);
	free(first);
	return (str);
}*/

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}


char   *path_env(struct imp **imp)
{
    int i;

    i = 0;
	struct imp *tmp;

	tmp = *imp;
    while (tmp)
    {
		//printf("hamade\n");
        if (ft_strcmp(tmp->key, "PATH") == 0)
            break ;
        tmp = tmp->next;
    }
	//printf("hamade\n");
	if (tmp == NULL)
	{
		ft_putstr_fd("minishell: ", 1);
		ft_putstr_fd(g_cmds->cmd, 1);
		ft_putstr_fd(": No such file or directory\n", 1);
		exit(0);
		return (0);
	}
    return (tmp->value);
}

void	error_command(char	*str)
{
	ft_putstr_fd("minishell: ", 1);
	if (str)
		ft_putstr_fd(str, 2);
	ft_putstr_fd(" : command not found\n", 2);

	
}

void	ft_perror(char *cmd)
{
	perror(cmd);
	exit(127);
}

char    *research_path(struct imp **imp)
{
    char	**path;
	char	*pathname;
	int		i;

	i = 0;
	if (!g_cmds->cmd)
		error_command(NULL);
	if (access(g_cmds->cmd, F_OK) == 0 && g_cmds->cmd[0] == '/')
		return (ft_strdup(g_cmds->cmd));
	path = ft_split(path_env(imp), ':');
	//path[0] = ft_strdup(ft_strrchr(path[0], '=') + 1);
    //printf("%s\n", path[0]);
  //printf("hamade\n");
	while (path[i])
	{
		pathname = ft_strjoin_char(path[i], g_cmds->cmd, '/');
		if (access(pathname, F_OK) == 0)
			break ;
		i++;
		free(pathname);
		if (path[i] == 0)
			error_command(g_cmds->cmd);
	}
	ft_free_split(path);
	return (pathname);

}

void    ft_execve(struct imp **imp, char **envp)
{
    char *pathname;
    int pid;

    // printf("%s\n", pathname);
    pid = fork();
    wait(0);
	/*if (pathname == NULL)
		exit (0);*/
    //    if child
    if (pid == 0)
	{
    	pathname = research_path(imp);
        execve(pathname, g_cmds->options, envp);
		exit(0);

	}
}
/*
void    ft_execve_red(char **envp)
{
    char *pathname;
    pathname = research_path(envp);
    execve(pathname, g_cmds->options, envp);
	exit(0);
	//exit(WEXITSTATUS(status));
}*/