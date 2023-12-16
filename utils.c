/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:18:28 by dscholz           #+#    #+#             */
/*   Updated: 2023/12/14 16:25:58 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && --n && str1[i] != '\0' && str2[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

double	atodouble(char *str)
{
	double	res;
	double	decimal;
	int		op;
	double	div;

	res = 0;
	decimal = 0;
	op = 1;
	div = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			op = op * -1;
	while (*str >= '0' && *str <= '9' && *str != '.' && *str)
		res = res * 10 + (*str++ - 48);
	if (*str == '.')
		str++;
	while (*str != '\0')
	{
		div /= 10;
		decimal += (*str++ - 48) * div;
	}
	return ((res + decimal) * op);
}
