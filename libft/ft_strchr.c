/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:06:08 by olaaroub          #+#    #+#             */
/*   Updated: 2023/11/22 21:30:41 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*buff;

	buff = (char *)str;
	i = 0;
	while (i <= ft_strlen(buff))
	{
		if (buff[i] == (char)c)
			return (buff + i);
		i++;
	}
	return (NULL);
}
