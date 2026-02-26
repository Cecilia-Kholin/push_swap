#include "push_swap.h"

s_stack	*new_node(int value)
{
	s_stack	*node;

	node = malloc(sizeof(s_stack));
	if (!node)
		return (NULL);

	node->value = value;
	node->next = NULL;

	return (node);
}
