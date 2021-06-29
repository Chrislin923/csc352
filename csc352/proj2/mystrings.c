#include <stdio.h>
#include<stdlib.h>

//Project 2: mystrings.c
//By Chris Lin
//Purpose: print strings one per line base on the input file

int main(int argc, char *argv[]){
	FILE * file;
	char str[100];
	char ch;
	int i = 0;
	int index;
	file = fopen(argv[1], "rb");
	if(file == NULL){
		printf("File not exist");
		exit(1);
	}

	ch = fgetc(file);
	while((ch != EOF)){
		while( ch >= 32 && ch <= 126 && ch != EOF){
			str[i] =ch;
			i++;
			ch = fgetc(file);
		}
		str[i] = '\0';
		if(i >= 4){
			printf("%s\n", str );
		}
		for(index = 0; index < i; index++){
			str[index] = '\0';
		}
		i = 0;
		ch = fgetc(file);

	}
	fclose(file);
	return 0;


}