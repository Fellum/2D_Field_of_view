#include "vector.h"

t_vector	ft_vecsum(t_vector *v1, t_vector *v2)
{
	return ((t_vector){v1->x + v2->x, v1->y + v2->y, v1->z + v2->z});
}

t_vector	ft_vecsub(t_vector *v1, t_vector *v2)
{
	return ((t_vector){v1->x - v2->x, v1->y - v2->y, v1->z - v2->z});
}