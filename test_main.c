#include "mlx.h"

int main (void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (!(mlx_ptr = mlx_init()))
		return (4);
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "mlx_window");
	mlx_loop(mlx_ptr);
}