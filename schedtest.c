/*
Prints its PID, then forks one child per argument. Each
child calls settickets() with its number (prints an error
and exits if it returns -1), prints its PID and tickets, and
spins forever. The parent exits. Like childrentester, a
child must never return to the fork loop.
*/

#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

/*
  int i;

  for(i = 1; i < argc; i++)
    printf(1, "%s%s", argv[i], i+1 < argc ? " " : "\n");
  exit();
*/


int main(int argc, char *argv[])
{
    int i;
    int rc;

    printf(1, "Parent PID: %d\n", getpid());
    for (i = 1; i < argc; i++) {
        rc = fork();
        if (!rc) {
            // Child process
            printf(1,
                "Child %d PID: %d\n",
                i,
                getpid()
            );
            if(settickets(atoi(argv[i])) == -1){
                printf(1, "Child %d died after calling settickets(%s).\n", i, argv[i]);
                return -1;
            }
            for(;;){}
        }
    }
    exit();
}