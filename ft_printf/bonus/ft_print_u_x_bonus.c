/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_x_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:09:44 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:09:44 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_uxctx_value(t_uxctx *ctx, t_conv conv, va_list args)
{
	ctx->value = va_arg(args, unsigned int);
	if (conv.cs == 'x' || conv.cs == 'X')
		ctx->dlen = ft_utoa_base(ctx->value, conv.cs == 'X', ctx->digits);
	else
		ctx->dlen = ft_utoa_dec(ctx->value, ctx->digits);
	if (conv.p == 0 && ctx->value == 0)
		ctx->dlen = 0;
	ctx->prefix_len = 0;
	ctx->prefix_char = 'x';
	if (conv.cs == 'X')
		ctx->prefix_char = 'X';
	if ((conv.f & F_HASH) && conv.cs != 'u' && ctx->value != 0)
		ctx->prefix_len = 2;
}

static void	init_uxctx_padding(t_uxctx *ctx, t_conv conv)
{
	ctx->zeros = 0;
	if (conv.p > ctx->dlen)
		ctx->zeros = conv.p - ctx->dlen;
	ctx->pad = ' ';
	if ((conv.f & F_ZERO) && !(conv.f & F_MINUS) && conv.p < 0)
		ctx->pad = '0';
	ctx->spaces = conv.w - ctx->prefix_len - ctx->zeros - ctx->dlen;
	if (ctx->spaces < 0)
		ctx->spaces = 0;
	if (ctx->pad == '0')
	{
		ctx->zeros += ctx->spaces;
		ctx->spaces = 0;
	}
}

static int	write_ux_body(t_uxctx *ctx, int *count)
{
	if (ctx->prefix_len)
	{
		if (ft_buffer_write_char('0') < 0)
			return (-1);
		if (ft_buffer_write_char(ctx->prefix_char) < 0)
			return (-1);
		*count += 2;
	}
	if (ctx->zeros > 0)
	{
		if (ft_append_padding(count, ctx->zeros, '0') < 0)
			return (-1);
	}
	if (ctx->dlen > 0)
	{
		if (ft_write_str_n(ctx->digits, ctx->dlen) < 0)
			return (-1);
		*count += ctx->dlen;
	}
	return (0);
}

int	ft_print_u_x(t_conv conv, va_list args)
{
	t_uxctx	ctx;
	int		count;

	init_uxctx_value(&ctx, conv, args);
	init_uxctx_padding(&ctx, conv);
	count = 0;
	if (!(conv.f & F_MINUS))
	{
		if (ft_append_padding(&count, ctx.spaces, ' ') < 0)
			return (-1);
	}
	if (write_ux_body(&ctx, &count) < 0)
		return (-1);
	if (conv.f & F_MINUS)
	{
		if (ft_append_padding(&count, ctx.spaces, ' ') < 0)
			return (-1);
	}
	return (count);
}
