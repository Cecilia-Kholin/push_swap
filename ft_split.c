/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:25:01 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/26 16:02:57 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**free_all(char **v, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(v[i++]);
	free(v);
	return (NULL);
}

void	copy_chars(char *dst, const char *src, size_t len)
{
	size_t	k;

	k = 0;
	while (k < len)
	{
		dst[k] = src[k];
		k++;
	}
	dst[len] = '\0';
}

size_t	len_word(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*total;
	size_t	countwords;
	size_t	len;
	size_t	i;

	i = 0;
	countwords = count_words (s, c);
	result = malloc(sizeof(char *) * (countwords + 1));
	if (!result)
		return (free_all(result, (int)i));
	while (i < countwords)
	{
		while (*s && *s == c)
			s++;
		len = len_word(s, c);
		total = malloc((sizeof(char)) * (len + 1));
		if (!total)
			return (free_all(result, (int)i));
		copy_chars(total, s, len);
		result[i++] = total;
		s += len;
	}
	result[countwords] = NULL;
	return (result);
}
