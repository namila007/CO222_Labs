#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//define true or false to better understading
#define true 1
#define false 0

//define bool type
typedef int bool;

//check whether entered string is a valid integer
bool is_num(char* str){
	int length = strlen(str);
	int i;

	for(i = 0; i < length; i++){
		if(isdigit(str[i]) == 0)
			return false;
	}

	return true;
}

int main(int argc, char *argv[]){
	int i, n, t, count;
	time_t e;  
   	char set [8] = {'P','S','C','R','L','K','D','f'};
   	
	count = 10;

	if(argc > 1){
		if(is_num(argv[1])){
			count = atoi(argv[1]);		
		}else{
			printf("usage: %s [count=10]\n", argv[0]);
			exit(1);
		}
	}

	/* Intializes random number generator */
   	srand((unsigned) time(&e));

   	/* random number generate and assign to char*/
   	for( i = 0 ; i < count ; i++ ) {
     		n = rand() % 7;   //assigning random integer between 0-7
     		t = rand() % 7;
    		printf("%c %c\n", set[n], set[t]);   //printing
    	}
   
	return 0;
}
