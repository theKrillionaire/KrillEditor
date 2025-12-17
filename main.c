#include <stdio.h>
#include <stdlib.h>

int getFile(char *fileName, char **outAr, int *length) {
    FILE* file = fopen(fileName, "r");
	if (file != NULL) {
		printf("file '%s' opened successfully!\n\n", fileName);
		char readFile[256][256];
		int line = 0;
		while(fgets(readFile[line], 256, file)) line++;
		*length = line;
		int i = 1;
		while(i < line) {
			outAr[i] = readFile[i];
			i++;
		}
		return 0;
	} else { printf("{ \e[1m\e[31mFAILURE\e[0m to read file: '\e[32m%s\e[0m' }\n", fileName); return 1; }
}

void printFile(char **file, int length) {
	for(int i = 0; i < length; i++) {
		if(file[i] != NULL) printf("%s", file[i]);
		else printf("\n");
	}
}

int main(int argc, char** argv) {
//  |  get the file
	int lineCount = 0;
	int *lineCPtr = &lineCount;
	char file[256][256];
	if(argc >= 2) { if(getFile(argv[1], (char**)file, lineCPtr)) return 1; }
	else { printf("{ \e[1m\e[31mNot enough arguments! \e[0m%i argument. }\n", argc); return 1; }

//  |  input
	int running = 1;
	char input[256];
	char lineC[3];
	int lineI = 0;
	while(running) {
		printFile((char**)file, lineCount);
		printf("input ?");
		fgets(input, 256, stdin);
		for(int lineI = 0; lineI < 3; lineI++) {
			lineC[lineI] = input[lineI];
		}
		printf("%s, %s", lineC, input);
	}
	return 0;
}

