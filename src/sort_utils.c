#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int n;

	n = 1;
	if (nb <= 0)
		return (0);
	while (n <= 46340)
	{
		if (n * n == nb)
			return (n);
		else if (n * n > nb)
			return (0);
		n++;
	}
	return (0);
}
