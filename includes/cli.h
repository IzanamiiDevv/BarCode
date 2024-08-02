/*IzanamiiDevv*/

#ifndef CLI_H
#define CLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan integer argument from the command line
int scan_int(const char* args, int argc, char* argv[]) {
    int data = 0;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], args) == 0 && i + 1 < argc) {
            data = atoi(argv[i + 1]);
        }
    }
    return data;
}

// Function to scan string argument from the command line
char* scan_string(const char* args, int argc, char* argv[]) {
    char* data = NULL;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], args) == 0 && i + 1 < argc) {
            data = argv[i + 1];
        }
    }
    return data;
}

#endif // CLI_H