/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:56:39 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/12 12:01:35 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
    //para guardar los nodos
    t_stack *tmp;
    //control de errores, si existe la pila y no esta vacia
    if (!*stack || (*stack)->next == NULL)
		return ;
    //tmp guarda la dirrecion del primer nodo
    tmp = *stack;
    //apuntamos al segundo nodo
    //tmp      *stack
    //↓          ↓
    //[N1] → [N2] → [N3] → NULL
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    //Haz que el nodo actual cabeza (N2) apunte a tmp (N1)
    (*stack)->next = tmp;
}
void	move_sa(t_stack **stack_a)
    {
        swap(stack_a);
        ft_putstr("sa\n");
    }

void	move_sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}
void	move_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}