/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:02:56 by alyasar           #+#    #+#             */
/*   Updated: 2022/06/02 15:55:23 by alyasar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	signal_take(int sig)
{
	static int				i;
	static unsigned char	c;

	if (sig == SIGUSR1)
		c++;
	if (i == 7)
	{
		if (c == 0)
		{
			i = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
		i = 0;
		return ;
	}
	c <<= 1;
	i++;
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			block_mask;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGUSR1);
	sigaddset(&block_mask, SIGUSR2);
	sa.sa_handler = &signal_take;
	sa.sa_mask = block_mask;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
