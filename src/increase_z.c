#include "fdf.h"

void    make_screen_black(t_vars *vars)
{
    size_t  i;
    size_t  j;

    i = 0;
    while (i < S_HEIGHT)
    {
        j = 0;
        while (j < S_WIDTH)
        {
            my_mlx_pixel_put(&vars->img, j, i, BLACK_COLOR);
            j++;
        }
        i++;
    }
}


int increase_z(int keycode, t_vars *vars)
{
    make_screen_black(vars);
    if (keycode == X)
    {
        printf("koekkoekk\n");
    }
        // vars->z_mul *= 0.9;
    else
        vars->z_mul *= 1.1;
    return (0);
}
