#include <stdio.h>
#include <stdlib.h>

#define MAX_CODE_NUMBER 4
int main(void) {

    /*Map*/
    int mapWidth;
    int mapHeight;
    int **map;

    /*Treasure*/
    int randomXAxis;
    int randomYAxis;


    int numTreasures;
    char **treasures;


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

    /*Initializing Memory for treasure*/
    treasures = (char **) malloc(numTreasures * sizeof(char *));
    for (i = 0; i < numTreasures; i++) {
        treasures[i] = (char *) malloc(MAX_CODE_NUMBER * sizeof(char));
    }

    /*Initializing Map*/
    map = (int **)malloc(mapHeight * sizeof(int *));
    for (i = 0; i < mapHeight; i++) {
        map[i] = (int *)malloc(mapWidth * sizeof(int));
    }

    /*Setting codes*/
    /*Random Loc for Treasures*/
    for(i = 0; i < numTreasures; i++) {
        randomXAxis = (rand() % mapWidth);
        randomYAxis = (rand() % mapHeight);

        printf("Enter treasure #%d code: ", i+1);
        scanf("%s", treasures[i]);

        map[randomXAxis][randomYAxis] = 2;

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
        printf("%d|",y%10);
        for (x=0; x < mapWidth; x++) {
            printf("%d",map[x][y]);
        }
        printf("\n");

    }


    /*Menu*/


    /*Free*/
    /*Freeing Map*/
    for(i = 0; i < mapWidth; i++) {
        free(map[i]);
    }
    for(i = 0; i<numTreasures; i++) {
        free(treasures[i]);
    }
    free(map);
    /*Freeing Treasure*/
    free(treasures);



return EXIT_SUCCESS;
}

