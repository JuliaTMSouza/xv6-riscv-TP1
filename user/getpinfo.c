#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pstat.h"

int main(int argc, struct pstat *argv[])
{

    if (argc != 1)
    {
        fprintf(2, "usage: getpinfo...\n");
        exit(1);
    }

    struct pstat *p = malloc(sizeof(p));

    int response = getpinfo(p);
    printf("logo dps de entrar\n");

    if (response == 0)
    {
        for (int i = 0; i < NPROC; i++)
        {
            if (p->inuse[i])
            {
                printf("PID: %d, Tickets: %d, Ticks: %d\n", p->pid[i], p->tickets[i], p->ticks[i]);
            }
        }
    }
    else
    {
        printf("Não foi possível obter as informações\n");
    }
    free(p);
    exit(0);
}