#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*This function is to print the map*/
void printMap(char ***map, int mapWidth, int mapHeight, int isCheatModeOn) {

    /*Loop Variables*/
    int x,y;


    /*Printing Map*/
    printf("Map: \n");

    /*Printing X Grid indicator*/
    printf("   ");
    for(x = 0; x < mapWidth; x++) {
        printf("%d",x / 10);
    }
    printf("\n");
    printf("   ");
    for(x = 0; x < mapWidth; x++) {
        printf("%d",x % 10);
    }

    printf("\n");
    printf("   ");
    for(x = 0; x < mapWidth; x++) {
        printf("-");
    }

    /*Printing Y Grid Indicator*/
    printf("\n");
    for(y=0; y < mapHeight; y++) {
        printf("%d",y/10);
        printf("%d|",y%10);
        /*Printing map*/
        for (x=0; x < mapWidth; x++) {
            if(map[y][x] == NULL) {
                printf(" ");
            }else if(map[y][x] == (char *)"#") {
                printf("#");
            }else if(map[y][x] == (char *)"$") {
                printf("$");
            }else if(isCheatModeOn && map[y][x] != NULL) {
                printf("!");
            }else {
                printf(" ");
            }
        }
        printf("\n");

    }

}