/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:45:30 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/06 14:07:48 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	print_same_line(int should_print)
{
	if (should_print == 1)
		write(1, "*\n", 2);
}

void	print_final_offset(int offset)
{
	if (offset > 0)
	{
		write_offset(offset, "0123456789abcdef");
		write(1, "\n", 1);
	}
}

int	bufsize(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_hexdump(int fd)
{
	int			bytes_read;
	static int	offset;
	static char	current_line[17];
	static char	previous_line[17];
	int			same_line;

	same_line = 0;
	bytes_read = read(fd, current_line, 16);
	while (bytes_read)
	{
		if (ft_strncmp(current_line, previous_line, bufsize(current_line)) == 0)
			print_same_line(++same_line);
		else
		{
			same_line = 0;
			print_hexdump(offset, current_line);
		}
		offset += bytes_read;
		ft_strncpy(previous_line, current_line, 16);
		clear_buffer(current_line);
		bytes_read = read(fd, current_line, 16);
	}
	print_final_offset(offset);
	close(fd);
}
