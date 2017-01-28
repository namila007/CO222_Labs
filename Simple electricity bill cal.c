/*
Lab 01
Programming Methodology
Author :Namila Bandara
        E/14/084

*/

#include <stdio.h>


float Uinput, Ucharged,Fcharge,Total;  
int main(){

scanf("%f", &Uinput); //getting units used in 30 days

if(Uinput<0){
	printf("-1\n");         //checking whether input is valid or not 
	return 1;
	
}
else{
	if(Uinput<=60){                              //calculating for units under or equal 60
		if(Uinput>=30){
			Fcharge=60;
			Ucharged=(Uinput-30)*4.85+30*2.5;
			
		}
		else{
			Fcharge=30;
			Ucharged=(Uinput)*2.5;
			
		}
		Total=Ucharged+Fcharge;
			printf("%.2f\n",Total);
	}
	else{                                                   //calculating for units above 60
		if(Uinput<=90){
			Fcharge=90;
			Ucharged=(Uinput-60)*10+60*7.85;
			
		}
		else if(Uinput<=120){                                //calculating for units below 120
			Fcharge=480;                                    
			Ucharged=(Uinput-90)*27.75+30*10+60*7.85;
			
		}
		else if(Uinput<=180){                                  //calculating for units below 180
			Fcharge=480;
			Ucharged=(Uinput-120)*32+30*10+30*27.75+60*7.85;
			
		}
		else{													//calculating for units above 180
			Fcharge=540;
			Ucharged=(((Uinput-180)*45)+32*60+30*10+27.75*30+60*7.85);
			
		}
	Total=Fcharge+Ucharged;
	printf("%.2f\n",Total);
}
	
}
return 0;
}