#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    assert(argc==5);
    int argv1_notempty = strcmp(argv[1], "")!=0;
    int argv2_notempty = strcmp(argv[2], "")!=0;
    int argv3_notempty = strcmp(argv[3], "")!=0;
    int argv4_notempty = strcmp(argv[4], "")!=0;
    int case0 = argv1_notempty && argv2_notempty && argv3_notempty && argv4_notempty;
    int case1 = argv1_notempty && (!argv2_notempty) && argv3_notempty && argv4_notempty;
    assert( case0 || case1 );

    printf("<!DOCTYPE html><html><head>");
    if (strcmp(argv[2], "")==0) { // ./a.out "sitename" "" "style_gajs_header.txt" "keywords.txt"
        printf("<title>%s</title>\n", argv[1]);
    }
    else { // ./a.out "sitename" "pagename" "style_gajs_header.txt" "keywords.txt"
        printf("<title>%s | %s</title>\n", argv[1], argv[2]);
    }

    char *STYLE_GAJS_HEADER_FILENAME = argv[3];
    char *KEYWORDS_FILENAME = argv[4];
    printf("<meta charset=\"UTF-8\"/>\n");
    printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"/>\n");   
    printf("<meta name=\"keywords\" content=\"");

    // read in and print out keywords
    FILE *infile = fopen(KEYWORDS_FILENAME, "r");
    char buffer[1024]={0};
    while (!feof(infile)) {
    	fgets(buffer, 1024, infile);
        int i = 0;
        for (i = strlen(buffer)-1; i >= 0; i--) { 
            if (buffer[i] == '\n') {
                buffer[i] = '\0';
                break;
            }
        }
        printf("%s, ", buffer);
        // zero out the buffer
        for (int i = 0; i < 1024; i++) {
            buffer[i] = 0;
        }
    }
    fclose(infile);
    printf("\b\b\b\b");
    printf("\"/>\n");

    // cat out the aggregate style + analytics header file
    infile = fopen(STYLE_GAJS_HEADER_FILENAME, "r");
    for (int i = 0; i < 1024; i++) {
        buffer[i] = 0;
    }
    while (!feof(infile)) {
    	fgets(buffer, 1024, infile);
    	printf("%s", buffer);
    }
    fclose(infile);
    return 0;
}

