#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int count;

    if (argc != 2)
    {
        fprintf(2, "usage: getcnt pid...\n");
        exit(1);
    }

    count = getcnt(atoi(argv[1]));
    fprintf(2, "syscall %d has been called %d times\n", atoi(argv[1]), count);

    exit(0);
}