/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:59:15 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/20 13:44:59 by cwolf            ###   ########.fr       */
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
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	init_list_a(&a, args);
	print_list(a);
	pb(&b, &a);
	pb(&b, &a);
	pb(&b, &a);
	pb(&b, &a);
	pb(&b, &a);
	rrr(&a, &b);
	print_list(a);
	print_list(b);
	//check ob Stack 'a' sortiert ist
		//if not
			//Checken ob es 2 nodes gibt in 'a'
				//wenn ja, swap nummern
			//Checken ob 3 Nummern in 'a'
				//wenn ja, "sort three algo"
			//Checken ob mehr als 3 Nummern in 'a'
				//turk algo
}
