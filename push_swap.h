/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:56:56 by olaaroub          #+#    #+#             */
/*   Updated: 2024/01/28 18:16:50 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

void				fill_stack(char **av, t_node **tail, t_node **head, char** ptr);
char				**ft_split(char const *s, char c);
void				init(t_node **tail, t_node **head, int value);
void				swap(t_node **head);
void				append_last(t_node **tail, int value);
void				deallocate_stack(t_node **head, t_node **tail);
void				check_numbers(char **av);
void				check_duplicates(t_node **head);


#endif