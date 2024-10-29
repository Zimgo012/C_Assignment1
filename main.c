#include <stdio.h>
#include <stdlib.h>

#define EMPTY_SPACE 3
int main(void) {

    /*Map*/
    int mapWidth;
    int mapHeight;
    int **map;

    /*Treasure*/
    int randomXAxis;
    int randomYAxis;
    int numTreasures;
    // char **treasure;
    // int **map;

    /*Digging*/
    int digCoordX;
    int digCoordY;

    /*Setting*/
    int choice;
    int cheatModeToggle;

    /*Loop Variables for looping*/
    int i;
    int j;
    int x;
    int y;

    /*Intro*/
    printf("Enter Map Width\n");
    scanf("%d", &mapWidth);
    printf("Enter Map Height\n");
    scanf("%d", &mapHeight);
    /**/
    printf("Enter Number of Treasures\n");
    scanf("%d", &numTreasures);

    /*Map*/
    /*Initializing Map*/
    map = (int **)malloc(EMPTY_SPACE + mapHeight * sizeof(int *));
    for (i = 0; i < mapHeight; i++) {
        map[i] = (int *)malloc(EMPTY_SPACE + mapWidth * sizeof(int));
    }


    /*Printing Map*/
    printf("Map: \n");

    /*Printing X indicator*/
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

    /*Printing Y Indicator*/
    printf("\n");
    for(y=0; y < mapHeight; y++) {
        printf("%d",y/10);
        printf("%d|\n",y%10);

    }


    /*Freeing*/
    // free(treasure);
    for(i = 0; i < mapWidth; i++) {
        free(map[i]);
    }
     free(map);

}

