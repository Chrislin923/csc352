#include <stdio.h>
#include <stdlib.h>


struct bmp_header{
	char id[2];
	int size;
	char resrved_v1[2];
	char resrved_v2[2];
	int offset;

};

struct dib_header{
	int size;
	int width;
	int height;
	char cplanes[2];
	char bits[2];
	int scheme;
	int image_s;
	int hori;
	int verti;
	int palette;
	int colors;
};


int main(int argc, char* argv[]){
	FILE* bmp_file;
	bmp_file = fopen(argv[argc - 1], "r");
	void * bmp_h[100];
	if(feof(bmp_file)){
		printf("File does not exist\n");
	}
	fread(bmp_h, sizeof(bmp_h), 1, bmp_file);
	printf("%p\n", bmp_h);
	return 0;
}