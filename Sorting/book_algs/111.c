#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

int main(void)
{
    char friends[] = "Damir Karen Mama";
    char * token = strtok(friends, " ");
   // loop through the string to extract all other tokens
   while( token != NULL ) {
      printf( " %d\n", strlen(token)); //printing each token
      token = strtok(NULL, " ");
   }
   return 0;
}