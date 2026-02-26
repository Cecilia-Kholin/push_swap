/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:42:37 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/26 15:46:19 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (!*stack || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	move_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	move_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	move_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
