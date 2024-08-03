#include <stdio.h>
#include <stdlib.h>
#include "includes/cli.h"

char* getSourceFile(unsigned short count, char* cmd[]);

int main(unsigned short argc, char* argv[]) {
    char* data = getSourceFile(argc, argv);

    printf("%s", data);

    return 0;
}

char* getSourceFile(unsigned short count, char* cmd[]) {
    char* src = NULL;

    for(unsigned short i = 0; i < count; i++) 
        if(strcmp("-s", cmd[i]) == 0) src = cmd[i + 1];
    

    if(src == NULL) exit(1);

    

    return src;
}