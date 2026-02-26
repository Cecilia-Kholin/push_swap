/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:33:42 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/26 17:29:15 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}


int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	is_valid_number(const char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i + 1] == '\0')
			return (0);
		i++;
	}
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	push_back(t_stack **stack, int n)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = n;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

int	check_number(char **nums, t_stack **a)
{
	long	n;
	int		i;

	i = 0;
	while (nums[i])
	{
		if (!is_valid_number(nums[i]))
		{
			free_stack(a);
			return (0);
		}
		n = ft_atoi(nums[i]);
		if (n < INT_MIN || n > INT_MAX || is_duplicate(*a, (int)n))
		{
			free_stack(a);
			return (0);
		}
		push_back(a, (int)n);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
