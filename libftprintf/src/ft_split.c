/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:12:35 by abastida          #+#    #+#             */
/*   Updated: 2022/06/13 14:16:22 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = -1;
	word = 0;
	while (s[++i])
	{
		if (s[i] != c && ((s[i + 1] == '\0') || (s[i + 1] == c)))
			word++;
	}
	return (word);
}

int	ft_strlenchar(const char *s, char c)
{
	int	i;

	i = 0;
	while ((s[i]) && (s[i] != c))
		i++;
	return (i);
}

char	**ft_free(char **matrix)
{
	int	contador;

	contador = -1;
	if (!matrix)
		return (NULL);
	while (matrix[++contador])
		free (matrix[contador]);
	free (matrix);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		n_word;
	int		len;
	int		i;
	char	**matrix;

	matrix = (char **) malloc (sizeof (char *) * (count_word(s, c) + 1));
	if (!matrix)
		return (NULL);
	i = -1;
	n_word = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			len = ft_strlenchar(&s[i], c);
			matrix[n_word] = ft_substr(&s[i], 0, len);
			if (!matrix[n_word])
				return (ft_free (matrix));
			n_word++;
			i = i + len - 1;
		}
	}
	matrix[n_word] = NULL;
	return (matrix);
}
