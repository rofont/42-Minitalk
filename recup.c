Serveur
// static void f_handler(int sign)
// {
// 	static unsigned char c = 0;
// 	static int nb_bit = 0;

// 	c <<= 1;
// 	c |= (sign == SIGUSR1);
// 	nb_bit++;
// 	if (nb_bit == 8)
// 	{
// 		ft_printf("%c", c);
// 		nb_bit = 0;
// 		c = 0;
// 	}
// }



// int main(int argc, char **argv)
// {
// 	(void)argv;
// 	struct sigaction sa_hand;
// 	sa_hand.sa_flags = SA_SIGINFO;
// 	sa_hand.sa_handler = f_handler_recep;
// 	if (argc > 1)
// 	{
// 		ft_printf(R "Error : There are too many arguments \n");
// 		return (0);
// 	}
// 	sigaction(SIGUSR1, &sa_hand, NULL);
// 	sigaction(SIGUSR2, &sa_hand, NULL);
// 	ft_printf(G "Le pid est : %d\n"W , getpid());
// 	while(argc == 1)
// 	{
// 		pause();
// 	}
// 	return (0);
// }

Client
// void f_send_bits(int pid, char c)
// {
// 	int i;

// 	i = 128;
// 	while (i > 0)
// 	{
// 		if (i & c)
// 			kill(pid, SIGUSR1);
// 		else
// 			kill(pid, SIGUSR2);
// 		usleep(150);
// 		i = i >> 1;
// 	}
// }

// int main(int argc, char **argv)
// {
// 	int i;
// 	int pid;

// 	i = 0;
// 	if(argc == 3)
// 	{

// 		pid = ft_atoi(argv[1]);
// 		while (argv[2][i])
// 		{
// 			f_send_bits(pid, argv[2][i++]);
// 		}
// 	}
// 	return (0);
// }
