#include <stdio.h>
#include <stdbool.h>
#include "checkEOF.h"

/*Passing in the memory location*/
bool checkEOFint(int *address) {

    if (scanf("%d", address) == EOF) {
        printf("EOF Detected\n");
        return true;
    }
    return false;
}

bool checkEOFstr(char *address) {

  if (scanf("%s", address) == EOF) {
    printf("EOF Detected\n");
    return true;
    }

    return false;
}
