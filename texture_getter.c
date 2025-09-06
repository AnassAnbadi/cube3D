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

void ft_put_texture(t_data *data, int x, int y, t_prm prm)
{
	int		tex_height;
	double	tex_pos;
	int		tex_y;

	if (y >= HEIGHT)
		return;
	tex_height = data->tex[data->wall].height;
	tex_pos = (double)(y - prm.start) / prm.line_height;	
	tex_y = (int)(tex_pos * tex_height);
	if (tex_y >= tex_height)
		tex_y = tex_height - 1;
	ft_put_px(data, x, y, get_tex_color(&data->tex[data->wall], prm.tex_x, tex_y));
}
