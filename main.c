#include <stdio.h>


int getFile(char fileName[64], char **outAr) {
    FILE* file = fopen(fileName, "r");
	if (file != NULL) {
		printf("file '%s' opened successfully!\n\n", fileName);
		char readFile[256][256];
		int line = 0;
		while(fgets(readFile[line], 256, file)) line++;
		int i = 1;
		while(i < line) {
			outAr[i] = readFile[i];
			i++;
		}
	} else { printf("{ \e[1m\e[31mFAILURE\e[0m to read file: '\e[32m%s\e[0m' }\n", fileName); return 1; }
}
int main(int argc, char** argv) {
	char file[256][256];
	if(argc >= 2) { if(getFile(argv[1], (char**)file)) return 1; }
	else { printf("{ \e[1m\e[31mNot enough arguments! \e[0m%i argument. }\n", argc); return 1; }
	char input[256];
	fgets(input, 256, stdin);
	return 0;
}

