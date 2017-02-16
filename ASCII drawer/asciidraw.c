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

char *checkerchar="checker";                      //declaring variables
char *donutchar="donut";
char *coloursavailable[]={"black","red","green","yellow","blue","magenta","cyan","white"};
int xaxis,yaxis,xaxisboxline,yaxisboxline,foregroundcolour=-1,backgroundcolour=-1;
float diameter,outerradius,inradi,radius;


void textcolor(int attr, int fg, int bg);
void wrongcolours(int backgroundcolour, int foregroundcolour);
void colourchecker(char **argvalue);
int outercircleradius(int xaxis,,int yaxis,int radius);
float diametertoradius(float diameter);
void donutprint(int radius);


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


	
		
		for(yaxis=0;yaxis< box_max	;y++){
			for(yaxisboxline=0;yaxisboxline< box_max;yaxisboxline++){
				for(xaxis=0;xaxis<argsize_max;x++){
					
					for(xaxisboxline=0;xaxisboxline<box_max	;xaxisboxline++){
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


float outercircleradius(int xaxis,,int yaxis,float radius){

	 outerradius=((xaxis-radius)*(xaxis-radius)+(yaxis-radius)*(yaxis-radius));	
	return outerradius;

}

float diametertoradius(float diameter){
	return (diameter/2);
}

void donutprint(int radius){
	for (yaxis=0; yaxis<diameter; yaxis++){

		for (xaxis =0; xaxis <diameter; xaxis++){
			
			outerradius=outercircleradius(xaxis,yaxis,radius);
			
			if((outerradius)<(radius*radius) && outerradius>(radius/2)*(radius/2)){
				textcolor(BRIGHT,backgroundcolour,foregroundcolour);	          //printing big circle
				printf(" ");
				textcolor(BRIGHT,foregroundcolour,backgroundcolour);	
				
			 

			}
			
			else if((outerradius)<=((radius/2)*(radius/2))){         //removing small circle from big one
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


	if(strcmp(argvalue[1],checkerchar)==0){   //checker printing function
		colourchecker(argvalue);
		checkerprint();

	}

	else if (strcmp(argvalue[1],donutchar)==0){          //funtion for donut printer
		
		colourchecker(argvalue);
		scanf("%f",&diameter);

		radius=diametertoradius(diameter);
		donutprint(radius);


			
		
	}
	else{
		printf("Requested figure is not available\n" );  //if figures are not available
		exit(0);

	}



		textcolor(RESET, WHITE, BLACK);	
}
	return 0;
	
	
}
