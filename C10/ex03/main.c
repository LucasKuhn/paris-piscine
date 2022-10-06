/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:13:08 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/06 21:03:21 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	read_files_into_tmp(int argc, char *argv[], char *program)
{
	int		hexdump_fd;
	int		file_fd;
	char	tmp[1];

	hexdump_fd = open("/tmp/hexdump", O_RDWR | O_CREAT | O_TRUNC, 0666);
	while (--argc)
	{
		if (ft_strncmp(*argv, "-C", 2) == 0 && argv++)
			continue ;
		if (ft_strncmp(*argv, "--", 2) == 0 && argv++)
			continue ;
		file_fd = open(*argv, O_RDWR);
		if (file_fd == -1 && print_error(*argv, program) && argv++)
			continue ;
		while (read(file_fd, tmp, 1) > 0)
			write(hexdump_fd, tmp, 1);
		close(file_fd);
		argv++;
	}
	close(hexdump_fd);
}

void	read_stdin_into_tmp(void)
{
	char	buffer[1];
	int		hexdump_fd;

	hexdump_fd = open("/tmp/hexdump", O_RDWR | O_CREAT | O_TRUNC, 0666);
	while (read(0, buffer, 1) > 0)
		write(hexdump_fd, buffer, 1);
	close(hexdump_fd);
}

int	main(int argc, char *argv[])
{
	char	*program;

	program = argv[0];
	argv++;
	if (argc == 2 && ft_strncmp(argv[0], "-C", 2) == 0)
		read_stdin_into_tmp();
	else if (argc == 3 && ft_strncmp(argv[1], "--", 2) == 0)
		read_stdin_into_tmp();
	else
		read_files_into_tmp(argc, argv, program);
	ft_hexdump(open("/tmp/hexdump", O_RDONLY));
	return (0);
}
