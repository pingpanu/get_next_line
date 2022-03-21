/*This file is only to test GNL function
DO NOT PUSH it on 42 git*/
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
/*declare struct for easier var dec in main*/
struct  checkGNL {
    char    *line;
    int     fd;
}

int main(void)
{
    struct  checkGNL check1, check2; //you can add additional checks
    
    check1.fd = open("test1.txt", O_RDONLY); //refer to your txt files
    printf("%d\n", check1.fd);
    check1.line = get_next_line(check1.fd);
    printf("%s\n",check1.line);
    check2.fd = open("empty.txt", O_RDONLY); //refer to your txt files
    printf("%d\n", check2.fd);
    check2.line = get_next_line(check2.fd);
    printf("%s\n",check2.line);
    return (0);
}