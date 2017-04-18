/*
Text File Analyzer 
Namila Bandara
E/14/084
*/
#include <stdio.h>
#include <string.h>

#define READ "r"

typedef struct node{
	//creating a linked list for store data
	char* string;
	int count;
	struct node *next
}	linklist;  //linked list name

linklist *head=NULL;   //making head and current null
linklist *current=NULL;


linklist find(char* string){
	linklist current=head;

	if(head==NULL){
		return NULL;
	}

	while (strcmp(current->string,string)!=0){
		if(current->next==NULL){
			return NULL;
		}	
		else{
			current=current->next;
		}

	}
	return current;
}


void insertdata(char* string){
	linklist *link=(linklist)malloc (sizeof(linklist));
	current=find(string);
	
	if(current==NULL){
		link->string=string;
		link->count=1;
		link->next=head;
		head=link;
	}else{
		current->count=(current->count)+1;
		

	}




}




void readfile(File *fp,char *filepath){

	fp=fopen(filepath ,READ);



}



int main(int argc, char **argv){

	char *filepath=argv[1];
	File *fp;






}