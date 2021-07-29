/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:18:47 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/29 04:20:10 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_traitement_char(int server_pid, char c)
{
	int	count;

	count = 8;
	while (--count)
	{
		if((c >> count & 1) == 0)
			kill(server_pid, SIGUSR1);
		else if((c >> count & 1) == 1)
			kill(server_pid, SIGUSR2);
		usleep(100);
	}
}

void	ft_envoyer_message(int server_pid, char *message)
{
	int	i;

	i = -1;
	while (message[++i])
		ft_traitement_char(server_pid, message[i]);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
		perror("./client [Server PID] [Message]");
	server_pid = ft_atoi(argv[1]);
	ft_envoyer_message(server_pid, argv[2]);
	return (0);
}
