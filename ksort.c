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