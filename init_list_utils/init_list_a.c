/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:00:06 by cwolf             #+#    #+#             */
/*   Updated: 2025/01/07 09:20:52 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void			attach_node(t_ps_list **a, int n);
static t_ps_list	*find_last_node(t_ps_list *a);
static t_ps_list	*newnode(int content);

void	init_list_a(t_ps_list **a, char **args)
{
	long	n;
	int		i;

	i = 0;
	while (args[i] != NULL)
	{
		if (check_syntax(args[i]) == 1)
			free_list(a);
		n = ft_atolo(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_list(a);
		if (check_duplicate(*a, ((int)n)) == 1)
			free_list(a);
		attach_node(a, (int)n);
		i++;
	}
}

static void	attach_node(t_ps_list **a, int n)
{
	t_ps_list	*node;
	t_ps_list	*last_node;

	if (a == NULL)
		return ;
	node = newnode(n);
	if (node == NULL)
		free_list(a);
	if (*a == NULL)
		*a = node;
	else
	{
		last_node = find_last_node(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

static t_ps_list	*find_last_node(t_ps_list *a)
{
	while (a != NULL)
	{
		if (a->next == NULL)
			return (a);
		a = a->next;
	}
	return (NULL);
}

static t_ps_list	*newnode(int content)
{
	t_ps_list	*newnode;

	newnode = malloc(sizeof(t_ps_list));
	if (newnode == NULL)
		return (NULL);
	newnode->nbr = content;
	newnode->index = -1;
	newnode->push_cost = -1;
	newnode->above_median = -1;
	newnode->cheapest = 0;
	newnode->target_node = NULL;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}
