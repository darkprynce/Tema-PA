#include "cerinte.h"

void removeLowestTeam(struct Team** head) {
    if (*head == NULL)
        return;

    struct Team* current = *head;
    struct Team* prev = NULL;
    struct Team* lowest = *head;
    struct Team* lowestPrev = NULL;

    while (current != NULL) {
        if (current->averagePoints < lowest->averagePoints) {
            lowest = current;
            lowestPrev = prev;
        }
        prev = current;
        current = current->next;
    }

    if (lowest == *head)
        *head = lowest->next;
    else
        lowestPrev->next = lowest->next;

    free(lowest->name);
    free(lowest);
}

void printTeams(struct Team* head, FILE *file2) {
    struct Team* current = head;
    while (current != NULL) {
        fprintf(file2,"%s\n", current->name);
        current = current->next;
    }
}

