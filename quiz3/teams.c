/* Use compiler option     -std=c99 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 128
#define NUM_TEAMS 18
#define MAX_GOALS 5

typedef struct Team {
    char name[BUFFER_SIZE];
    int o, g, b, m, a, y, av, p; 
} Team;

int cmp(const void *a, const void *b);
void create_fixture();
void load_teams();
void write_teams();
void play_league();
void play_game(Team *t1, Team *t2);

Team *teams[NUM_TEAMS];
FILE *fp;
int matches[NUM_TEAMS-1][NUM_TEAMS];

int main(int argc, char* argv[])
{
    load_teams();
    create_fixture();
    play_league();
    write_teams();
}

void play_league()
{
    for (int i = 0; i < NUM_TEAMS - 1; i++) {
        printf("------------------------------------\n");
        printf("Week %d\n", i+1);
        printf("------------------------------------\n");
        for (int j = 0; j < NUM_TEAMS; j++) {
            play_game(teams[j], teams[matches[i][j]]);
        }
    }
}

void write_teams()
{
    qsort(teams, NUM_TEAMS, sizeof(Team*), cmp);
    fp = fopen("league_result.txt", "w");
    if (fp == NULL) {
        printf("Error while opening file\n");
    } else {
        printf("------------------------------------\n");
        printf("Name,O,G,B,M,A,Y,Av,P\n");
        printf("------------------------------------\n");
        for (int i = 0; i < NUM_TEAMS; i++) {
            Team t = *(teams[i]);
            fprintf(fp, "%s,%d,%d,%d,%d,%d,%d,%d,%d\n", t.name, t.o, t.g, t.b, t.m, t.a, t.y, t.av, t.p);
            printf("%s,%d,%d,%d,%d,%d,%d,%d,%d\n", t.name, t.o, t.g, t.b, t.m, t.a, t.y, t.av, t.p);
        }
    }
    fclose(fp);
}

int cmp(const void *a, const void *b)
{
    Team **t1 = (Team**) a;
    Team **t2 = (Team**) b;
    // If the points are equal compare the averages:
    if ((*t2)->p == (*t1)->p) return (*t2)->av - (*t1)->av;
    // Else compare points:
    return (*t2)->p - (*t1)->p;
}

void play_game(Team *t1, Team *t2)
{
    int g1 = rand() % MAX_GOALS;
    int g2 = rand() % MAX_GOALS;

    if (strcmp(t1->name, "Ankaragucu") == 0) {           //     :)
        g1 = MAX_GOALS;                                  //
    } else if (strcmp(t2->name, "Ankaragucu") == 0) {    //
        g2 = MAX_GOALS;                                  //
    }                                                    //

    if (g1 > g2) {
        t1->g++;
        t2->m++;
        t1->p += 3;
    } else if (g2 > g1) {
        t1->m++;
        t2->g++;
        t2->p += 3;
    } else {
        t1->b++;
        t2->b++;
        t1->p += 1;
        t2->p += 1;
    }
    t1->o++; t2->o++;
    t1->a += g1;
    t2->a += g2;
    t1->y += g2;
    t2->y += g1;
    t1->av = t1->a - t1->y;
    t2->av = t2->a - t2->y;
    printf("%s %d - %d %s\n", t1->name, g1, g2, t2->name);
}

void create_fixture()
{
    srand(time(NULL));
    for (int i = 0; i < NUM_TEAMS - 1; i++) {
        for (int j = 0; j < NUM_TEAMS; j++) {
            int n = NUM_TEAMS - 1;
            int home = (i + j) % n;
            int away = (i - j + n) % n;
            if (j == 0) away = NUM_TEAMS - 1;
            if (j == NUM_TEAMS - 1) home = NUM_TEAMS - 1;
            matches[i][home] = away;
            matches[i][away] = home;
        }
    }
}

void load_teams()
{
    char buffer[BUFFER_SIZE];
    fp = fopen("teams.txt", "r");
    if (fp == NULL) {
        printf("Error while opening file\n");
        exit(EXIT_FAILURE);
    } else {
        int i = 0;
        while (fgets(buffer, BUFFER_SIZE, (FILE*) fp)) {
            Team *team = malloc(sizeof(Team));
            char team_data[9][BUFFER_SIZE];
            const char delim[3] = ",\n";
            char *token;
            token = strtok(buffer, delim);
            int j = 0;
            while (token != NULL) {
                strcpy(team_data[j++], token);
                token = strtok(NULL, delim);
            }
            strcpy(team->name, team_data[0]);
            team->o     = atoi(team_data[1]);
            team->g     = atoi(team_data[2]);
            team->b     = atoi(team_data[3]);
            team->m     = atoi(team_data[4]);
            team->a     = atoi(team_data[5]);
            team->y     = atoi(team_data[6]);
            team->av    = atoi(team_data[7]);
            team->p     = atoi(team_data[8]);
            teams[i++]  = team;
        }
    }
    fclose(fp);
}
