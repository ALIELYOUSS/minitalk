#include "../minitalk.h"

static void msg_converter(char *msg, int pid)
{
    char octet;
    int i;
    int x;

    i = 0;
    octet = 0;
    while (msg[i])
    {
        x = 128;
        octet = msg[i];
        while (x > 0)
        {
            if (octet >=x)
            {
                kill(pid, SIGUSR1);
                usleep(3000);
                octet %= x;
                x /= 2;
            }
            else
            {
                kill(pid, SIGUSR2);
                usleep(3000);
                x/=2;
            }
        }
        i++;
    }
}

int main(int ac, char **av)
{
    int pid;

    if (ac != 3)
        return (0);
    pid = ft_atoi(av[1]);
    ft_putstr_fd("PID succfully received: ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    if (av[2])
        msg_converter(av[2], pid);
}