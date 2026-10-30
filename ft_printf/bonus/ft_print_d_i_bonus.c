/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:09:20 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:09:20 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_dctx_value(t_dctx *ctx, t_conv conv, va_list args)
{
	ctx->value = (long)va_arg(args, int);
	ctx->sign = 0;
	if (ctx->value < 0)
	{
		ctx->sign = '-';
		ctx->value = -ctx->value;
	}
	else if (conv.f & F_PLUS)
		ctx->sign = '+';
	else if (conv.f & F_SPACE)
		ctx->sign = ' ';
	ctx->sign_len = (ctx->sign != 0);
	ctx->dlen = ft_utoa_dec((unsigned int)ctx->value, ctx->digits);
	if (conv.p == 0 && ctx->value == 0)
		ctx->dlen = 0;
}

static void	init_dctx_padding(t_dctx *ctx, t_conv conv)
{
	ctx->zeros = 0;
	if (conv.p > ctx->dlen)
		ctx->zeros = conv.p - ctx->dlen;
	ctx->pad = ' ';
	if ((conv.f & F_ZERO) && !(conv.f & F_MINUS) && conv.p < 0)
		ctx->pad = '0';
	ctx->spaces = conv.w - ctx->sign_len - ctx->zeros - ctx->dlen;
	if (ctx->spaces < 0)
		ctx->spaces = 0;
	if (ctx->pad == '0')
	{
		ctx->zeros += ctx->spaces;
		ctx->spaces = 0;
	}
}

static int	write_d_i_body(t_dctx *ctx, int *count)
{
	if (ctx->sign_len)
	{
		if (ft_buffer_write_char(ctx->sign) < 0)
			return (-1);
		(*count)++;
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

int	ft_print_d_i(t_conv conv, va_list args)
{
	t_dctx	ctx;
	int		count;

	init_dctx_value(&ctx, conv, args);
	init_dctx_padding(&ctx, conv);
	count = 0;
	if (!(conv.f & F_MINUS))
	{
		if (ft_append_padding(&count, ctx.spaces, ' ') < 0)
			return (-1);
	}
	if (write_d_i_body(&ctx, &count) < 0)
		return (-1);
	if (conv.f & F_MINUS)
	{
		if (ft_append_padding(&count, ctx.spaces, ' ') < 0)
			return (-1);
	}
	return (count);
}
