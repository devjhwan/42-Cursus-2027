/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwal <junghwal@student.42barcel>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 15:00:06 by junghwal          #+#    #+#             */
/*   Updated: 2026-10-30 15:00:06 by junghwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	sign;

	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	ret = 0;
	while (*nptr >= '0' && *nptr <= '9')
		ret = ret * 10 + (*nptr++ - '0');
	return (ret * sign);
}
