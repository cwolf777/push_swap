/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:59:15 by cwolf             #+#    #+#             */
/*   Updated: 2025/01/07 09:15:16 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char		**args;
	t_ps_list	*a;
	t_ps_list	*b;

	args = NULL;
	a = NULL;
	b = NULL;
	if (argc == 1)
		exit (EXIT_FAILURE);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	init_list_a(&a, args);
	if (in_order(&a) == 0)
	{
		if (two_nodes(&a) == 1)
			sa(&a);
		else if (three_nodes(&a) == 1)
			sort_three(&a);
		else
			turk_algorithm(&a, &b);
	}
	free_list_end(&a);
	return (0);
}
