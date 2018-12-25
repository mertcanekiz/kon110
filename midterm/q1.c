#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char number_str[10];
    while (1) {
        printf("-----------------\n");
        printf("Please enter your student number or q to quit:\n");
        gets(number_str);
        if (number_str[0] == 'q') {
            break;
        }
        int n = strlen(number_str);
        if (!(n == 9 || n == 8)) {
            printf("Invalid student number. Please enter your student number with 8 or 9 digits\n");
            continue;
        }
        int number = atoi(number_str);
        int dept = (number % 10000) / 100;
        int year = 2000 + (number % (int)(1e7)) / (int) 1e4;
        int faculty = number / (int) 1e7;
        switch (faculty) {
            case 4:
                switch(dept) {
                    case 3:
                        printf("Department: KON\n");
                        break;
                    case 4:
                        printf("Department: EHB\n");
                        break;
                    case 5:
                        printf("Department: ELK\n");
                        break;
                }
                break;
        }
        printf("Year: %d\n", year);
    }
    return 0;
}
