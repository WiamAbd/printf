/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabdella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 22:43:00 by wabdella          #+#    #+#             */
/*   Updated: 2025/11/03 22:43:00 by wabdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static size_t	*count_lens(char const *s, char c, size_t cw)
{
	size_t	*list;
	size_t	i;
	size_t	j;
	size_t	n;

	list = malloc(sizeof(size_t) * cw);
	if (!list)
		return (NULL);
	i = 0;
	n = 0;
	while (s[i] && n < cw)
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		list[n++] = j;
		i += j;
	}
	return (list);
}

static char	**alloc_words(size_t cw, size_t *list)
{
	char	**words;
	size_t	i;

	words = malloc(sizeof(char *) * (cw + 1));
	if (!words)
		return (free(list), NULL);
	i = 0;
	while (i < cw)
	{
		words[i] = ft_calloc(list[i] + 1, sizeof(char));
		if (!words[i])
		{
			while (i > 0)
				free(words[--i]);
			free(words);
			free(list);
			return (NULL);
		}
		i++;
	}
	return (words);
}

static void	fill_words(char **strs, const char *s, char c, size_t cw)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i] && n < cw)
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i] && s[i] != c)
			strs[n][j++] = s[i++];
		strs[n++][j] = '\0';
	}
	strs[n] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	*list_of_len;
	size_t	cw;

	if (!s)
		return (NULL);
	cw = count_word(s, c);
	list_of_len = count_lens(s, c, cw);
	if (!list_of_len)
		return (NULL);
	strs = alloc_words(cw, list_of_len);
	if (!strs)
		return (NULL);
	fill_words(strs, s, c, cw);
	free(list_of_len);
	return (strs);
}
