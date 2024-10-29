#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Map*/
int mapWidth;
int mapHeight;
char ***map;

/*Treasure*/
int randomXAxis;
int randomYAxis;
int numTreasures;
char **treasures;

/*User Input*/
int choice;
int digCoordX;
int digCoordY;

/*Situation*/
bool isTreasureFound;

/*Setting*/
int cheatModeToggle;


/*Loop Variables for looping*/
int i;
int j;
int x;
int y;

#define MAX_CODE_NUMBER 4
int main(void) {



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

    /*Initializing Map (2d array of int*/
    map = (char ***)malloc(mapHeight * sizeof(char **));
    for (i = 0; i < mapHeight; i++) {
        map[i] = (char **)malloc(mapWidth * sizeof(char *));
        for(j = 0; j < mapWidth; j++) {
            map[i][j] = NULL;
        }
    }



    /*Setting codes*/
    /*Random Loc for Treasures*/
    for(i = 0; i < numTreasures; i++) {
        randomXAxis = (rand() % mapWidth);
        randomYAxis = (rand() % mapHeight);

        printf("Enter treasure #%d code: ", i+1);
        scanf("%s", treasures[i]);

        map[randomXAxis][randomYAxis] = treasures[i];

    }





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
            if(map[y][x] != NULL) {
                printf("x");
            }else {
                printf(".");
            }

        }
        printf("\n");

    }



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

