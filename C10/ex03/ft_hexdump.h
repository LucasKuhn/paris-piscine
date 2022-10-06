/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:16:28 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/06 18:03:04 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <fcntl.h>  // open
# include <unistd.h> // write read close
# include <string.h> // strerror
# include <errno.h>  // errno
# include <libgen.h> // basename

int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	ft_hexdump(int fd);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	print_hexdump(int offset, char buffer[16]);
void	clear_buffer(char buffer[16]);
void	write_offset(int number, char *base);
int		ft_isspace(char c);
int		print_error(char *str, char *program);
void	ft_puterror(char *str);

#endif
