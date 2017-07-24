#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
int main(int argc, char *argv[]) {
    if (argc!=5) {
        perror("Argument count is wrong");
        exit(-1);
    }
    int argv1_notempty = strcmp(argv[1], "")!=0;
    int argv2_notempty = strcmp(argv[2], "")!=0;
    int argv3_notempty = strcmp(argv[3], "")!=0;
    int argv4_notempty = strcmp(argv[4], "")!=0;
    int checkfornotempty134 = argv1_notempty && argv3_notempty && argv4_notempty;
    if (!checkfornotempty134) {
        perror("One or more of your arguments are empty");
        exit(-1);
    }
    printf("<!DOCTYPE html><html><head>");
    if (!argv2_notempty) { // ./a.out "sitename" "" "style_gajs_header.txt" "keywords.txt"
        printf("<title>%s</title>\n", argv[1]);
    }
    else { // ./a.out "sitename" "pagename" "style_gajs_header.txt" "keywords.txt"
        printf("<title>%s | %s</title>\n", argv[1], argv[2]);
    }
    int styleFilenameExists = access(argv[3], R_OK) != -1;
    int keywordsFilenameExists = access(argv[4], R_OK) != -1;
    if (! (styleFilenameExists && keywordsFilenameExists)) {
        perror("An error has occurred");
        exit(-1);
    }
    printf("<meta charset=\"UTF-8\"/><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"/><meta name=\"keywords\" content=\"");
    FILE *infile = fopen(argv[4], "r");// read in and print out keywords
    char buffer[BUFFER_SIZE]={0};
    while (!feof(infile)) {
    	fgets(buffer, BUFFER_SIZE, infile);
        for (int i = strlen(buffer)-1; i >= 0; i--) { 
            if (buffer[i] == '\n') {
                buffer[i] = '\0';
                break;
            }
        }
        printf("%s, ", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }
    fclose(infile);
    printf("\b\b\b\b\"/>\n");
    infile = fopen(argv[3], "r");// cat out the aggregate style + analytics header file
    memset(buffer, 0, BUFFER_SIZE);
    while (!feof(infile)) {
    	fgets(buffer, BUFFER_SIZE, infile);
    	printf("%s", buffer);
    }
    fclose(infile);
    return 0;
}

