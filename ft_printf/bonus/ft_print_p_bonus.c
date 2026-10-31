/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:09:29 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:09:29 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	init_pctx_value(t_pctx *ctx, va_list args)
{
	ctx->value = (uintptr_t)va_arg(args, void *);
	ctx->dlen = ft_utoa_base((unsigned long long)ctx->value, 0, ctx->digits);
}

static void	init_pctx_padding(t_pctx *ctx, t_conv conv)
{
	if (ctx->value == 0)
		ctx->spaces = conv.w - 5;
	else
		ctx->spaces = conv.w - 2 - ctx->dlen;
	if (ctx->spaces < 0)
		ctx->spaces = 0;
}

static int	write_pointer_body(t_pctx *ctx, int *count)
{
	if (ctx->value == 0)
	{
		if (ft_write_bytes("(nil)", 5) < 0)
			return (-1);
		*count += 5;
		return (0);
	}
	if (ft_write_bytes("0x", 2) < 0)
		return (-1);
	*count += 2;
	if (ctx->dlen > 0)
	{
		if (ft_write_bytes(ctx->digits, ctx->dlen) < 0)
			return (-1);
		*count += ctx->dlen;
	}
	return (0);
}

int	ft_print_p(t_conv conv, va_list args)
{
	t_pctx	ctx;
	int		count;

	init_pctx_value(&ctx, args);
	init_pctx_padding(&ctx, conv);
	count = 0;
	if (!(conv.f & F_MINUS) && ctx.spaces > 0)
	{
		if (ft_append_padding(ctx.spaces, ' ') < 0)
			return (-1);
		count += ctx.spaces;
	}
	if (write_pointer_body(&ctx, &count) < 0)
		return (-1);
	if (conv.f & F_MINUS && ctx.spaces > 0)
	{
		if (ft_append_padding(ctx.spaces, ' ') < 0)
			return (-1);
		count += ctx.spaces;
	}
	return (count);
}
