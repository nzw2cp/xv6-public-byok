#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int pid, a, b, c;
    pid = getpid();
    a   = firstPart();
    b   = secondPart();
    c   = thirdPart();
    
    printf(1,"Pid: %d\n",pid);
    printf(1,"# Pid Calls: %d\n",a);
    printf(1,"# Sys Calls: %d\n",b);
    printf(1,"# Sys Calls != -1: %d\n",c);
    
    exit();
}
