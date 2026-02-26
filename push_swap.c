/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:33:34 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/26 17:33:11 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	min;

	min = get_min(*a);
	while ((*a)->value != min)
		move_ra(a);
	move_pb(a, b);
}

int	validate_args(char **nums, int argc, t_stack **stack_a)
{
	if (!check_number(nums, stack_a))
	{
		if (argc == 2)
		{
			free_split(nums);
			free_stack(stack_a);
		}
		free_stack(stack_a);
		return (0);
	}
	if (is_sorted(*stack_a))
	{
		if (argc == 2)
		{
			free_split(nums);
			free_stack(stack_a);
		}
		free_stack(stack_a);
		return (2);
	}
	return (1);
}

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    char **nums;
    int status;

    if (argc < 2)
        return 0;

    if (argc == 2)
        nums = ft_split(argv[1], ' ');
    else
        nums = argv + 1;

    status = validate_args(nums, argc, &stack_a);

    if (status == 0)
        return error(&stack_a, nums, argc);
    if (status == 2)
    {
        if (argc == 2)
        {
			free_split(nums);
			free_stack(stack_a);
		}
        free_stack(&stack_a);
        return 0;
    }

    check_stack_size(stack_a, stack_b);

    if (argc == 2)
    {
		free_split(nums);
		free_stack(stack_a);
	}
    free_stack(&stack_a);
    free_stack(&stack_b);

    return 0;
}
