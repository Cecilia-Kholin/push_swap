/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:33:34 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/26 15:53:56 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices_no_array(t_stack *a)
{
	t_stack	*current;
	t_stack	*tmp;
	int		index;

	current = a;
	while (current)
	{
		index = 0;
		tmp = a;
		while (tmp)
		{
			if (tmp->value < current->value)
				index++;
			tmp = tmp->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	push_to_b(t_stack **a, t_stack **b, int range)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			move_pb(a, b);
			move_rb(b);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			move_pb(a, b);
			i++;
		}
		else
			move_ra(a);
	}
}

int	get_position(t_stack *stack, t_stack *objetive)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == objetive)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*max_node;
	int		size;
	int		pos;

	while (*b)
	{
		size = stack_size(*b);
		max_node = find_max(*b);
		pos = get_position(*b, max_node);
		if (pos <= size / 2)
		{
			while (*b != max_node)
				move_rb(b);
		}
		else
		{
			while (*b != max_node)
				move_rrb(b);
		}
		move_pa(a, b);
	}
}
