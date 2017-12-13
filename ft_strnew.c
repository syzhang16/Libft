#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*strnew;

	if (!(strnew = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(strnew, size + 1);
	return (strnew);
}
