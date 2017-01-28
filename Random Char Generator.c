#include <stdio.h>
#include <stdlib.h>

int main(){

 int i, n,t;
   time_t e;
   
   n = 5;
   char set [8]={'P','S','C','R','L','K','D','f'};
   /* Intializes random number generator */
   srand((unsigned) time(&e));

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < 40 ; i++ ) 
  
   {
   	 n=	rand() % 7;
   	 t=	rand() % 7;
   	 //printf("%d %d\n",n,t);
   	  
   	 printf("echo '%c %c'| ./a.out\n",set[n],set[t] );
     // printf("%c",set[n] );
       //printf(" %c\n",set[t] );

   }
   
   return(0);




}