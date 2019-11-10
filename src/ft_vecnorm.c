#include "vector.h"

t_vector	ft_vecnorm(t_vector *v)
{
	return (ft_vecscale(v, 1.0 / ft_veclen(v)));
}