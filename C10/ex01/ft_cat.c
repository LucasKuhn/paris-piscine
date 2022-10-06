/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:03:58 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/05 20:07:36 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>  // errno
#include <fcntl.h>  // open
#include <string.h> // strerror
#include <unistd.h> // write read close

void	ft_puterror(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, str, len);
	return ;
}

void	ft_cat_stdin(void)
{
	char	buffer[1];

	while (read(0, buffer, 1) > 0)
		write(1, buffer, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_cat_file(char *filename)
{
	int		fd;
	char	buffer[1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("ft_cat: ");
		ft_puterror(filename);
		ft_puterror(": ");
		ft_puterror(strerror(errno));
		ft_puterror("\n");
	}
	else
	{
		while (read(fd, buffer, 1) > 0)
			write(1, buffer, 1);
		close(fd);
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		ft_cat_stdin();
	if (argc == 2 && ft_strcmp(argv[1], "--") == 0)
		ft_cat_stdin();
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-") == 0)
			ft_cat_stdin();
		else if (ft_strcmp(argv[i], "--") == 0)
		{
			i++;
			continue ;
		}
		else
			ft_cat_file(argv[i]);
		i++;
	}
	return (0);
}
