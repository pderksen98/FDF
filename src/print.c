#include "fdf.h"

//Prints the output array : 'vector_array'
void	print_test(t_array array, t_output *output)
{
	size_t	i;

	i = 0;
	while (i < array.input_len)
	{
		printf("struct number: %zu		x: %d		y:%d\n", i, output[i].x, output[i].y);
		i++;
	}
}

//Prints the input array
// void	print_test(t_array array)
// {
// 	size_t	i;

// 	i = 0;
// 	printf("Input length: %zu\n", array.input_len);
// 	while (i < array.input_len)
// 	{
// 		printf("struct number: %zu	x: %f	y: %f	z: %f\n", \
// 		i, array.input[i].x, array.input[i].y, array.input[i].z);
// 		i++;
// 	}
// }
