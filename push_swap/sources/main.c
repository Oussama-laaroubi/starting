/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:20:17 by olaaroub          #+#    #+#             */
/*   Updated: 2024/03/01 18:11:15 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_fill_stack(t_program *main, char **av)
{
	char	**ptr;
	int		k;
	int		index;

	k = 1;
	if (!av || !av[1][0])
		ft_error(ERROR_MESSAGE);
	while (av[k])
	{
		index = 0;
		ptr = ft_split(av[k], ' ');
		if (!ptr)
			ft_error(ERROR_MESSAGE);
		while (ptr[index])
		{
			append_last(&main->head_a, ft_atoi(ptr[index]));
			free(ptr[index]);
			index++;
		}
		free(ptr);
		k++;
	}
	main->stack_a_size = stack_size(main->head_a);
	main->stack_b_size = 0;
	main->head_b = NULL;
}

int	main(int ac, char **av)
{
	t_program	main;

	main.head_a = NULL;
	if (ac == 1)
		return (EXIT_SUCCESS);
	if (!check_args(av, ac))
		ft_error(ERROR_MESSAGE);
	ft_fill_stack(&main, av);
	if (!check_duplicates(&main.head_a))
		ft_error(ERROR_MESSAGE);
	if (!stack_sorted(main.head_a))
	{
		ft_indexing(&main);
		sort_stack(&main);
	}
	deallocate_stack(&main.head_a);
	return (EXIT_SUCCESS);
}
