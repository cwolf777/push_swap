/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:59:15 by cwolf             #+#    #+#             */
/*   Updated: 2025/01/09 10:01:34 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sorting_part(t_ps_list **a, t_ps_list **b);
// static void	print_list(t_ps_list *head);

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
	{
		args = ft_split(argv[1], ' ');
		init_list_malloced(&a, args);
	}
	else
	{
		args = argv + 1;
		init_list_a(&a, args);
	}
	sorting_part(&a, &b);
	free_list_end(&a);
	if (argc == 2)
		free_args(args);
	return (0);
}

void	sorting_part(t_ps_list **a, t_ps_list **b)
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
