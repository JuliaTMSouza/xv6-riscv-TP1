#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(2, "usage: settickets int...\n");
        exit(1);
    }

    int ticketNumber = atoi(argv[1]);
    int success = settickets(ticketNumber);

    if (success != 0) {
        printf("Não foi possível alocar este número de tickets\n");
        exit(1);
    }

    exit(0);
}