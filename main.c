#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "printMap.h"
#include "checkEOF.h"
#include "freeMem.h"

#define MIN_SIZE_MAP 2
#define MAX_SIZE_MAP 32
#define MAX_CODE_NUMBER 4

/*Entry point and main function of the app*/
int main(void) {
    /*Setting*/
    bool isCheatModeOn = false;

    /*User Status*/
    bool isAllTreasureFound = false;
    int numberOfTreasuresFound =0;

    /*Map Setup*/
    int mapWidth, mapHeight;
    char ***map;
    bool isValidWidth = false;
    bool isValidHeight = false;
    bool isValidNumberOfTreasures = false;

    /*Treasure*/
    int randomXAxis, randomYAxis, numTreasures;
    char **treasures;
    bool isValidCode = false;
    bool isUniqueLocation = false;
    bool isUnique = true;

    /*User Input*/
    int choice, digCoordX, digCoordY;

    /*Loop Variables for looping*/
    int i, j;

    /*Intro*/
    while (!isValidHeight) {
        printf("Enter Map Height\n");

        /*check for EOF*/
            if (checkEOFint(&mapHeight)) {
                return 0;
            }

            /*checks if the number is valid*/
            if(mapHeight< MIN_SIZE_MAP || mapHeight > MAX_SIZE_MAP) {
            printf("Invalid Map Height. Input 2 - 32 only!\n");

            /*clears input buffer*/
            while (getchar() != '\n');
            isValidHeight = false;
            } else {
            isValidHeight = true;
            }
    }

    while(!isValidWidth) {

            printf("Enter Map Width\n");

            /*check for EOF*/
            if(checkEOFint(&mapWidth)) {
                return 0;
            }

            /*checks if the number is valid*/
            if(mapWidth < MIN_SIZE_MAP || mapWidth > MAX_SIZE_MAP ) {
                printf("Invalid Map Width. Input 2 - 32 only!\n");

                /*clears input buffer*/
                while (getchar() != '\n');
                isValidWidth = false;
            } else {
                isValidWidth = true;
            }
        }


    while(!isValidNumberOfTreasures) {
        printf("Enter number of treasures to add: \n");

        /*check for EOF*/
            if(checkEOFint(&numTreasures)) {
                return 0;
            }

            /*checks if the number is valid*/
            if(numTreasures > mapWidth || numTreasures > mapHeight || numTreasures < 0) {
                printf("Invalid number of treasures!\n");

                /* clears he input buffer */
                while (getchar() != '\n');
                isValidNumberOfTreasures = false;
            } else {
                isValidNumberOfTreasures = true;
            }
        }

    /*Initializing Memory for treasure*/
    treasures = (char **) malloc(numTreasures * sizeof(char *));

    /*edge case if memory allocation will be error*/
    if(treasures == NULL) {
        printf("Memory allocation error!\n");
    }

    /*Handling memory allocation error*/
    for (i = 0; i < numTreasures; i++) {
        treasures[i] = (char *) malloc(MAX_CODE_NUMBER * sizeof(char));

        /*edge case if memory allocation will be error*/
        if(treasures[i] == NULL) {
        printf("Memory allocation error!\n");
        }
    }

    /*Initializing Map (2d array of int)*/
    map = (char ***)malloc(mapHeight * sizeof(char **));

    /*edge case if memory allocation will be error*/
    if(map == NULL) {
        printf("Memory allocation error!\n");
    }
    for (i = 0; i < mapHeight; i++) {
        map[i] = (char **)malloc(mapWidth * sizeof(char *));

        /*edge case if memory allocation will be error*/
        if(map[i] == NULL) {
            printf("Memory allocation error!\n");
        }

        /*Creating an empty spot for the treasures*/
        for(j = 0; j < mapWidth; j++) {
            map[i][j] = NULL;
        }
    }



    /*Setting random location  for treasures*/

        /*Iterate through numbers of treasure */
        for(i = 0; i < numTreasures; i++) {

        isUniqueLocation = false; /*reset the flag every iteration*/
        isValidCode = false;    /*reset the flag every iteration*/

        /* while the memory address is not taken, set this address to be the storage for our new treasure*/
        while(!isUniqueLocation) {
            randomXAxis = (rand() % mapWidth);
            randomYAxis = (rand() % mapHeight);

            /*Checking if location is empty*/
            if(map[randomYAxis][randomXAxis] == NULL) {
                isUniqueLocation = true;
            }
        }

        /*Validate and check uniqueness*/
        while(!isValidCode) {

        printf("Enter Treasure #%d code (e.g. T001): ",i + 1);

        /*input and check EOF*/
        if(checkEOFstr(treasures[i])) {
            freeMem(map,mapHeight,treasures,numTreasures);
            return 0;
        }

        /*Check for correct format*/
        if(treasures[i][0] == 'T' && strlen(treasures[i]) == MAX_CODE_NUMBER &&
            treasures[i][1] >= '0' && treasures[i][1] <= '9' &&
            treasures[i][2] >= '0' && treasures[i][2] <= '9' &&
            treasures[i][3] >= '0' && treasures[i][3] <= '9') {

            /*Check if code is unique. Checks all the treasure being store and compare it to this
             *new treasure to be stored. It uses strcmp for comparing similiarity of the string*/
            isUnique = true;
            for (j = 0; j < i; j++) {
                if (strcmp(treasures[i], treasures[j]) == 0) {
                    printf("Treasure code already in use.\n");
                    isUnique = false;
                    break;
                }
            }

            /* If the code is unique, set the treasure in the location */
            if(isUnique) {
                isValidCode = true;
                map[randomYAxis][randomXAxis] = treasures[i];
            }

        }else {
            printf("Invalid code format. Treasure codes must be 'T' followed by 3 digits (e.g., T001).\n");
              }
        }
    }



    printMap(map,mapWidth,mapHeight,isCheatModeOn);

    while(!isAllTreasureFound) {

        /*Menu*/
        printf("Enter Choice: \n");
        printf("1 - Dig at spot\t| 2 - Exit Game\t| 3 - Cheat!\n");

        if(checkEOFint(&choice)) {
            freeMem(map,mapHeight,treasures,numTreasures);
            return 0;
        }

        switch (choice) {
            case 1:
                /*Sub Menu*/
                 printf("Where would you like to dig?\n");

                 /*Geting input for x*/
                 printf("X = ");
                 if(checkEOFint(&digCoordX)) {
                     freeMem(map,mapHeight,treasures,numTreasures);
                     return 0;
                 }
                 /*Getting input for y*/
                 printf("Y = ");
                 if(checkEOFint(&digCoordY)) {

                     freeMem(map,mapHeight,treasures,numTreasures);
                     return 0;
                 }

            /*Perform checking for each treasure if its equal to the digging coordinates*/
                for(i = 0; i < numTreasures; i++) {
                if(map[digCoordY][digCoordX] == treasures[i]) {
                    printf("Treasure #%d found! Code: %s\n", i+1,treasures[i]);
                    numberOfTreasuresFound++;
                    map[digCoordY][digCoordX] = "$";
                    break;
                }else if(map[digCoordY][digCoordX] == NULL){
                    printf("You found nothing!\n");
                    map[digCoordY][digCoordX] = "#";
                    break;
                }else if(map[digCoordY][digCoordX] == (char *)"$") {
                    printf("You already found the treasure there!\n");
                    break;
                }
            }
                break;

            case 2:
                printf("Thank you for playing");
                freeMem(map,mapHeight,treasures,numTreasures);
                return EXIT_SUCCESS;

            case 3:
                isCheatModeOn = true;
                printf("Cheat Mode Enabled\n");
                break;
            default:
                printf("Wrong choice\n");
        }
        /*All treasures found!*/
        if(numberOfTreasuresFound == numTreasures) {
            isAllTreasureFound = true;
            printf("Congratulations, you found all the treasure!\n");
        }

        /*Show map here*/
        printMap(map,mapWidth,mapHeight,isCheatModeOn);
    }

    /*Free*/
    freeMem(map,mapHeight,treasures,numTreasures);

return EXIT_SUCCESS;
}




