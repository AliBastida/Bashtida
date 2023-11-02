/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:47:58 by abastida          #+#    #+#             */
/*   Updated: 2023/11/02 12:18:01 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_master
{
	char *line;
    char *clean_line;
	int n_pipes;
}t_master;

typedef struct s_token
{
    char *content_token;
    struct s_token *next;
}t_token;

#endif