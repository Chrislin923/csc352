#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct bmp_header{
	short id;
	int size;
	short resrved_v1;
	short resrved_v2;
	int offset;
};

struct dib_header{
	int size;
	int width;
	int height;
	short cplanes;
	short bits;
	int scheme;
	int image_s;
	int hori;
	int verti;
	int palette;
	int colors;
};


int main(int argc, char *argv[]){
	FILE * bmp_file;
	bmp_file = fopen(argv[argc - 1], "r");
	if(bmp_file == NULL){
		printf("File not exist");
		return 0;
	}
	struct bmp_header bmp;
	struct dib_header dib;
	fread(&bmp, sizeof(bmp), 1, bmp_file);
	if(bmp.id != 0x4D42){
		printf("Not BMP file.\n");
		return 0;
	}
	fread(&dib, sizeof(dib), 1, bmp_file);
	//if(dib.size != 0x28){
	//	printf("Not BMP file.\n");
	//	return 0;
	//}
	
	//if(dib.bits != 0x18){
	//	printf("Not BMP file.\n");
	//	return 0;
	//}
	fseek(bmp_file, bmp.offset, SEEK_SET);
	
	return 0;
}