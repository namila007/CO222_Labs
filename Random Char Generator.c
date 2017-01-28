#include <stdio.h>
#include <stdlib.h>

int main(){

 int i, n,t;
   time_t e;
   char set [8]={'P','S','C','R','L','K','D','f'};
   /* Intializes random number generator */
   srand((unsigned) time(&e));

   /* random number generate and assign to char*/
   for( i = 0 ; i < 40 ; i++ ) 
  
   {
     n= rand() % 7;
     t= rand() % 7;
  
      
     printf("%c %c\n",set[n],set[t] );
    

   }
   
   return(0);




}