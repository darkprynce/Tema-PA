#include "cerinte.h"

struct Team* createTeam(char* name, double averagePoints) {
    struct Team* team = (struct Team*)malloc(sizeof(struct Team));
    team->name = strdup(name);
    team->averagePoints = averagePoints;
    team->next = NULL;
    team->left = NULL;
    team->right = NULL;
    return team;
}

void addTeam(struct Team** head, char* name, double averagePoints) {
    struct Team* newTeam = createTeam(name, averagePoints);
    newTeam->next = *head;
    *head = newTeam;
}

void freeTeams(struct Team** head) {
    struct Team* current = *head;
    while (current != NULL) {
        struct Team* temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }
    *head = NULL;
}
