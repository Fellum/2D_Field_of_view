//
// Created by Jasper Leann on 09/11/2019.
//

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_int2
{
	int			x;
	int			y;
}				t_int2;

typedef struct	s_int4
{
	int			x;
	int			y;
	int			z;
	int			w;
	int			err;
}				t_int4;

typedef struct	s_double4
{
	double			x;
	double			y;
	double			z;
	double			w;
	double			err;
}				t_double4;

typedef struct	s_object
{
	int			type;
	int 		size;
	t_int2		pos;
}				t_object;

#endif
