#include "cerinte.h"

struct Match* createMatch(struct Team* team1, struct Team* team2) {
    struct Match* match = (struct Match*)malloc(sizeof(struct Match));
    match->team1 = team1;
    match->team2 = team2;
    match->next = NULL;
    return match;
}

void enqueue(struct Queue* queue, struct Team* team1, struct Team* team2) {
    struct Match* newMatch = createMatch(team1, team2);
    if (queue->rear == NULL) {
        queue->front = newMatch;
        queue->rear = newMatch;
    } else {
        queue->rear->next = newMatch;
        queue->rear = newMatch;
    }
}

struct Match* dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return NULL;

    struct Match* match = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    return match;
}

void push(struct Stack* stack, struct Team* team) {
    team->next = stack->top;
    stack->top = team;
}

struct Team* pop(struct Stack* stack) {
    if (stack->top == NULL)
        return NULL;

    struct Team* team = stack->top;
    stack->top = stack->top->next;
    return team;
}

void freeMatches(struct Queue* queue) {
    struct Match* current = queue->front;
    while (current != NULL) {
        struct Match* temp = current;
        current = current->next;
        free(temp);
    }
    queue->front = NULL;
    queue->rear = NULL;
}

void printMatches(struct Queue* queue, FILE *file2) {
    struct Match* current = queue->front;
    while (current != NULL) {
        fprintf(file2,"%-32s - ", current->team1->name);
        fprintf(file2,"\t%s\n",  current->team2->name);
        current = current->next;
    }
}

void printWinners(struct Stack* stack, FILE *file2) {
    struct Team* current = stack->top;
    while (current != NULL) {
        fprintf(file2,"%-32s - %.2lf\n", current->name, current->averagePoints);
        current = current->next;
    }
}

void copyTeams(struct Team* source, struct Team** destination) {
    struct Team* currentSource = source;
    struct Team* currentDest = NULL;

    while (currentSource != NULL) {
        struct Team* newTeam = createTeam(currentSource->name, currentSource->averagePoints);

        if (*destination == NULL) {
            *destination = newTeam;
            currentDest = newTeam;
        } else {
            currentDest->next = newTeam;
            currentDest = currentDest->next;
        }

        currentSource = currentSource->next;
    }
}
