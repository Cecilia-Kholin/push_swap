/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsksort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:10:36 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/26 17:11:07 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_range(int len)
{
	if (len <= 100)
		return (16);
	return (40);
}

t_stack	*find_max(t_stack *stack)
{
	int		max;
	t_stack	*max_node;

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

void	free_split(char **nums)
{
	int	i;

	i = 0;
	if (!nums)
		return ;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}
