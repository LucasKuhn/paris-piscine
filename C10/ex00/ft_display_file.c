/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:36:25 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/03 12:58:58 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>  // open
#include <unistd.h> // write read close

void	ft_display_file(char *filename)
{
	int		fd;
	char	buffer[1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		write(2, "Cannot read file.\n", 18);
	else
	{
		while (read(fd, buffer, 1) > 0)
			write(1, buffer, 1);
		close(fd);
	}
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	if (argc == 2)
		ft_display_file(argv[1]);
	return (0);
}
