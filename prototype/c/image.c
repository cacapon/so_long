#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./cacapon.xpm";
	int		img_width;
	int		img_height;

	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 300,300, "image");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_loop(mlx);
}
