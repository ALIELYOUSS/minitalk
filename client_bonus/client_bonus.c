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
            if (octet >= x)
            {
                kill(pid, SIGUSR1);
                octet %= x;
                x /= 2;
            }
            else
            {
                kill(pid, SIGUSR2);
                x/=2;
            }
            usleep(500);
        }
        i++;
    }
}

void    listen(int signum)
{
    if (signum == SIGTERM)
        ft_putstr_fd("🥳 🥳 msg succfully sent to: ", 1);
}

int main(int ac, char **av)
{
    int pid;

    if (ac != 3 || !ft_atoi(av[1]))
        return (0);
    pid = ft_atoi(av[1]);
    if (pid == -1)
        return (ft_putstr_fd("Error has occured\n", 1), exit(0), 0);
    if (av[2])
    {
        msg_converter(av[2], pid);
        signal(SIGUSR1, listen);
        ft_putnbr_fd(pid, 1);
    }
    return (0);
}