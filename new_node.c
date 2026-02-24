/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:45:43 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/24 11:31:43 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *new_node(int value)
{
    t_stack *node;

    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return (NULL);

    node->value = value;
	node->index = -1;
	node->next = NULL;

    return (node);
}