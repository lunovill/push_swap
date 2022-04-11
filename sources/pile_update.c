#include "push_swap.h"

t_pile  *pile_update(t_pile *p)
{
    if (!p || p->size == 0)
    {
        return (NULL);
    }
	ft_index(p);
	p->min = pile_min(p->first, p->first);
	p->max = pile_max(p->first, p->first);
    return (p);
}