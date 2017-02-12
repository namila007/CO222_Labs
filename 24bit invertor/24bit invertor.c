/*
Inverter 
Namila Bandara 
E/14/084
*/
#include <stdio.h>
//declaring variables
int u_row,u_col,u_r,u_g,u_b,col,row,pad2,pad,ipad;

int main(){
	//scaning and pringting columns,rows
scanf("%d %d",&u_col,&u_row);
printf("%d %d\n",u_col,u_row);

//getting padding values
pad=(4-(3*u_col)%4)%4;


for(row=0;row<u_row;row++){
	
	for (col=0;col<u_col;col++){	
			//scaning each rgb value and printing reducing 255 value
			scanf("%d %d %d",&u_r,&u_g,&u_b);
			printf("%d %d %d\n",255-u_r,255-u_g,255-u_b);
			}
			
			//scaning padded 0s and writing them again
		for (ipad=0;ipad<pad;ipad++){
			scanf("%d", &pad2);
			printf("0\n");
		}	
	
	}

return 0;
}
