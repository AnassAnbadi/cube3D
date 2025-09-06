#include "cube.h"


static void move_forward(t_data *data)
{
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x + data->p_dir.x * MOVE_SPEED * 4)] 
		== '0')
	{
		data->player.x += data->p_dir.x * MOVE_SPEED;
	}
	if (data->map[(int)(data->player.y 
		+ data->p_dir.y * MOVE_SPEED * 4)]
		[(int)(data->player.x)] == '0')
	{
		data->player.y += data->p_dir.y * MOVE_SPEED;
	}
}

static void move_backward(t_data *data)
{
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x - data->p_dir.x * MOVE_SPEED * 4)] 
		== '0')
	{
		data->player.x -= data->p_dir.x * MOVE_SPEED;
	}
	if (data->map[(int)(data->player.y 
		- data->p_dir.y * MOVE_SPEED * 4)]
		[(int)(data->player.x)] == '0')
	{
		data->player.y -= data->p_dir.y * MOVE_SPEED;
	}
}

static void move_right(t_data *data)
{
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x + data->plane.x * MOVE_SPEED * 4)] 
		== '0')
	{
		data->player.x += data->plane.x * MOVE_SPEED;
	}
	if (data->map[(int)(data->player.y 
		+ data->plane.y * MOVE_SPEED * 4)]
		[(int)(data->player.x)] == '0')
	{
		data->player.y += data->plane.y * MOVE_SPEED;
	}
}

static void move_left(t_data *data)
{
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x - data->plane.x * MOVE_SPEED * 4)] 
		== '0')
	{
		data->player.x -= data->plane.x * MOVE_SPEED;
	}
	if (data->map[(int)(data->player.y 
		- data->plane.y * MOVE_SPEED * 4)]
		[(int)(data->player.x)] == '0')
	{
		data->player.y -= data->plane.y * MOVE_SPEED;
	}
}

void keyboard_move(t_data *data)
{
	if (data->key_board2 == W)
		move_forward(data);
	if (data->key_board2 == S)
		move_backward(data);
	if (data->key_board == D)
		move_right(data);
	if (data->key_board == A)
		move_left(data);
}
