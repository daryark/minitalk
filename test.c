#include <stdio.h> 
#include <libc.h>
int main(int ac, char **av)
{
    // while (1)
        printf("pid: %d\n", (int)getpid());
    return (0);
}