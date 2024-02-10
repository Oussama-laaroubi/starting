/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:20:17 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/10 02:04:59 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	ft_fill_stack(t_program *main, char **av)
{
	char	**ptr;
	int		k;
	int		index;

	k = 1;
	if (!av || !av[1][0])
		ft_error("Error");
	while (av[k])
	{
		index = 0;
		ptr = ft_split(av[k], ' ');
		if (!ptr)
			exit(1);
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

static void	ft_fill_args(t_program *main, char *av)
{
	char	**ptr;
	int		k;

	k = 0;
	if (!av || !av[0])
		ft_error("Error");
	ptr = ft_split(av, ' ');
	if (!ptr)
		exit(1);
	while (ptr[k])
	{
		append_last(&main->head_a, ft_atoi(ptr[k]));
		free(ptr[k]);
		k++;
	}
	free(ptr);
	main->stack_a_size = stack_size(main->head_a);
	main->stack_b_size = 0;
	main->head_b = NULL;
}

int	main(int ac, char **av)
{
	t_program	main;
	node		*tmp;

	main.head_a = NULL;
	if (!check_args(av, ac))
		ft_error("Error");
	if (ac == 2)
		ft_fill_args(&main, av[1]);
	else
		ft_fill_stack(&main, av);
	if (!check_duplicates(&main.head_a))
		ft_error("Error");
	if (!stack_sorted(main.head_a))
		ft_indexing(&main);
	// sa(&main.head_a);
	// ra(&main.head_a);
	// rra(&main.head_a);
	pb(&main.head_a, &main.head_b);
	pb(&main.head_a, &main.head_b);
	pb(&main.head_a, &main.head_b);
	pb(&main.head_a, &main.head_b);
	pb(&main.head_a, &main.head_b);
	pb(&main.head_a, &main.head_b);
	tmp = main.head_a;
	while (tmp)
	{
		printf("value == %d and index == %d\n", tmp->value, tmp->index);
		if(tmp->next)
			printf("the next value is == %d\n-------------------------------\n", tmp->next->value);
		tmp = tmp->next;
	}
	deallocate_stack(&main.head_a);
	deallocate_stack(&main.head_b);

}
