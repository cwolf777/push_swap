/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:24:12 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/21 18:41:59 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	str ++;
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	check_duplicate(t_ps_list *a, int n)
{
	if (a == NULL)
		return (0);
	while (a != NULL)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_list(t_ps_list **a)
{
	t_ps_list	*temp;
	t_ps_list	*current;

	if (a == NULL)
		return ;
	current = *a;
	while (current != NULL)
	{
		temp = current->next;
		current->nbr = -1;
		free(current);
		current = temp;
	}
	*a = NULL;
	ft_printf("Error\n");
	exit(1);
}
