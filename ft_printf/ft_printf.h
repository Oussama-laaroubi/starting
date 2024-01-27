/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:21:43 by olaaroub          #+#    #+#             */
/*   Updated: 2023/12/10 17:06:40 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *placeholder, ...);
int	ft_placeholder(char placeholder, va_list args);
int	ft_putnbr_base(long n, int base, char c);
int	ft_putptr(void *p, char c);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_putptr_base(unsigned long n, int base, char c);

#endif