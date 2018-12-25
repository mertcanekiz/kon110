#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000
#define CHARACTER_INTERVAL 58 /* 'A' = 65, 'z' = 122 */

FILE *fp;
char text[MAX_SIZE];
int chars[CHARACTER_INTERVAL]; 

void read_file();
void count_chars();
void print_counts();

int main(int argc, char* argv[])
{
    read_file();
    count_chars();
    print_counts();
    return 0;
}

void print_counts()
{
    unsigned int i;
    for (i = 0; i < CHARACTER_INTERVAL; i++) {
        char c = (char) i + 'A';
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            printf("%c: %u\n", (char) (i + 'A'), chars[i]);
        }
    }
}

void count_chars()
{
    unsigned int i;
    for (i = 0; i < strlen(text); i++) {
        char c = text[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            unsigned int index = c - 'A';
            chars[index]++;
        }
    }
}

void read_file()
{
    long lsize;
    char *buffer;
    fp = fopen("Kratos.txt", "rb");
    if (fp == NULL) {
        printf("Error while loading file\n");
        exit(EXIT_FAILURE);
    } else {
        fseek(fp, 0L, SEEK_END);
        lsize = ftell(fp);
        rewind(fp);

        buffer = calloc(1, lsize+1);
        if (!buffer) fclose(fp), fputs("Memory allocation failed", stderr), exit(EXIT_FAILURE);
        if (fread(buffer, lsize, 1, fp) != 1) {
            fclose(fp), free(buffer), fputs("Reading file failed", stderr), exit(EXIT_FAILURE);
        }
        strcpy(text, buffer);
        fclose(fp);
        free(buffer);
    }
}
