/*
Namila Bandara
E/14/084
Word Wrapper

*/

#include <stdio.h>
#include <string.h>


int main(){
	FILE *fp;
	char str[4000];
	char *strs;
	int str_len=0,temp_len;

	fp=fopen("paragraph.txt" ,"r");

	while(fscanf(fp,"%s",str)!=EOF){
		temp_len=strlen(str);
		if(str_len<temp_len){
			str_len=temp_len;
		}

	}
	fclose(fp);

//printf("%d\n",str_len );

fp=fopen("paragraph.txt" ,"r");

int prt_len=20,count=0;
char c;

while(fscanf(fp,"%s%c",str,&c)!=EOF){
	str_len= strlen(str);
	
	if(count+str_len<=prt_len){
		printf("%s",str );

		count+=str_len;
		if(c=='\n'){
			
			count=0;
			printf("\n");
		}
		else if(c==' '){
			printf("%c",c);
			count+=1;
		}

		
	}
	else if(count+str_len>prt_len) {
		printf("\n");
		count=0;
		printf("%s",str );

		count+=str_len;
		if(c=='\n'){
			
			count=0;
			printf("\n");
		}
		else if(c==' '){
			printf("%c",c);
			count+=1;
		}

	
			
		}
		
	}
	
	







	return 0;
}
