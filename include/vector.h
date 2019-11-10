//
// Created by Jasper Leann on 10/11/2019.
//

#ifndef VECTOR_MATH_VECTOR_H
#define VECTOR_MATH_VECTOR_H

typedef struct	s_vector
{
	double 		x;
	double		y;
	double		z;
}				t_vector;

t_vector	ft_vecsub(t_vector *v1, t_vector *v2);
t_vector	ft_vecsum(t_vector *v1, t_vector *v2);
double		ft_vecdot(t_vector *v1, t_vector *v2);
t_vector	ft_veccdot(t_vector *v1, t_vector *v2);
double		ft_veclen(t_vector *v);
t_vector	ft_vecscale(t_vector *v, double scale);
t_vector	ft_vecnorm(t_vector *v);
double		sphere_intersection(t_vector *st, t_vector *dir, t_vector *cent, double r);
t_vector	vecsphere_intersection(t_vector *st, t_vector *dir, t_vector *cent, double r);

#endif //VECTOR_MATH_VECTOR_H
