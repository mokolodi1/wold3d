#include "wolf3d.h"

int					key_hook(int keycode, t_environment *env)
{
	(void)env;
	ft_putstr("key: ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
