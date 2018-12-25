#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 80
#define MAX_STUDENTS 100
#define PASS_GRADE 50

typedef struct Student
{
    unsigned int id;
    unsigned int m1, m2, m3, m4;
    unsigned int final;
    float grade;
} Student;

Student *students[MAX_STUDENTS];
unsigned int num_students;
FILE *fp;

void read_students();
void evaluate_students();
void write_students();
int startswith(const char*, const char*);

int main(int argc, char* argv[])
{
    read_students();
    evaluate_students();
    write_students();
}

void read_students()
{
    char buffer[BUFFER_SIZE];

    fp = fopen("students.txt", "r+");
    if (fp == NULL) {
        printf("Error while loading students from file\n");
        exit(EXIT_FAILURE);
    }
    
    int i = 0;
    while (fgets(buffer, BUFFER_SIZE, (FILE*) fp)) {
        if (startswith(" ", buffer) || startswith("\t", buffer)) continue;
        Student *student = malloc(sizeof(Student));
        char student_data[6][BUFFER_SIZE];
        const char delim[3] = "\t\n";
        char * token;
        token = strtok(buffer, delim);
        int j = 0;
        while (token != NULL) {
            strcpy(student_data[j], token);
            token = strtok(NULL, delim);
            j++;
        }
        student->id    = (unsigned int) atoi(student_data[0]);
        student->m1    = (unsigned int) atoi(student_data[1]);
        student->m2    = (unsigned int) atoi(student_data[2]);
        student->m3    = (unsigned int) atoi(student_data[3]);
        student->m4    = (unsigned int) atoi(student_data[4]);
        student->final = (unsigned int) atoi(student_data[5]);
        students[i] = student;
        i++;
    }
    num_students = i;
    fclose(fp);
}

void evaluate_students()
{
    unsigned int i;
    for (i = 0; i < num_students; i++) {
        Student *s = students[i];
        float grade = (s->m1 * 0.15f + s->m2 * 0.15f + s->m3 * 0.15f + s->m4 * 0.15f + s->final * 0.4f);
        s->grade = grade;
    }
}

void write_students()
{
    fp = fopen("pass_students.txt", "w");
    fprintf(fp, "%s\t\t%s\t%s\t%s\t%s\t%s\t%s\n", "ID", "M1", "M2", "M3", "M4", "Final", "Grade");
    unsigned int i;
    for (i = 0; i < num_students; i++) {
        Student* s = students[i];
        if (s->grade >= PASS_GRADE) {
            printf("%u\t%u\t%u\t%u\t%u\t%u\t%.3f\n", s->id, s->m1, s->m2, s->m3, s->m4, s->final, s->grade);
            fprintf(fp, "%u\t%u\t%u\t%u\t%u\t%u\t%.3f\n", s->id, s->m1, s->m2, s->m3, s->m4, s->final, s->grade);
            free(s);
        }
    }
    fclose(fp);
}

int startswith(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre);
    size_t lenstr = strlen(str);
    return lenstr < lenpre ? 0 : strncmp(pre, str, lenpre) == 0;
}
