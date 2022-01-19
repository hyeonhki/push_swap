#include "push_swap.h"

void	sort_three_flag(t_element **a)
{
	int	max;
	int	min;
	
	find_maxmin(3, *a, &max, &min);
	if ((*a)->val == min)
	{
		*a = rab(*a, "ra");
		*a = sab(*a, "sa");
		*a = rrab(*a, "rra");
		return ;
	}
	else if ((*a)->next->val != max)
		*a = sab(*a, "sa");
	*a = rab(*a, "ra");
	*a = sab(*a, "sa");
	*a = rrab(*a, "rra");
	if ((*a)->val != min)
		*a = sab(*a, "sa");
}