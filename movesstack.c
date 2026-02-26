/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesstack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:40:24 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/26 16:00:47 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		move_sa(a);
	else if (first > second && second > third)
	{
		move_sa(a);
		move_rra(a);
	}
	else if (first > second && second < third && first > third)
		move_ra(a);
	else if (first < second && second > third && first < third)
	{
		move_sa(a);
		move_ra(a);
	}
	else if (first < second && second > third && first > third)
		move_rra(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;

	min = get_min(*a);
	while ((*a)->value != min)
		move_ra(a);
	move_pb(a, b);
	sort_three(a);
	move_pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	if ((*b)->value < (*b)->next->value)
		move_sb(b);
	move_pa(a, b);
	move_pa(a, b);
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	check_stack_size(t_stack *stack_a, t_stack *stack_b)
{
	int		size;

	size = stack_size(stack_a);
	if (size == 2)
	{
		if (stack_a->value > stack_a->next->value)
			move_sa(&stack_a);
	}
	else if (size == 3)
		sort_three(&stack_a);
	else if (size == 4)
		sort_four(&stack_a, &stack_b);
	else if (size == 5)
		sort_five(&stack_a, &stack_b);
	else if (size > 5)
	{
		assign_indices_no_array(stack_a);
		push_to_b(&stack_a, &stack_b, get_range(size));
		push_to_a(&stack_a, &stack_b);
	}
	return (0);
}
