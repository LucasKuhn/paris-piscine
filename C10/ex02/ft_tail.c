/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:01:13 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/06 21:00:55 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	print_filename(char *filename)
{
	static int	print_break;

	if (print_break)
		ft_putstr("\n");
	print_break = 1;
	ft_putstr("==> ");
	if (is_stdin(filename))
		ft_putstr("standard input");
	else
		ft_putstr(filename);
	ft_putstr(" <==\n");
}

void	print_error(char *filename, char *program)
{
	ft_puterror(program);
	if (errno == 2)
	{
		ft_puterror(": cannot open '");
		ft_puterror(filename);
		ft_puterror("' for reading: ");
	}
	else
	{
		ft_puterror(": error reading '");
		ft_puterror(filename);
		ft_puterror("': ");
	}
	ft_puterror(strerror(errno));
	ft_puterror("\n");
}

void	ft_tail_file(char *filename, int bytes, int filecount, char *program)
{
	char	buffer[8192];
	int		fd;
	int		read_bytes;

	fd = open(filename, O_RDWR);
	if (fd == -1)
		return (print_error(filename, program));
	if (filecount > 1)
		print_filename(filename);
	read_bytes = read(fd, buffer, 8192);
	close(fd);
	if (read_bytes < bytes)
		write(1, buffer, read_bytes);
	else
		write(1, &buffer[read_bytes - bytes], bytes);
}

void	ft_tail_stdin(int bytes)
{
	char	tmp[1];
	char	buffer[8192];
	int		read_bytes;

	read_bytes = 0;
	while (read(0, tmp, 1) > 0)
		buffer[read_bytes++] = *tmp;
	if (read_bytes < bytes)
		write(1, buffer, read_bytes);
	else
		write(1, &buffer[read_bytes - bytes], bytes);
}

void	ft_tail(int argc, char *argv[], int bytes, int filecount)
{
	int	i;

	if (bytes == 0)
		return ;
	if (filecount == 0)
		ft_tail_stdin(bytes);
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "-c", 2) != 0 && !ft_str_is_numeric(argv[i]))
		{
			if (is_stdin(argv[i]))
				ft_tail_stdin(bytes);
			else
				ft_tail_file(argv[i], bytes, filecount, argv[0]);
		}
		i++;
	}
}
