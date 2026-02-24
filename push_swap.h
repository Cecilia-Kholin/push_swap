/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:45:55 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/24 11:44:43 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack *new_node(int value);
t_stack *get_bottom(t_stack *stack);
t_stack *get_second_last(t_stack *stack);
int	ft_atoi(const char *nptr);
// FUNCIONES DE SORT
void sort_three(t_stack **a);
void sort_four(t_stack **a, t_stack **b);
void sort_five(t_stack **a, t_stack **b);
void push_min_to_b(t_stack **a, t_stack **b);
void k_sort(t_stack **a, t_stack **b);
// FUNCIONES DE MOVIMIENTOS
void move_sa(t_stack **a);
void move_sb(t_stack **b);
void move_ss(t_stack **a, t_stack **b);
void move_pa(t_stack **a, t_stack **b);
void move_pb(t_stack **a, t_stack **b);
void move_ra(t_stack **a);
void move_rb(t_stack **b);
void move_rr(t_stack **a, t_stack **b);
void move_rra(t_stack **a);
void move_rrb(t_stack **b);
void move_rrr(t_stack **a, t_stack **b);

// FUNCIONES DE STACK
int stack_size(t_stack *stack);
void push_to_stack(t_stack **stack, int n);
int is_sorted(t_stack *stack);
int is_duplicate(t_stack *stack, int n);
int get_min(t_stack *stack);
int error(void);
int check_numerber(int argc, char **argv, t_stack **a);
void	ft_putstr(char *s);
void assign_indices_no_array(t_stack *a);
int	max_bits(t_stack *a);
void	ksort_radix(t_stack **a, t_stack **b);
int	is_valid_number(const char *s);
int	ft_isdigit(int c);


#endif