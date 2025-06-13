/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:59:15 by cwolf             #+#    #+#             */
/*   Updated: 2025/06/13 17:41:33 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sorting_part(t_ps_list **a, t_ps_list **b);
// static void	print_list(t_ps_list *head);

int	main(int argc, char *argv[])
{
	char		**args;
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;

	args = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit (EXIT_FAILURE);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		init_list_malloced(&stack_a, args);
	}
	else
	{
		args = argv + 1;
		init_list_a(&stack_a, args);
	}
	execute_sorting(&stack_a, &stack_b);
	free_list(&stack_a);
	if (argc == 2)
		free_args(args);
	return (0);
}

void	execute_sorting(t_ps_list **a, t_ps_list **b)
{
	if (in_order(a) == 0)
	{
		if (two_nodes(a) == 1)
			sa(a);
		else if (three_nodes(a) == 1)
			sort_three(a);
		else
			turk_algorithm(a, b);
	}
}

// static void print_list(t_ps_list *head)
// {
//     t_ps_list *current = head;

//     if (!head)
//     {
//         printf("Die Liste ist leer.\n");
//         return;
//     }

//     printf("Liste: ");
//     while (current != NULL)
//     {
//         printf("%d -> ", current->nbr);
//         current = current->next;
//     }
//     printf("NULL\n"); // Am Ende der Liste
// }	
