/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:59:15 by cwolf             #+#    #+#             */
/*   Updated: 2024/12/09 18:30:41 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		exit (1);
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
