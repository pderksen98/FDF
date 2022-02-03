#include "fdf.h"

//Prints the input array : 'vector_array'
void	print_test(t_array array)
{
	size_t	i;

	i = 0;
	printf("Input length: %zu\n", array.input_len);
	while (i < array.input_len)
	{
		printf("x: %f	y: %f	z: %f\n", \
		array.input[i].x, array.input[i].y, array.input[i].z);
		i++;
	}
}
