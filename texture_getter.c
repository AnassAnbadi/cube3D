#include "cube.h"


unsigned int get_texture_color(t_data *data, int tex_x, int tex_y)
{

	char	*dst;

	dst = data->tex.addr + (tex_y * data->tex.line_length + tex_x * (data->tex.bits_per_pixel / 8));
	return *(unsigned int*)dst;

}
void ft_put_texture(t_data *data, int x, int y, int line_height, int end)
{
    static double tex_y ;

    unsigned int color ;// = get_texture_color(data, (x % data->tex.width) , tex_y);

    if (y == end)
        tex_y = 0.0;
    // if (line_height > data->tex.height)
    //     {
            
    //         color  = get_texture_color(data, (x % data->tex.width) , ((int)tex_y) % data->tex.height);
    //         tex_y += (data->tex.height / line_height);
    //     }
    // else
    //     {
            
            color  = get_texture_color(data, (x % data->tex.width) , ((int)tex_y) % data->tex.height);
            tex_y += (data->tex.height / line_height);
            // if (tex_y >= 1.0)
            // {
            //     tex_y -= 1.0;
            // }
            // else
            //     ft_put_px(data, x, y, color);
            
        // }
    ft_put_px(data, x, y, color);
}