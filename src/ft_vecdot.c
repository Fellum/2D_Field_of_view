#include "vector.h"

double		ft_vecdot(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vector	ft_veccdot(t_vector *v1, t_vector *v2)
{
	return ((t_vector){v1->y * v2->z - v1->z * v2->y,
			v1->z * v2->x - v1->x * v2->z,
			v1->x * v2->y - v1->y * v2->x});
}