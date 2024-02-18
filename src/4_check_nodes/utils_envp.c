/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:51:12 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/16 15:30:04 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*clean_vble(char *node, int idx)
{
	int		i;
	int		j;
	int		len;
	char	*new_line;

	j = -1;
	len = 0;
	i = idx + 1;
	while (ft_isalpha(node[i]))
	{
		i++;
		len++;
	}
	new_line = malloc(sizeof(char) * (len + 1));
	if (!new_line)
		exit_error("Malloc error\n");
	i = idx + 1;
	while (++j < len)
		new_line[j] = node[i++];
	new_line[j] = '\0';
	return (new_line);
}

char	*ft_getenv(const char *name, t_list *env, int idx)
{
	char	*vble;
	char	*new_name;
	t_list	*tmp;

	tmp = env;
	new_name = clean_vble((char *)name, idx);
	vble = ft_strjoin(new_name, "=");
	if (!vble)
		exit_error("Malloc error\n");
	free(new_name);
	while (tmp && tmp->content)
	{
		if (ft_strncmp((char *)tmp->content, vble, ft_strlen(vble)) == 0)
		{
			free(vble);
			return ((char *)tmp->content + ft_strlen(vble));
		}
		tmp = tmp->next;
	}
	free(vble);
	vble = ft_strdup("");
	if (!vble)
		exit_error("Malloc error\n");
	return (vble);
}
