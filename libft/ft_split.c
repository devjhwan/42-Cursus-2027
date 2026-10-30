/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:01:52 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:01:52 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Release memory for a partially-built split result.
 * `allocated` is the number of words successfully allocated so far.
 * We free from the end to the beginning, then free the array itself.
 */
static void	ft_free_split(char **split, size_t allocated)
{
	while (allocated > 0)
		free(split[--allocated]);
	free(split);
}

/*
 * Count how many words are in `s` when `c` is used as a delimiter.
 * A word is a continuous block of non-delimiter characters.
 * Example: "a::bc:d" with ':' has 3 words ("a", "bc", "d").
 */
static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

/*
 * Fill `res` with substrings extracted from `s`.
 * For each word, we save its start index and length, then create it with
 * `ft_substr`. If any allocation fails, we free everything already created.
 * Returns 1 on success, 0 on failure.
 */
static int	ft_fill_split(char **res, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			res[j] = ft_substr(s, start, i - start);
			if (!res[j])
				return (ft_free_split(res, j), 0);
			j++;
		}
	}
	res[j] = NULL;
	return (1);
}

/*
 * Split string `s` by delimiter `c`.
 * 1) Count words to know array size.
 * 2) Allocate array of char* (+1 for NULL terminator).
 * 3) Build each substring.
 * Returns NULL if input is NULL or if any allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	if (!ft_fill_split(res, s, c))
		return (NULL);
	return (res);
}
