/*
Namila Bandara
E/14/084
Word Wrapper

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 4000
#define READ "r"


int word_count(FILE *fp, char* filepath);
void word_wrap(FILE *fp , char* filepath, int prt_len);


int word_count(FILE *fp, char* filepath){
/*
here this count the maximum word count in a string and
 return the largest wordcount available

*/
	char str[SIZE];
	
	int str_len=0,temp_len;
	fp=fopen(filepath ,READ);

	while(fscanf(fp,"%s",str)!=EOF){
			temp_len=strlen(str);
			if(str_len<temp_len){
				str_len=temp_len;
			}

		}
	fclose(fp);
	return str_len;

}

void word_wrap(FILE *fp , char* filepath, int prt_len){
/*
printing word by word according to user wrap size

*/
	fp=fopen(filepath ,READ);

	int count=0,str_len;
	char c;
	char word[SIZE];
	
	
	while(fscanf(fp,"%s%c",word,&c)!=EOF){
		//loop run till it reach the EOF
		str_len= strlen(word); //checking word char length
		
		if(count+str_len<=prt_len){
			printf("%s",word ); //prinitng if wrap size is available

			count+=str_len;
			if(c=='\n' ){
				count=0;
				printf("\n"); //checking it has new line if yes print new line
			}
			else if(c==' '){
				printf("%c",c); //priting space
				count+=1;
			}

			
		}
		else if(count+str_len>prt_len) {
			//when wrap length isnt enouh to print next word
			printf("\n");
			count=0;
			printf("%s",word );

			count+=str_len;
			if(c=='\n' ){
				
				count=0;
				printf("\n");
			}
			else if(c==' '){
				printf("%c",c);
				count+=1;
			}
		}
			
	}
	fclose(fp);

}


int main(int argc ,char** argv){

	FILE *fp;
	int max_strnlen,user_strnlen;
	char *filepath=argv[2];
	

	if (argc==3){
		user_strnlen=atoi(argv[1]);
		max_strnlen=word_count(fp,filepath);

		if(max_strnlen<=user_strnlen){
		 	word_wrap(fp,filepath,user_strnlen);
		}
		else{
			printf("Word length must me less than screen width\n");
			exit(0);
		}
	}
	else{
		fprintf(stderr,"Usage: ./prog <width> <input-file>\n");
		exit(0);
	}

return 0;
}