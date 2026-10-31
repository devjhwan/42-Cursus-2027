/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:10:02 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:10:02 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_vprintf(const char *format, va_list args);
int	ft_handle_conversion(char ch, va_list args);
int	ft_putstr(char *s);
int	ft_putchar(char ch);
int	ft_putnbr(long n);
int	ft_putnbr_base(unsigned long long n, int base, int upper);

#endif
