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
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7
//dd
char *ck="checker";                      //declaring variables
char *dn="donut";
char *colourval[]={"black","red","green","yellow","blue","magenta","cyan","white"};
int x,y,xbox,ybox,xx,yy,args,fgg=-1,bgg=-1;
float outcir,incir,diam,outradi,inradi,r;


void textcolor(int attr, int fg, int bg);

void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */

	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in
	black in white background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}


void colourchecker(char **argv1){
	/* this is for checking the background and foreground colour inputs are valid or not
	*/
for (args = 0; args < 8; args++)
	{
		 if(strcmp(argv1[2],colourval[args])==0){
		 	bgg=args;
		 }}
	for (args = 0; args < 8; args++)
	{	 
		 if(strcmp(argv1[3],colourval[args])==0){
		 	fgg=args;
		 }
		 	
	}
	if (bgg==-1 )
	{
	printf("Background color is not available\n");
		 	exit(0);
	}else if (fgg==-1)
	{
		printf("Foreground color is not available\n");
		 	exit(0);
	}

}



int main(int argc, char **argv){

if(argc<4){                            //checking args are less or more
	printf("Not enough arguments\n");
	exit(0);
}
if(argc>4){
	printf("Too many arguments\n");
	exit(0);
}
else{


	if(strcmp(argv[1],ck)==0){   //checker printing function
	
		colourchecker(argv);
		
		for(y=0;y<8;y++){
			for(ybox=0;ybox<8;ybox++){
				for(x=0;x<8;x++){
					
					for(xbox=0;xbox<8;xbox++){
						if((x+y)%2==0){
							textcolor(BRIGHT,bgg,fgg);	//changing colours
							printf(" ");

						}else{
							textcolor(BRIGHT,fgg,bgg);	
							printf(" ");
							

						}
						textcolor(BRIGHT,fgg,bgg);

					}
				}
			printf("\n");
			}

				
		}

	}

	else if (strcmp(argv[1],dn)==0){          //funtion for donut printer
		
	colourchecker(argv);
		scanf("%f",&diam);

		r=diam/2;
		for (y=0; y<diam; y++){

		for (x =0; x <diam; x++){
			outradi=((x-r)*(x-r)+(y-r)*(y-r));
			
			if((outradi)<(r*r) && outradi>(r/2)*(r/2)){
				textcolor(BRIGHT,bgg,fgg);	          //printing big circle
				printf(" ");
				textcolor(BRIGHT,fgg,bgg);	
				
			 

			}
			
			else if((outradi)<=((r/2)*(r/2))){         //removing small circle from big one
				textcolor(BRIGHT,fgg,bgg);	
				printf(" ");
                                        
			}
			else{
				
				textcolor(BRIGHT,fgg,bgg);	   //printing outer
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
