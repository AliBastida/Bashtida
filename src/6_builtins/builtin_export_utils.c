/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:50:02 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 17:44:17 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_until_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

// printf("Join var: Name->-%s- Value->-%s-\n", aux->content, cont);
void	join_var(t_list *aux, char *arg)
{
	int		i;
	char	*tmp;
	char	*cont;

	i = 0;
	while (arg[i] != '=')
		i++;
	cont = ft_strjoin(ft_strchr(aux->content, '=') + 1, &arg[++i]);
	if (!cont)
		exit_error("Malloc error\n");
	free(aux->content);
	aux->content = ft_substr(arg, 0, ft_strchr(arg, '+') - arg);
	if (!aux->content)
		exit_error("Malloc error\n");
	tmp = ft_strjoin(aux->content, "=");
	if (!tmp)
		exit_error("Malloc error\n");
	free(aux->content);
	aux->content = ft_strjoin(tmp, cont);
	if (!aux->content)
		exit_error("Malloc error\n");
	free(tmp);
	free(cont);
}

int	checking_format(char *str)
{
	int	i;
	int	equal;

	i = 0;
	equal = len_until_equal(str);
	while (str[i] && i < equal)
	{
		if (i == 0 && !ft_isalpha(str[i]))
			return (1);
		else if ((str[i] == '+' && str[equal] == '=' && i != equal - 1)
			|| (str[i] == '+' && str[equal] == '\0') || (str[i] != '+'
				&& !ft_isalnum(str[i]) && str[i] != '_'))
			return (1);
		i++;
	}
	return (0);
}

t_list	*get_envnode_export(t_list *env, char *arg)
{
	int		arg_len;
	t_list	*tmp;

	tmp = env;
	arg_len = len_until_equal(arg);
	if (ft_strchr(arg, '+'))
		arg_len--;
	while (tmp)
	{
		if (ft_strncmp((char *)tmp->content, arg, arg_len) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

// int	len_until_equal(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if ((str[i] == '=') || (str[i] == '+'))
// 			return (i);
// 		i++;
// 	}
// 	return (i);
// }

// char	*copyvble(char *str, int size)
// {
// 	int		i;
// 	char	*copy;

// 	copy = ft_calloc(size + 1, sizeof(char));
// 	if (!copy)
// 		exit_error("Malloc error\n");
// 	i = 0;
// 	while (str[i] && str[i] != '=' && (i <= size))
// 	{
// 		if (str[i] == '+')
// 			break ;
// 		// return (copy);
// 		else
// 			copy[i] = str[i];
// 		i++;
// 	}
// 	copy[i] = '\0';
// 	return (copy);
// }

// int	checking_format(char *str)
// {
// 	int		i;
// 	size_t	last_one;

// 	i = 0;
// 	last_one = ft_strlen(str);
// 	while (str[i])
// 	{
// 		if (str[last_one - 1] == '+')
// 			return (1);
// 		else if (ft_isalpha(str[0]) || (i > 0 && (ft_isdigit(str[i])
// 					|| ft_isalpha(str[i]) || str[i] == '_')))
// 			return (0);
// 		else
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strchr_export(char *str, char c)
// {
// 	while (*str != '\0')
// 	{
// 		if (*str == c)
// 			return (str + 1);
// 		str++;
// 	}
// 	return (str);
// }
