/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-01 22:01:49 by junghwal          #+#    #+#             */
/*   Updated: 2026-11-01 22:01:49 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_context
{
	char	*buffer;
	size_t	len;
	size_t	capacity;
}	t_context;

char	*get_next_line(int fd);
int		init_context(t_context *context);
void	free_context(t_context *context);
int		has_newline(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif
