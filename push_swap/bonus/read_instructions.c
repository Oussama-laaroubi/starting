/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:47:07 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/19 15:26:46 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_fill_stack(t_checker *checker, char **av)
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
			append_last_bonus(&checker->head_a, ft_atoi(ptr[index]));
			free(ptr[index]);
			index++;
		}
		free(ptr);
		k++;
	}
	checker->stack_a_size = stack_size(checker->head_a);
	checker->stack_b_size = 0;
	checker->head_b = NULL;
}

static int	check_for_ss_sb(t_checker *checker, char *instructions)
{
	if (ft_strncmp(instructions, "sb\n", ft_strlen(instructions)) == 0)
		sb(&checker->head_b, true);
	else if (ft_strncmp(instructions, "ss\n", ft_strlen(instructions)) == 0)
		ss(&checker->head_a, &checker->head_b, true);
	else
	{
		free(instructions);
		get_next_line(INVALID_FD);
		return (-1);
	}
	return (0);
}

static int	apply_instructions(t_checker *checker, char *instructions)
{
	if (ft_strncmp(instructions, "ra\n", ft_strlen(instructions)) == 0)
		ra(&checker->head_a, true);
	else if (ft_strncmp(instructions, "rb\n", ft_strlen(instructions)) == 0)
		rb(&checker->head_b, true);
	else if (ft_strncmp(instructions, "sa\n", ft_strlen(instructions)) == 0)
		sa(&checker->head_a, true);
	else if (ft_strncmp(instructions, "pb\n", ft_strlen(instructions)) == 0)
		pb_bonus(checker);
	else if (ft_strncmp(instructions, "pa\n", ft_strlen(instructions)) == 0)
		pa_bonus(checker);
	else if (ft_strncmp(instructions, "rra\n", ft_strlen(instructions)) == 0)
		rra(&checker->head_a, true);
	else if (ft_strncmp(instructions, "rrb\n", ft_strlen(instructions)) == 0)
		rrb(&checker->head_b, true);
	else if (ft_strncmp(instructions, "rrr\n", ft_strlen(instructions)) == 0)
		rrr_bonus(checker);
	else if (ft_strncmp(instructions, "rr\n", ft_strlen(instructions)) == 0)
		rr_bonus(checker);
	else
	{
		if (check_for_ss_sb(checker, instructions) == -1)
			return (deallocate_stack(&checker->head_a),
				deallocate_stack(&checker->head_b), -1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_checker	checker;
	char		*instructions;

	checker.head_a = NULL;
	if (ac == 1)
		exit(0);
	if (!check_args(av, ac))
		ft_error("Error");
	ft_fill_stack(&checker, av);
	if (!check_duplicates(&checker.head_a))
		ft_error("Error");
	instructions = get_next_line(0);
	while (instructions)
	{
		if (apply_instructions(&checker, instructions) == -1)
			ft_error("Error");
		free(instructions);
		instructions = get_next_line(0);
	}
	if (stack_sorted(checker.head_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	deallocate_stack(&checker.head_a);
	return (0);
}
