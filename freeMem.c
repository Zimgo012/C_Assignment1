#include <stdio.h>
#include <stdlib.h>
#include "freeMem.h"

/*This function will clear out the memory address*/
void freeMem(char ***map,int mapNumCol, char **treasure, int maxTreasure){
  int i,j;

  /*clearing out the memory address allocated for the row(x-axis) of the map*/
  for(i=0;i<mapNumCol;i++){
    /*edge case*/
    if(map[i]!=NULL){
    free(map[i]);
    }
    }

    /*clearing out the memory address allocated for the characters  of the treasures*/
    for(j=0;j<maxTreasure;j++){
    /*edge case*/
    if(treasure[j]!=NULL){
      free(treasure[j]);
    }
    }

    /*freeing the memory address allocated for the column(y-axis) of the map*/
    if(map!=NULL){
    free(map);
    }

    /*freeing the memory address allocated for the treasures */
    if(treasure!=NULL){
      free(treasure);
    }


  }
