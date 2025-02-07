/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:09:50 by amismail          #+#    #+#             */
/*   Updated: 2025/02/04 18:16:47 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <minitalk.h>

static int	g_ack = 0;

static int		check_pid(char **argv);
static void		send_message(int pid, char *message);
static void		send_char(int c, int pid);
static void		ack(int sig, siginfo_t *info, void *context);

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
		return (1);
	pid = check_pid(argv);
	if (pid == -1)
		return (1);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = ack;
	sigaction(SIGUSR1, &sa, NULL);
	send_message(pid, argv[2]);
	return (0);
}

static int	check_pid(char **argv)
{
	int	pid;
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (ft_isdigit(argv[1][i]) == 0)
		{
			ft_printf("Error\ninvalid PID\n");
			return (-1);
		}
		i++;
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || (kill(pid, 0)) != 0)
	{
		ft_printf("Error\ninvalid PID\n");
		return (-1);
	}
	ft_printf("pid is:%d\nthe massege is :%s\n", pid, argv[2]);
	return (pid);
}

static void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		send_char(message[i], pid);
		i++;
	}
	send_char(0, pid);
}

static void	send_char(int c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (((c >> i) & 1) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		ft_printf("signal sent\n");
		while (g_ack == 0)
			;
		g_ack = 0;
		i++;
	}
}

static void	ack(int sig, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (sig == SIGUSR1)
		g_ack = 1;
	ft_printf("ACK reseved\n");
}
