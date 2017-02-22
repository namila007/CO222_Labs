/*
Project 1 - Display clock
Author Namila Bandara
 E/14/084
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW_SIZE 5
#define COL_SIZE 6
#define LEVEL_SIZE 11

void timedisplay();
void cursorjump();


void timedisplay(){
	
	int hour,min,sec,mont;
	time_t settime;
	struct tm* timevals;
	time(&settime);
	timevals=localtime(&settime);
	hour=timevals->tm_hour;
	min=timevals->tm_min;
	sec=timevals->tm_sec;
	
	printf("%02d:%02d:%02d\n",hour,min,sec);
	

}

void digitprint(int numprint){
	int i,j,k,printcount=1;;
	int Disp_array[11][5][6]={
		{{1,1,1,1,1,1},{1,1,0,0,1,1},{1,1,0,0,1,1},{1,1,0,0,1,1},{1,1,1,1,1,1}},
		{{0,0,0,0,1,1},{0,0,0,0,1,1},{0,0,0,0,1,1},{0,0,0,0,1,1},{0,0,0,0,1,1}},
		{{1,1,1,1,1,1},{0,0,0,0,1,1},{1,1,1,1,1,1},{1,1,0,0,0,0},{1,1,1,1,1,1}},
		{{1,1,1,1,1,1},{0,0,0,0,1,1},{1,1,1,1,1,1},{0,0,0,0,1,1},{1,1,1,1,1,1}},
		{{1,1,0,0,1,1},{1,1,0,0,1,1},{1,1,1,1,1,1},{0,0,0,0,1,1},{0,0,0,0,1,1}},
		{{1,1,1,1,1,1},{1,1,0,0,0,0},{1,1,1,1,1,1},{0,0,0,0,1,1},{1,1,1,1,1,1}},
		{{1,1,1,1,1,1},{1,1,0,0,0,0},{1,1,1,1,1,1},{1,1,0,0,1,1},{1,1,1,1,1,1}},
		{{1,1,1,1,1,1},{0,0,0,0,1,1},{0,0,0,0,1,1},{0,0,0,0,1,1},{0,0,0,0,1,1}},
		{{1,1,1,1,1,1},{1,1,0,0,1,1},{1,1,1,1,1,1},{1,1,0,0,1,1},{1,1,1,1,1,1}},
		{{1,1,1,1,1,1},{1,1,0,0,1,1},{1,1,1,1,1,1},{0,0,0,0,1,1},{1,1,1,1,1,1}},
		{{0,0,0,0,0,0},{0,0,1,1,0,0},{0,0,0,0,0,0},{0,0,1,1,0,0},{0,0,0,0,0,0}},
	};

	for(k=0;k<LEVEL_SIZE;k++){
			if(numprint==k){
				for (i = 0; i <ROW_SIZE; ++i)
				{
					for (j = 0; j <COL_SIZE; ++j)
					{
						if(Disp_array[k][i][j]==1){
							printf("*" );
						}else{
							printf(" ");
						}


					}
					printf("\n");
				}
			}
		}
		cursorjump();
		printcount++;
}

void cursorjump(int i){
	i=8*i;
printf("\033[6A\033[%dC",i);

}



int main(int argc, char const *argv[]){
	
	
	
	
 
	int i;

	for(i=0;i<LEVEL_SIZE;i++){
		digitprint(i);
	}



/*
	while(1){
		
		timedisplay();
		printf("\033[2J\033[1;1H");
	}
	*/
	
	return 0;
}