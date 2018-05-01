#include "ft_printf.h"
#include <time.h>

t_bool		is_unique(int tmp, int *arr, int counter)
{
	int		i;

	i = -1;
	while (++i < counter)
	{
		if (arr[i] == tmp)
			return (FALSE);
	}
	return (TRUE);
}

int			main(int ac, char **av)
{
    time_t	t;
	int		sign;
	int		count;
	int		limit;
	int		*output;
	int		tmp;

	if (ac == 2)
	{
		if (!ft_aredigits(av[1]))
			ft_printf("Error\n");
		else
		{
    		srand((unsigned)time(&t));
			if (ft_aredigits(av[1]))
			{
				count = ft_atoi(av[1]);
				output = ft_memalloc(sizeof(int) * count);
				ft_bzero(output, sizeof(int) * count);
				limit = count * 2;
				int i = 0;
				while (i < count)
				{
					sign = (rand() % 2) ? -1 : 1;
					tmp = (rand() % limit) * sign;
					if (is_unique(tmp, output, i))
					{
						output[i] = tmp;
						i++;
					}
				}
				i = -1;
				while (++i < count)
				{
					ft_printf("%d ", output[i]);
				}
				ft_printf("\n");
			}
		}
	}
	else
	{
		ft_printf("Usage: ./rand <count> <limit>\n");
		ft_printf("count of randomly generated numbers\n");
	}
    return (0);
}