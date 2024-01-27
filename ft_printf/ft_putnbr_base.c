/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:39:23 by olaaroub          #+#    #+#             */
/*   Updated: 2023/12/09 12:28:33 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long n, int base, char c)
{
	int			count;
	const char	*hexa;

	hexa = "0123456789abcdef";
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
		count += ft_putnbr_base(n, base, c);
	}
	else if (n < (long)base)
		count += ft_putchar(hexa[n]);
	else
	{
		count += ft_putnbr_base(n / base, base, c);
		count += ft_putnbr_base(n % base, base, c);
	}
	return (count);
}
