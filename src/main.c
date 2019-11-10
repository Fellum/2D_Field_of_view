#include "libft.h"
#include "SDL.h"
#include "structs.h"
#include "vector.h"

#define W_SIZE 1000

t_list	*fill_objects()
{
	t_list *res;

	res = ft_lstinit();

	ft_lstadd(res, ft_lstnew_node((&(t_object){0, 200, 400, 400}), sizeof(t_object)));
	return (res);
}

double	circle_collision(t_object *obj, t_vector *start, t_vector *dir)
{
	t_vector tmp = {obj->pos.x, obj->pos.y, 0};
	double res = sphere_intersection(start, dir, &tmp, obj->size);
	return (res);
}

t_int4	get_fow_ray(t_list	*objs, t_vector *start, t_vector *dir)
{
	t_list_node *cur;
	double tmp;
	double res;
	t_vector	vres;
	cur = objs->begin;
	res = NAN;
	while (cur)
	{
		tmp = circle_collision(cur->content, start, dir);
		if (!isnan(tmp))
			res = res > tmp ? tmp : (isnan(res) ? tmp : res);
		cur = cur->next;
	}

	if (isnan(res))
		return ((t_int4){0, 0, 0, 0, 1});

	vres = ft_vecscale(dir, res);
	vres = ft_vecsum(&vres, start);

	return ((t_int4){(int)start->x, (int)start->y, (int)vres.x, (int)vres.y});
}

void	draw_fow(SDL_Renderer *rend, int x, int y, t_list *objs)
{
	t_int4	tmp;

	t_vector	start = {x, y, 0};
	t_vector	dir;

	dir.z = 0;
	SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
	for (int i = 0; i < W_SIZE; i++)
	{
		dir.x = 0 - start.x;
		dir.y = i - start.y;
		tmp = get_fow_ray(objs, &start, &dir);
		if (tmp.err)
			SDL_RenderDrawLine(rend, x, y, 0, i);
		else
			SDL_RenderDrawLine(rend, tmp.x, tmp.y, tmp.z, tmp.w);
	}
	for (int i = 0; i < W_SIZE; i++)
	{
		dir.x = i - start.x;
		dir.y = 0 - start.y;
		tmp = get_fow_ray(objs, &start, &dir);
		if (tmp.err)
			SDL_RenderDrawLine(rend, x, y, i, 0);
		else
			SDL_RenderDrawLine(rend, tmp.x, tmp.y, tmp.z, tmp.w);
	}
	for (int i = 0; i < W_SIZE; i++)
	{
		dir.x = W_SIZE - start.x;
		dir.y = i - start.y;
		tmp = get_fow_ray(objs, &start, &dir);
		if (tmp.err)
			SDL_RenderDrawLine(rend, x, y, W_SIZE, i);
		else
			SDL_RenderDrawLine(rend, tmp.x, tmp.y, tmp.z, tmp.w);
	}
	for (int i = 0; i < W_SIZE; i++)
	{
		dir.x = i - start.x;
		dir.y = W_SIZE - start.y;

		tmp = get_fow_ray(objs, &start, &dir);
		if (tmp.err)
			SDL_RenderDrawLine(rend, x, y, i, W_SIZE);
		else
			SDL_RenderDrawLine(rend, tmp.x, tmp.y, tmp.z, tmp.w);
	}
}

int	main()
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		e;
	int				status;
	t_list			*objects;

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return (1);
	}
	if (SDL_CreateWindowAndRenderer(W_SIZE, W_SIZE, SDL_WINDOW_OPENGL, &window, &renderer))
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return (1);
	}
	objects = fill_objects();
	status = 1;
	t_object	*tmp = objects->begin->content;

	while (status)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				status = 0;
			else if (e.type == SDL_MOUSEMOTION)
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
				SDL_RenderClear(renderer);

				tmp->pos.x = e.motion.x;
				tmp->pos.y = e.motion.y;

				draw_fow(renderer, e.motion.x, e.motion.y, objects);
				SDL_RenderPresent(renderer);
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (e.button.button == SDL_BUTTON_LEFT)
					ft_lstadd(objects, ft_lstnew_node((&(t_object){0, 10, e.motion.x, e.motion.y}), sizeof(t_object)));
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
				SDL_RenderClear(renderer);
				draw_fow(renderer, tmp->pos.x, tmp->pos.y, objects);
				SDL_RenderPresent(renderer);
			}
			else if (e.type == SDL_MOUSEWHEEL)
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
				SDL_RenderClear(renderer);
				draw_fow(renderer, tmp->pos.x, tmp->pos.y, objects);
				SDL_RenderPresent(renderer);
				tmp->size += e.wheel.y;

			}
		}

	}

	SDL_DestroyWindow(window);
	//SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}

