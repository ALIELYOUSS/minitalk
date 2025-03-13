#include "minitalk.h"

int main(int ac, char **av)
{
    int pid;
    int i;
    int x;
    char octet;

    if (ac != 3)
        return (0);
    pid = atoi(av[1]);
    printf("PID succfully received: %d\n", pid);
    if (av[2])
    {
        i = 0;
        while (av[2][i])
        {
            x = 128;
            octet = av[2][i];
            while (x > 0)
            {
               if (octet >=x)
               {
                    kill(pid, SIGUSR1);
                    perror(":");
                    usleep(5000);
                    printf("1");
                    octet %= x;
                    x /= 2;
                }
                else
                {
                    kill(pid, SIGUSR2);
                    perror(":");
                    usleep(5000);
                    printf("0");
                    x/=2;
                }
            }
            kill(pid, SIGINT);
            usleep(5000);
            i++;
        }
     }
    
}