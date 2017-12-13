#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	if (!(new = (void*)malloc(sizeof(*new) * size)))
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
