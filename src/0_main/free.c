/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 14:08:43 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_hd(t_heredoc *hd)
{
	close(hd->fd[0]);
	close(hd->fd[1]);
	free(hd->word);
	free(hd);
}

static void	free_words(t_word *words)
{
	t_word	*tmp;
	t_word	*next;

	tmp = words;
	next = tmp->next;
	while (tmp)
	{
		if (tmp->word)
			free(tmp->word);
		free(tmp);
		tmp = next;
		if (tmp)
			next = tmp->next;
	}
}

void	free_cmds(t_cmd *cmds)
{
	t_cmd	*tmp;
	t_cmd	*next;

	tmp = cmds;
	next = tmp->next;
	while (tmp)
	{
		if (tmp->cmd)
			free(tmp->cmd);
		if (tmp->args)
			ft_free_double(tmp->args);
		if (tmp->hd)
			free_hd(tmp->hd);
		if (tmp->error)
			free(tmp->hd);
		free(tmp);
		tmp = next;
		if (tmp)
			next = tmp->next;
	}
}

void	free_tokens(t_token *tk)
{
	t_token	*tmp;
	t_token	*next;

	tmp = tk;
	next = tmp->next;
	while (tmp)
	{
		if (tmp->content_token)
			free(tmp->content_token);
		if (tmp->word_node)
			ft_free_double(tmp->word_node);
		if (tmp->words)
			free_words(tmp->words);
		free(tmp);
		tmp = next;
		if (tmp)
			next = tmp->next;
	}
}

void	free_all(t_master *master, int mode)
{
	if (master->line)
		free(master->line);
	if (master->clean_line)
		free(master->clean_line);
	if (master->cmds)
		free_cmds(master->cmds);
	if (master->node)
		free_tokens(master->node);
	if (mode)
	{
		if (master->env)
			ft_lstclear(&master->env, &free);
		free(master);
	}
	else
	{
		master->line = NULL;
		master->clean_line = NULL;
		master->cmds = NULL;
		master->node = NULL;
	}
}
