/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:59:40 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/26 15:49:20 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_second_last(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (!stack || !stack->next)
		return (NULL);
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*new_tail;

	if (!*stack || (*stack)->next == NULL)
		return ;
	tail = get_bottom(*stack);
	new_tail = get_second_last(*stack);
	tmp = *stack;
	tail->next = tmp;
	new_tail->next = NULL;
	*stack = tail;
}

void	move_rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr("rra\n");
}

void	move_rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	move_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr("rrr\n");
}
