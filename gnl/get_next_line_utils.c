/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 14:20:51 by pderksen      #+#    #+#                 */
/*   Updated: 2022/01/18 15:13:28 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//adds buffer to the existing line and returns this newline
char	*ft_line_add_buf(char *buf, t_list x)
{
	int	count;
	int	count1;

	count = 0;
	while (count < x.line_count)
	{
		x.newline[count] = x.line[count];
		count++;
	}
	count1 = 0;
	while (count1 < x.buf_count)
	{
		x.newline[count] = buf[count1];
		count++;
		count1++;
	}
	x.newline[count] = '\0';
	return (x.newline);
}

//allocates memmory for the newline, makes the newline and frees the 'old' line
char	*ft_line_maker(char *buf, t_list x)
{
	x.line_count = 0;
	while (x.line[x.line_count])
		x.line_count++;
	x.newline = (char *)malloc((x.line_count + x.buf_count + 1) * sizeof(char));
	if (!x.newline)
		return (NULL);
	x.newline = (ft_line_add_buf(buf, x));
	free (x.line);
	return (x.newline);
}

void	new_buffer(char *buf, t_list x)
{
	int	i;

	i = 0;
	while (x.buf_count < BUFFER_SIZE)
	{
		buf[i] = buf[x.buf_count];
		i++;
		x.buf_count++;
	}
	while (i < BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
}
