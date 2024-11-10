#include <stdio.h>
#include "checkEOF.h"

#define TRUE 1
#define FALSE 0

/*Passing in the memory location*/
int checkEOFint(int *address) {

    if (scanf("%d", address) == EOF) {
        printf("EOF Detected\n");
        return TRUE;
    }
    return FALSE;
}

int checkEOFstr(char *address) {

  if (scanf("%s", address) == EOF) {
    printf("EOF Detected\n");
    return TRUE;
    }

    return FALSE;
}
