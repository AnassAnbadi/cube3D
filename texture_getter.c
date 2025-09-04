#include "cube.h"


// unsigned int get_texture_color(t_data *data, int tex_x, int tex_y)
// {

// 	char	*dst;

// 	dst = data->tex.addr + (tex_y * data->tex.line_length + tex_x * (data->tex.bits_per_pixel / 8));
// 	return *(unsigned int*)dst;

// }
// void ft_put_texture(t_data *data, int x, int y, int line_height, int end)
// {
//     static double tex_y ;
//     static double tex_x ;

//     unsigned int color ;// = get_texture_color(data, (x % data->tex.width) , tex_y);

//     // if (y == end)
//     //     tex_y = 0.0;
//     // if (x == 0) 
//     //     tex_x = 0.0;
//     // if (line_height > data->tex.height)
//     //     {
            
//     //         color  = get_texture_color(data, (x % data->tex.width) , ((int)tex_y) % data->tex.height);
//     //         tex_y += (data->tex.height / line_height);
//     //     }
//     // else
//     //     {
            
//             color  = get_texture_color(data, x % data->tex.width , ((int)tex_y) % data->tex.height);
//             tex_y += (data->tex.height / line_height);
//             if (x == 2 )
//                 printf("tex_y: %f  line_height: %d\n", tex_y, line_height);
//             // tex_x += (data->tex.height / line_height);
//             // if (tex_y >= 1.0)
//             // {
//             //     tex_y -= 1.0;
//             // }
//             // else
//             //     ft_put_px(data, x, y, color);
            
//         // }
//     ft_put_px(data, x, y, color);
//     if (y == end)
//         tex_y = 0.0;
// }



#include "cube.h"

int get_tex_color(t_texture *tex, int tex_x, int tex_y)
{
    char    *dst;

    dst = tex->addr + (tex_y * tex->line_length + tex_x * (tex->bits_per_pixel / 8));
    return (*(unsigned int *)dst);
}

void ft_put_texture(t_data *data, int x, int y, int line_height, int start, int tex_x)
{
    // choose the texture
    // t_img *tex = data->wall_tex; // <-- use the correct texture depending on wall side
    if (y >= HEIGHT)
        return;
    int tex_height = data->tex.height;
    int tex_width = data->tex.width;

    // vertical position in texture
    // 1. calculate how far we are in the wall slice (0.0 -> 1.0)
    double tex_pos = (double)(y - start) / line_height;
    

    // 2. map it to texture Y coordinate
    int tex_y = (int)(tex_pos * tex_height);
    if (tex_y < 0)
        tex_y = 0;
    if (tex_y >= tex_height)
        tex_y = tex_height - 1;

    // tex_x is usually calculated during raycasting when you know hit position
    // int tex_x = (int)((x + data->tex._x) % (tex_width )); // Example calculation, adjust as needed
    // if (tex_x < 0)
    //     tex_x = 0;
    // if (tex_x >= tex_width)
    //     tex_x = tex_width - 1;

    // get the color from texture
    int color = get_tex_color(&data->tex, tex_x, tex_y);

    // put pixel to screen
    ft_put_px(data, x, y, color);
}
