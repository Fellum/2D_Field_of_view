#include "vector.h"

t_vector	ft_vecscale(t_vector *v, double scale)
{
	return ((t_vector){v->x * scale, v->y * scale, v->z * scale});
}
