#include "cube.h"


int mouse_move(int x, int y, t_data *data)
{
    static int last_x = WIDTH / 2;
    int delta_x;
    double angle;
    double old_dir_x;
    double old_plane_x;
    
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return (0);
    delta_x = x - last_x;
    last_x = x;
    angle = delta_x * 0.005;
    data->p_dir.x;
    data->p_dir.x = data->p_dir.x * cos(angle) - data->p_dir.y * sin(angle);
    data->p_dir.y = old_dir_x * sin(angle) + data->p_dir.y * cos(angle);
    old_plane_x = data->plane.x;
    data->plane.x = data->plane.x * cos(angle) - data->plane.y * sin(angle);
    data->plane.y = old_plane_x * sin(angle) + data->plane.y * cos(angle);
    ft_raycasting(data, 0, 0.0);
    return (0);
}
// void keyboard_move(t_data *data)
// {
//     if (data->key_board2 == W)
//     {
//         if (data->map[(int)(data->player.y)][(int)(data->player.x + data->p_dir.x * MOVE_SPEED*4)] == '0')
//             data->player.x += data->p_dir.x * MOVE_SPEED;
//         if (data->map[(int)(data->player.y + data->p_dir.y * MOVE_SPEED*4)][(int)(data->player.x)] == '0')
//             data->player.y += data->p_dir.y * MOVE_SPEED;
//     }
//     if (data->key_board2 == S)
//     {
//         if (data->map[(int)(data->player.y)][(int)(data->player.x - data->p_dir.x * MOVE_SPEED*4)] == '0')
//             data->player.x -= data->p_dir.x * MOVE_SPEED;
//         if (data->map[(int)(data->player.y - data->p_dir.y * MOVE_SPEED*4)][(int)(data->player.x)] == '0')
//             data->player.y -= data->p_dir.y * MOVE_SPEED;
//     }
//     if (data->key_board == D)
//     {
//         if (data->map[(int)(data->player.y)][(int)(data->player.x + data->plane.x * MOVE_SPEED * 4)] == '0')
//             data->player.x += data->plane.x * MOVE_SPEED;
//         if (data->map[(int)(data->player.y + data->plane.y * MOVE_SPEED *4)][(int)(data->player.x)] == '0')
//             data->player.y += data->plane.y * MOVE_SPEED;
//     }
//     if (data->key_board == A)
//     {
//         if (data->map[(int)(data->player.y)][(int)(data->player.x - data->plane.x * MOVE_SPEED*4)] == '0')
//             data->player.x -= data->plane.x * MOVE_SPEED;
//         if (data->map[(int)(data->player.y - data->plane.y * MOVE_SPEED*4)][(int)(data->player.x)] == '0')
//             data->player.y -= data->plane.y * MOVE_SPEED;
//     }
// }





int move_(t_data *data)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = data->p_dir.x;
    old_plane_x = data->plane.x;
    if (data->key_fleche == LEFT)
    {
        data->p_dir.x = data->p_dir.x * cos(ROT) + data->p_dir.y * sin(ROT);
        data->p_dir.y = -old_dir_x * sin(ROT) + data->p_dir.y * cos(ROT);
        data->plane.x = data->plane.x * cos(ROT) + data->plane.y * sin(ROT);
        data->plane.y = -old_plane_x * sin(ROT) + data->plane.y * cos(ROT);
    }
    if (data->key_fleche == RIGHT)
    {
        data->p_dir.x = data->p_dir.x * cos(ROT) - data->p_dir.y * sin(ROT);
        data->p_dir.y = old_dir_x * sin(ROT) + data->p_dir.y * cos(ROT);
        data->plane.x = data->plane.x * cos(ROT) - data->plane.y * sin(ROT);
        data->plane.y = old_plane_x * sin(ROT) + data->plane.y * cos(ROT);
    }
    keyboard_move(data);
    if(data->key_fleche != 0 || data->key_board != -1 || data->key_board2 != -1)
        ft_raycasting(data, 0, 0.0);
    return (0);
}

int key_press(int keycode, t_data *data)
{
    if (keycode == ESC ) // Escape key
        exit(0);//////////////////////////////////////////////////
    if (keycode == LEFT || keycode == RIGHT)
        data->key_fleche = keycode;
    if (keycode == A || keycode == D)
        data->key_board = keycode;
    if (keycode == W || keycode == S)
        data->key_board2 = keycode;
    return (0);
}

int key_release(int keycode, t_data *data)
{
    if (keycode == LEFT || keycode == RIGHT)
        data->key_fleche = 0;
    if (keycode == A || keycode == D)
        data->key_board = -1;
    if (keycode == W || keycode == S)
        data->key_board2 = -1;
    return (0);
}

int close_window(void *param)
{
    (void)param;
    exit(0);////////////////////////////////////
    return (0);
}
