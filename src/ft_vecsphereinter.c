#include "vector.h"
#include <math.h>
#include "stdio.h"

double		find_pos_min(double a, double b)
{
	if (a >= 0 && b >= 0)
		return (a > b ? b : a);
	else if (a >= 0 && b < 0)
		return (a);
	else if (b >= 0)
		return (b);
	else
		return (NAN);
}

t_vector	vecsphere_intersection(t_vector *st, t_vector *dir, t_vector *cent, double r)
{
	double 		a;
	double 		b;
	double 		c;
	double		res;
	t_vector	tmp;

	a = ft_vecdot(dir, dir);
	tmp = ft_vecsub(st, cent);
	b = ft_vecdot(dir, &tmp);
	c = ft_vecdot(&tmp, &tmp) - r * r;
	c = b * b - a * c;
	tmp = (t_vector){NAN, NAN, NAN};
	if (c >= 0)
	{
		c = sqrt(c) / a;
		res = find_pos_min(-b / a + c, -b / a - c);
		if (res >= 0)
		{
			tmp = ft_vecscale(dir, res);
			tmp = ft_vecsum(&tmp, st);
		}
	}
	return (tmp);
}

double		sphere_intersection(t_vector *st, t_vector *dir, t_vector *cent, double r)
{
	double 		a;
	double 		b;
	double 		c;
	double		res;
	t_vector	tmp;

	a = ft_vecdot(dir, dir);
	tmp = ft_vecsub(st, cent);
	b = ft_vecdot(dir, &tmp);
	c = ft_vecdot(&tmp, &tmp) - r * r;
	c = b * b - a * c;
	res = NAN;
	if (c >= 0)
	{
		c = sqrt(c) / a;
		res = find_pos_min(-b / a + c, -b / a - c);
	}
	return (res);
}