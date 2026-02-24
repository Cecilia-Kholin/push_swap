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

void assign_indices_no_array(t_stack *a)
{
    t_stack *current = a;
    t_stack *tmp;
    int index;

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

int	max_bits(t_stack *a)
{
	int max;
	int bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	ksort_radix(t_stack **a, t_stack **b)
{
	int bits;
	int i;
	int j;
	int size;

	bits = max_bits(*a);
	i = 0;
	while (i < bits)
	{
		size = stack_size(*a);
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				move_ra(a);      // bit = 1 => se queda en A (rota)
			else
				move_pb(a, b);   // bit = 0 => a B
			j++;
		}
		while (*b)
			move_pa(a, b);       // devolver todo a A
		i++;
	}
}