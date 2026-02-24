/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:52:08 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/24 11:43:53 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//get de botton
t_stack *get_bottom(t_stack *stack)
{
    t_stack *tmp = stack;

    if (!stack)
        return (NULL);

    while (tmp->next != NULL) // recorre hasta el último nodo
        tmp = tmp->next;

    return tmp; // devuelve el último nodo
}

t_stack *get_second_last(t_stack *stack)
{
    t_stack *tmp = stack;

    if (!stack || !stack->next)
        return NULL;

    while (tmp->next && tmp->next->next)  // Cuando tmp->next->next es NULL, tmp es el penúltimo nodo
        tmp = tmp->next;

    return tmp;  // Devuelve el penúltimo nodo
}

int	ft_atoi(const char *nptr)
{
	int	    i;
	long	num;
	int	    sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ' || nptr[i] == '"')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - '0';
        // Verificación de overflow
        if (sign == 1 && num > 2147483647)
            return 0;
        if (sign == -1 && num > 2147483648)
            return 0;
		i++;
	}
	return (num * sign);
}

int is_duplicate(t_stack *stack, int n)
{
    while (stack)
    {
        if (stack->value == n)
            return 1;   
        stack = stack->next;
    }
    return 0;
}
