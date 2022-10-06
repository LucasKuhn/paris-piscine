/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:01:16 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/06 17:31:27 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	print_invalid_bytes_error(char *str, char *program_name)
{
	ft_puterror(program_name);
	ft_puterror(": invalid number of bytes: ");
	ft_puterror("‘");
	ft_puterror(str);
	ft_puterror("’");
	ft_puterror("\n");
	return (1);
}

int	invalid_bytes(char *argv[], char *program_name)
{
	if (argv[0][2] && ft_str_is_numeric(&argv[0][2]))
		return (0);
	if (argv[1] && ft_str_is_numeric(argv[1]))
		return (0);
	if (argv[0][2] && !ft_str_is_numeric(&argv[0][2]))
		return (print_invalid_bytes_error(&argv[0][2], program_name));
	if (argv[1] && !ft_str_is_numeric(argv[1]))
		return (print_invalid_bytes_error(argv[1], program_name));
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	bytes;
	int	filecount;

	if (argc < 2)
		return (1);
	i = 1;
	filecount = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "-c", 2) == 0)
		{
			if (invalid_bytes(&argv[i], argv[0]))
				return (1);
			if (argv[i][2] && ft_str_is_numeric(&argv[i][2]))
				bytes = ft_atoi(&argv[i][2]);
			else if (argv[i + 1] && ft_str_is_numeric(argv[i + 1]))
				bytes = ft_atoi(argv[i + 1]);
		}
		if (ft_strncmp(argv[i], "-c", 2) != 0 && !ft_str_is_numeric(argv[i]))
			filecount++;
		i++;
	}
	ft_tail(argc, argv, bytes, filecount);
	return (0);
}
