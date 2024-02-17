/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:47:07 by olaaroub          #+#    #+#             */
/*   Updated: 2024/02/17 21:44:28 by olaaroub         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_checker	checker;
	static char *stat;
	char **to_split;
	char *tmp;
	char *buff = malloc(sizeof(char) * 1024 + 1);
	ssize_t readed = 1;

	checker.head_a = NULL;
	if (!check_args(av, ac))
		ft_error("Error");
	ft_fill_stack(&checker, av);
	if (!check_duplicates(&checker.head_a))
		ft_error("Error");
	while (readed > 0)
	{
		readed = read(0, buff, 1024);
		if(readed == -1)
			return (free(buff), free(stat), ft_error("Error"), 1);
		buff[readed] = '\0';
		tmp = ft_strdup_gnl(stat);
		free(stat);
		stat = ft_strjoin_gnl(tmp, buff);
		free(tmp);
	}
	free(buff);
	to_split = ft_split(stat, '\n');
	int k = 0;
	while (to_split[k])
	{
		if (strncmp(to_split[k], "ra", 2) == 0)
			ra(&checker.head_a, true);
		else if (strncmp(to_split[k], "rb", 2) == 0)
			rb(&checker.head_b, true);
		else if (strncmp(to_split[k], "sa", 2) == 0)
			sa(&checker.head_a, true);
		else if (strncmp(to_split[k], "pb", 2) == 0)
			pb_bonus(&checker);
		else if (strncmp(to_split[k], "pa", 2) == 0)
			pa_bonus(&checker);
		else if (strncmp(to_split[k], "rra", 3) == 0)
			rra(&checker.head_a, true);
		else if (strncmp(to_split[k], "rrb", 3) == 0)
			rrb(&checker.head_b, true);
		else if (strncmp(to_split[k], "rrr", 3) == 0)
			rrr_bonus(&checker);
		else if (strncmp(to_split[k], "rr", 2) == 0)
			rr_bonus(&checker);
		free(to_split[k]);
		k++;
	}
	free(to_split);
	if (stack_sorted(checker.head_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	deallocate_stack(&checker.head_a);
	return 0;
}
