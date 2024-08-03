#include <stdio.h>
#include <stdlib.h>
#include "includes/cli.h"

#define CREDIT "IzanamiiDev"

typedef struct {
    void* list;
    unsigned int len;
} Array;

Array array_init() {
    Array buff;
    buff.len = 0;
    buff.list = NULL;
    return buff;
}


void array_flush(Array* arr) {
    free(arr->list);
    arr->len = 0;
}

#define array_pushBack(type ,arr, value) { \
    void* new_list; \
    (arr).len += 1; \
    new_list = realloc((arr).list, sizeof(type) * (arr).len); \
    if (new_list == NULL) printf("Error: Memorry Allocation Failed."); \
    (arr).list = new_list; \
    ((type*)(arr).list)[(arr).len - 1] = value; \
};

#define array_popBack(type, arr) { \
    void* new_list; \
    (arr).len -= 1; \
    new_list = realloc((arr).list, sizeof(type) * (arr).len); \
    if(new_list == NULL) printf("Error: Memorry Allocation Failed."); \
    (arr).list = new_list; \
}

#define array_print(format, type, arr) { \
    printf("["); \
    for(int i = 0; i < (arr).len; i++) { \
        printf(format, ((type*)(arr).list)[i]); \
        if(i == (arr).len - 1) break; \
        printf(", "); \
    } \
    printf("] \n"); \
}

#define array_take(type, arr, index) ((( type* )(arr).list)[(index)])


#define array_forEach(type, arr, callback) { \
    void(*arrforeach)(type) = callback; \
    for(int i = 0; i < (arr).len; i++) { \
        arrforeach((( type* )(arr).list)[i]); \
    } \
}

#define array_map(type, arr, callback) { \
    type (*arrmap)(type) = callback; \
    for(int i = 0; i < (arr).len; i++) { \
        (( type* )(arr).list)[i] = arrmap((( type* )(arr).list)[i]); \
    } \
}

#define array_mod(type, arr, index, value) (( type* )(arr).list)[index] = value;

#define array_shuffle(type, arr) { \
    srand(time(0)); \
    const unsigned int MAX = (arr).len - 1; \
    const unsigned short MIN = 0; \
    for(int i = 0; i < (arr).len; i++) {\
        type temp = (( type* )(arr).list)[i]; \
        int randn = (rand() % (MAX - MIN + 1)) + MIN; \
        (( type* )(arr).list)[i] = (( type* )(arr).list)[randn];\
        (( type* )(arr).list)[randn] = temp; \
    } \
}


/*======================================================*/
char* getbuffer(unsigned short count, char* cmd[]);
void cleanSourceBuffer(char* line);

int main(unsigned short argc, char* argv[]) {
    char* data = getbuffer(argc, argv);

    return 0;
}

void cleanSourceBuffer(char* line) {
    free(line);
}

char* getbuffer(unsigned short count, char* cmd[]) {
    char* src = NULL;

    for(unsigned short i = 0; i < count; i++) 
        if(strcmp("-s", cmd[i]) == 0) src = cmd[i + 1];
    
    if(src == NULL) exit(1);

    FILE *fptr;
    Array source = array_init();

    fptr = fopen(src, "r");

    if(fptr == NULL) {
        fclose(fptr);
        exit(1);
    };

    char buffer[100];
    while(fgets(buffer, 100, fptr)) {

        char* line = malloc(sizeof(char*) * strlen(buffer));
        strcpy(line, buffer);

        for(unsigned int i = 0; i < strlen(line); i++)
            if(line[i] == '\n') line[i] = '\0';
    
        array_pushBack(char*, source, line);
    }

    fclose(fptr);

    array_print("%s", char*, source);
    
    array_forEach(char*, source, cleanSourceBuffer);
    array_flush(&source);

    

    return " ";
}