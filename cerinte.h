#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Player {
    char* firstName;
    char* secondName;
    int points;
};

struct Match {
    struct Team* team1;
    struct Team* team2;
    struct Match* next;
};

struct Team {
    char* name;
    double averagePoints;
    struct Team* next;
    struct Team* left;
    struct Team* right;
};

struct Queue {
    struct Match* front;
    struct Match* rear;
};

struct Stack {
    struct Team* top;
};

struct AVLNode {
    char* name;
    double averagePoints;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

///cerinta 1
struct Team* createTeam(char* name, double averagePoints);
void addTeam(struct Team** head, char* name, double averagePoints);
void freeTeams(struct Team** head);

///cerinta 2
void removeLowestTeam(struct Team** head);
void printTeams(struct Team* head, FILE *file2);

///cerinta 3
struct Match* createMatch(struct Team* team1, struct Team* team2);
void enqueue(struct Queue* queue, struct Team* team1, struct Team* team2);
struct Match* dequeue(struct Queue* queue);
void push(struct Stack* stack, struct Team* team);
struct Team* pop(struct Stack* stack);
void freeMatches(struct Queue* queue);
void printMatches(struct Queue* queue, FILE *file2);
void printWinners(struct Stack* stack, FILE *file2);
void copyTeams(struct Team* source, struct Team** destination);

///cerinta 4
struct Team* insertTeam(struct Team* root, struct Team* team);
void printTeamsBST(struct Team* root, FILE *file2);
void freeTeamsBST(struct Team* root);

///cerinta 5
