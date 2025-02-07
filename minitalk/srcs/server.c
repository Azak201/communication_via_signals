/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:17:05 by amismail          #+#    #+#             */
/*   Updated: 2025/02/04 19:12:59 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <minitalk.h>

static char		*str_adder(char *c, char *str);
static void		reset_print(char *c, int *bit_num, char **str);
static void		bit_adder(int bit, char *c, int bit_num);
static void		handler(int signum, siginfo_t *info, void *context);

int	main(void)
{
	int					i;
	struct sigaction	sa;

	i = getpid();
	ft_printf("pid is : %i\n", i);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction (SIGUSR1, &sa, NULL);
	sigaction (SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

static void	handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit_num = 0;
	static char	*str = NULL;
	static int	pid;
	int			cpid;

	if (pid == 0)
		pid = info->si_pid;
	(void) context;
	cpid = info->si_pid;
	if (pid != cpid)
	{
		pid = cpid;
		free(str);
		str = NULL;
		c = 0;
		bit_num = 0;
	}
	bit_adder (signum, &c, bit_num++);
	if (bit_num == 8)
		reset_print(&c, &bit_num, &str);
	if ((kill(cpid, SIGUSR1)) == -1)
		reset_print(0, &bit_num, &str);
}

static void	bit_adder(int bit, char *c, int bit_num)
{
	if (bit == SIGUSR2)
		*c = *c | (1 << bit_num);
}

static void	reset_print(char *c, int *bit_num, char **str)
{
	if (*c == 0)
	{
		ft_printf ("%s\n", *str);
		free (*str);
		*str = NULL;
		*bit_num = 0;
	}
	else
	{
		*str = str_adder(c, *str);
		*bit_num = 0;
		*c = 0;
	}
}

static char	*str_adder(char *c, char *str)
{
	char	*nstr;

	if (!str)
		str = ft_strdup("");
	nstr = ft_strjoin(str, c);
	if (!nstr)
	{
		if (str)
			free (str);
		ft_printf("fail in join");
		exit (1);
	}
	if (str)
		free (str);
	return (nstr);
}
