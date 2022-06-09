/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:54:56 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/02 16:03:07 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	void	mors_it(int spid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		c = *str++;
		i = 8;
		while (i--)
		{
			if (c >> i & 1)
				kill(spid, SIGUSR1);
			else
				kill(spid, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(spid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		if (argc != 3)
			ft_putstr_fd("Bad usage of parameters.", 1);
		else if (!ft_strlen(argv[2]))
			ft_putstr_fd("There is no message to signal.", 1);
		return (1);
	}
	mors_it(ft_atoi(argv[1]), argv[2]);
	return (0);
}
