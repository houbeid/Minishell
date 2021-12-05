/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <houbeid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:04:32 by houbeid           #+#    #+#             */
/*   Updated: 2021/12/05 20:26:22 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error(char *str1, char *str2, char *str3)
{
	if (!ft_strcmp(g_global->lst->cmd, "cat"))
		ft_putstr_fd("minishell: cd: ", 2);
	else
		ft_putstr_fd("minishell:  ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd("\n", 2);
	g_global->error = str3;
}
