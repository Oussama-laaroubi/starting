/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:24:36 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/14 16:31:31 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_base(unsigned long n, int base, char c)
{
	int			count;
	const char	*hexa;

	hexa = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
		return (ft_putptr_base(n, base, c) + 1);
	}
	else if (n < (unsigned long)base)
		return (ft_putchar(hexa[n]));
	else
	{
		count += ft_putptr_base(n / base, base, c);
		return (count + ft_putptr_base(n % base, base, c));
	}
	return (count);
}
