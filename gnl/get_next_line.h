/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 14:21:10 by pderksen      #+#    #+#                 */
/*   Updated: 2022/01/25 11:57:12 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# define BUFFER_SIZE 42

typedef struct s_list
{
	char	*line;
	char	*newline;
	int		line_count;
	int		buf_count;
}	t_list;

char	*ft_reader(int fd, char *buf, t_list x);
char	*get_next_line(int fd);
char	*ft_line_add_buf(char *buf, t_list x);
char	*ft_line_maker(char *buf, t_list x);
void	new_buffer(char *buf, t_list x);
#endif
