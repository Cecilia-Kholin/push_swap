/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:33:34 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/24 12:21:21 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_range(int len)
{
	if (len <= 100) return 16;
		return 40;
}
void assign_indices_no_array(t_stack *a)
{
    t_stack *current = a;
    t_stack *tmp;
    int index;

    while (current)
    {
		//comparamos el primero de current con todos los del tmp
        index = 0;
        tmp = a;
		// 42  10  4
        while (tmp)
        {
			//ejemplo 42 es menor que 42.... NO
			//segunda: 10 es menor que 42..... SI
            if (tmp->value < current->value)
                index++;
			//como no es menor avanzamos al siguiente, 10
            tmp = tmp->next;
        }
		//los numeros menores del temp
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

t_stack	*find_max(t_stack *stack)
{
	int					max;
	t_stack				*max_node;

	if (!stack)
		return (NULL);
	max = stack->index;
	max_node = stack;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
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
	int				size;
	int				pos;

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