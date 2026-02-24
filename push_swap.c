/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:33:34 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/24 11:27:03 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_five(t_stack **a, t_stack **b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);

	sort_three(a);

	// Si en B el mayor está arriba, lo rotamos
	if ((*b)->value < (*b)->next->value)
		move_sb(b);

	move_pa(a, b);
	move_pa(a, b);
}
//contar cuantos numero hay
int stack_size(t_stack *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

//combinacion de los 3 numeros
void sort_three(t_stack **a)
{
	int first = (*a)->value;
	int second = (*a)->next->value;
	int third = (*a)->next->next->value;

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

int get_min(t_stack *a)
{
	int min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

void push_min_to_b(t_stack **a, t_stack **b)
{
	int min;

	min = get_min(*a);
	while ((*a)->value != min)
		move_ra(a);
	move_pb(a, b);
}

void sort_four(t_stack **a, t_stack **b)
{
	int min = get_min(*a);

	// Mientras el mínimo no esté arriba
	while ((*a)->value != min)
	{
		move_ra(a);
	}

	move_pb(a, b);
	sort_three(a);
	move_pa(a, b);
}

void push_to_stack(t_stack **stack, int n)
{
	t_stack *new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		return ;
	}
	
	new_node->value = n;  // Asignamos el valor del número a este nuevo nodo
	new_node->next = *stack;  // El nuevo nodo apunta a lo que sea que esté en el inicio de la pila
	*stack = new_node;  // Ahora el inicio de la pila es este nuevo nodo
}

//si todo va bien devulve 1
//que sea numerico
//qur no tenga doble signo
int check_numerber(int argc, char **argv, t_stack **a)
{
	int     i;
	long    n;
	
	i = 1;
	n = 0;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);              
		if (is_duplicate(*a, (int)n))     
			return 0;
		push_to_stack(a, (int)n);
		i++;
	}
	return (1);
}
int is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return 0; // No está ordenada
		stack = stack->next;
	}
	return 1; // Ordenada
}
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	
	stack_a = NULL;
	stack_b  = NULL;    
	if (argc < 2)
		return (0);
	//comprobamos que no tenga doble signo, que sea numerico
	if (!check_numerber(argc, argv, &stack_a))
		return (error());
	//comprobamos is ya esta ordenaado
	if (is_sorted(stack_a))
		return 0;
	size = stack_size(stack_a);
	//comprobamos menores de 5
	if (size == 2) // si hay 2 elementos
	{
		if (stack_a->value > stack_a->next->value)
			move_sa(&stack_a); // swap
	}
	else if (size == 3)
		sort_three(&stack_a);
	else if (size == 4)
		sort_four(&stack_a, &stack_b);
	else if (size == 5)
		sort_five(&stack_a, &stack_b);
	else
	{
		k_sort(&stack_a, &stack_b); // K-Sort para >5 números
	}
}