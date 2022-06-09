/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:09:11 by alyasar           #+#    #+#             */
/*   Updated: 2022/03/05 12:11:05 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putstr_fd(ft_itoa(n), fd);
}

static char	*revstr(char *str, size_t len)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
	return (str);
}

static int	make_pos(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	int		neg;

	neg = 0;
	if (n < 0)
	{
		str = malloc(12 * sizeof(char));
		neg = 1;
	}
	else
		str = malloc(11 * sizeof(char));
	if (n == 0)
		str[0] = '0';
	i = 0;
	while (n != 0)
	{
		str[i++] = make_pos(n % 10) + '0';
		n /= 10;
	}
	if (neg)
		str[i] = '-';
	return (revstr(str, ft_strlen(str)));
}
