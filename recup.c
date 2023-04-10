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

Cliet
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

