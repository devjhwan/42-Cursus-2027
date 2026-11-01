/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-31 15:51:01 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-31 15:51:01 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_free_arr(char **arr)
{
	int	idx;

	if (arr == NULL)
		return ;
	idx = 0;
	while (arr[idx] != NULL)
		free(arr[idx++]);
	free(arr);
}

static size_t	ft_count_words(char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (*str)
			count++;
		while (*str && *str != ' ' && !(*str >= 9 && *str <= 13))
			str++;
	}
	return (count);
}

static int	ft_fill_split(char **arr, char const *str)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		start = i;
		while (str[i] && str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
			i++;
		if (i > start)
		{
			arr[j] = ft_substr(str, start, i - start);
			if (arr[j] == NULL)
				return (ft_free_arr(arr), -1);
			j++;
		}
	}
	arr[j] = NULL;
	return (0);
}

char	**ft_split(char *str)
{
	char	**arr;
	size_t	words;

	if (!str)
		return (NULL);
	words = ft_count_words(str);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	if (ft_fill_split(arr, str) < 0)
		return (NULL);
	return (arr);
}
