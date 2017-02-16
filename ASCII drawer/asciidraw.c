/*
Namila Bandara 
E/14/084
Ascii Draw
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET		0                //declaring constants
#define BRIGHT 		1

#define BLACK 		0
#define RED			1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7
#define argsize
#define argsize_max 8
#define box_max		8

char *ck="checker";                      //declaring variables
char *dn="donut";
char *coloursavailable[]={"black","red","green","yellow","blue","magenta","cyan","white"};
int x,y,xbox,ybox,xx,yy,foregroundcolour=-1,backgroundcolour=-1;
float outcir,incir,diam,outradi,inradi,r;


void textcolor(int attr, int fg, int bg);
void wrongcolours(int backgroundcolour, int foregroundcolour);
void colourchecker(char **argvalue);


void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */

	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in
	black in white background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}



void wrongcolours(int backgroundcolour, int foregroundcolour){
	if (backgroundcolour==-1 )
	{
		printf("Background color is not available\n");
		 	exit(0);
	}else if (foregroundcolour==-1)
	{
		printf("Foreground color is not available\n");
		 	exit(0);
	}
}


void colourchecker(char **argvalue){
	/* this is for checking the background and foreground colour inputs are valid or not
	*/
for (argsize = 0; argsize < argsize_max; argsize++)
	{
		 if(strcmp(argvalue[2],coloursavailable[argsize])==0){
		 	backgroundcolour=argsize;
		 }}
	for (argsize = 0; argsize < argsize_max; argsize++)
	{	 
		 if(strcmp(argvalue[3],coloursavailable[argsize])==0){
		 	foregroundcolour=argsize;
		 }
		 	
	}
	void wrongcolours(backgroundcolour,foregroundcolour);

}

void checkerprint(){


colourchecker(argvalue);
		
		for(y=0;y< box_max	;y++){
			for(ybox=0;ybox< box_max;ybox++){
				for(x=0;x<argsize_max;x++){
					
					for(xbox=0;xbox<box_max	;xbox++){
						if((x+y)%2==0){
							textcolor(BRIGHT,backgroundcolour,foregroundcolour);	//changing colours
							printf(" ");

						}else{
							textcolor(BRIGHT,foregroundcolour,backgroundcolour);	
							printf(" ");
							

						}
						textcolor(BRIGHT,foregroundcolour,backgroundcolour);

					}
				}
			printf("\n");
			}

				
		}

}



int main(int argc, char **argvalue){

if(argc<4){                            //checking argsize are less or more
	printf("Not enough arguments\n");
	exit(0);
}
if(argc>4){
	printf("Too many arguments\n");
	exit(0);
}
else{


	if(strcmp(argvalue[1],ck)==0){   //checker printing function
	
		checkerprint();

	}

	else if (strcmp(argvalue[1],dn)==0){          //funtion for donut printer
		
	colourchecker(argvalue);
		scanf("%f",&diam);

		r=diam/2;
		for (y=0; y<diam; y++){

		for (x =0; x <diam; x++){
			outradi=((x-r)*(x-r)+(y-r)*(y-r));
			
			if((outradi)<(r*r) && outradi>(r/2)*(r/2)){
				textcolor(BRIGHT,backgroundcolour,foregroundcolour);	          //printing big circle
				printf(" ");
				textcolor(BRIGHT,foregroundcolour,backgroundcolour);	
				
			 

			}
			
			else if((outradi)<=((r/2)*(r/2))){         //removing small circle from big one
				textcolor(BRIGHT,foregroundcolour,backgroundcolour);	
				printf(" ");
                                        
			}
			else{
				
				textcolor(BRIGHT,foregroundcolour,backgroundcolour);	   //printing outer
				printf(" ");
				
				
			}
                   			
			
		}	
		printf("\n");
			
		}


			
		
	}
	else{
		printf("Requested figure is not available\n" );  //if figures are not available
		exit(0);

	}



		textcolor(RESET, WHITE, BLACK);	
}
	return 0;
	
	
}
