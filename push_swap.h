/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:45:55 by maricamp          #+#    #+#             */
/*   Updated: 2026/02/26 17:31:05 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*new_node(int value);
t_stack	*get_bottom(t_stack *stack);
t_stack	*get_second_last(t_stack *stack);
long	ft_atoi(const char *str);
// FUNCIONES DE SORT
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	push_min_to_b(t_stack **a, t_stack **b);
void	k_sort(t_stack **a, t_stack **b);
// FUNCIONES DE MOVIMIENTOS
void	move_sa(t_stack **a);
void	move_sb(t_stack **b);
void	move_ss(t_stack **a, t_stack **b);
void	move_pa(t_stack **a, t_stack **b);
void	move_pb(t_stack **a, t_stack **b);
void	move_ra(t_stack **a);
void	move_rb(t_stack **b);
void	move_rr(t_stack **a, t_stack **b);
void	move_rra(t_stack **a);
void	move_rrb(t_stack **b);
void	move_rrr(t_stack **a, t_stack **b);	

// FUNCIONES DE STACK
int		stack_size(t_stack *stack);
void	push_to_stack(t_stack **stack, int n);
int		is_sorted(t_stack *stack);
int		is_duplicate(t_stack *stack, int n);
int		get_min(t_stack *stack);
void	error(t_stack **stack, char **argv);
int		check_number(char **nums, t_stack **a);
void	ft_putstr(char *s);
void	assign_indices_no_array(t_stack *a);
int		max_bits(t_stack *a);
void	push_to_a(t_stack **a, t_stack **b);
void	push_to_b(t_stack **a, t_stack **b, int range);
int		get_range(int len);
int		is_valid_number(const char *s);
int		ft_isdigit(int c);
t_stack	*find_max(t_stack *stack);
int		get_position(t_stack *stack, t_stack *objetive);
int		check_stack_size(t_stack *stack_a, t_stack *stack_b);
int		count_words(const char *s, char c);
size_t	len_word(const char *s, char c);
char	**free_all(char **v, int n);
void	copy_chars(char *dst, const char *src, size_t len);
char	**ft_split(char const *s, char c);
void	free_split(char **nums);
void free_stack(t_stack **stack);
int		validate_args(char **nums, int argc, t_stack **stack_a);
#endif