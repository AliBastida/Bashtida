/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:50:02 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 17:52:36 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int len_until_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '=') || (str[i] == '+'))
			return (i);
		i++;
	}
	return (i);
}

char	*copyvble(char *str, int size)
{
	int		i;
	char	*copy;

	copy = ft_calloc(size + 1, sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while ((str[i] && str[i] != '=') && (i <= size))
	{
		if (str[i] == '+')
		{
			return (copy);
		}
		else
			copy[i] = str[i];
		printf("%d \t %d\n", i, size);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	checking_format(char *str)
{
	int		i;
	size_t	last_one;

	i = 0;
	last_one = ft_strlen(str);
	while (str[i])
	{
		if (str[last_one - 1] == '+')
		{
			printf("NO esta bien escrito\n");
				// TODO: TENEMOS QUE GUARDAR EL ERROR EN LA V_GLOBAL.
			return (1);
		}
		else if (ft_isalpha(str[0]) || (i > 0 && (ft_isdigit(str[i])
					|| ft_isalpha(str[i]) || str[i] == '_')))
			return (0);
		else
		{
			printf("NO esta bien escrito\n");
				// TODO: TENEMOS QUE GUARDAR EL ERROR EN LA V_GLOBAL
			return (1);
		}
		i++;
	}
	return (0);
}

t_list	*get_envnode_export(t_list *env, char *arg)
{
	int		arg_len;
	t_list	*tmp;

	tmp = env;
	arg_len = ft_strlen(arg);
	while (tmp)
	{
		if (ft_strncmp((char *)tmp->content, arg, arg_len) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

// este strchar nos retorna la posicion siguiente del igual para hacer en builtin export un strjoin y asi no duplica el igual.
char	*ft_strchr_export(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str + 1);
		str++;
	}
	return (str);
}
