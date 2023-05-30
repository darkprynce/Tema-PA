#include "cerinte.h"

int main() {
    FILE* file = fopen("d.in", "r");
    if (file == NULL) {
        printf("Nu s-a putut deschide fisierul.");
        return 1;
    }

    FILE* file2 = fopen("r.out", "w");
    if (file2 == NULL) {
        printf("Nu s-a putut deschide fisierul.");
        return 1;
    }

    int numTeams;
    fscanf(file, "%d", &numTeams);

    struct Team* teams = NULL;

    for (int i = 0; i < numTeams; i++) {
        int numPlayers;
        char teamName[100];
        fscanf(file, "%d %[^\n]%*c", &numPlayers, teamName);

        int totalPoints = 0;
        for (int j = 0; j < numPlayers; j++) {
            char firstName[100], secondName[100];
            int points;
            fscanf(file, "%s %s %d", firstName, secondName, &points);
            totalPoints += points;
        }

        double averagePoints = (double)totalPoints / numPlayers;
        addTeam(&teams, teamName, averagePoints);
    }

    fclose(file);

    struct Queue matchQueue;
    matchQueue.front = NULL;
    matchQueue.rear = NULL;

    struct Stack winnersStack;
    winnersStack.top = NULL;

    int n = 1;
    while (n <= numTeams) {
        n = n * 2;
    }

    if (n > numTeams)
        n = n / 2;

    while (numTeams > n) {
        removeLowestTeam(&teams);
        numTeams--;
    }

    printTeams(teams, file2);

    fprintf(file2,"\n");

    int roundNum = 1;

    while (numTeams > 8) {
        fprintf(file2,"--- ROUND NO:%d\n", roundNum);
        struct Team* team1;
        struct Team* team2;

        while (teams != NULL) {
            team1 = teams;
            teams = teams->next;
            team2 = teams;
            teams = teams->next;

            struct Match* newMatch = createMatch(team1, team2);
            enqueue(&matchQueue, team1, team2);
        }

        printMatches(&matchQueue, file2);

        fprintf(file2,"\n");

        while (matchQueue.front != NULL) {
            struct Match* match = dequeue(&matchQueue);

            struct Team* winner;
            if (match->team1->averagePoints > match->team2->averagePoints) {
                winner = match->team1;
                winner->averagePoints++;
            } else {
                winner = match->team2;
                winner->averagePoints++;
            }

            push(&winnersStack, winner);
        }

        fprintf(file2,"WINNERS OF ROUND NO:%d\n", roundNum);
        printWinners(&winnersStack, file2);

        fprintf(file2,"\n");

        while (winnersStack.top != NULL) {
            struct Team* team = pop(&winnersStack);
            addTeam(&teams, team->name, team->averagePoints);
        }

        roundNum++;
        numTeams = numTeams / 2;
    }

    struct Team* lastEightTeams = NULL;
    copyTeams(teams, &lastEightTeams);

    while (numTeams > 1) {
        fprintf(file2,"--- ROUND NO:%d\n", roundNum);
        struct Team* team1;
        struct Team* team2;

        while (teams != NULL) {
            team1 = teams;
            teams = teams->next;
            team2 = teams;
            teams = teams->next;

            struct Match* newMatch = createMatch(team1, team2);
            enqueue(&matchQueue, team1, team2);
        }

        printMatches(&matchQueue, file2);

        fprintf(file2,"\n");

        while (matchQueue.front != NULL) {
            struct Match* match = dequeue(&matchQueue);

            struct Team* winner;
            if (match->team1->averagePoints > match->team2->averagePoints) {
                winner = match->team1;
                winner->averagePoints++;
            } else {
                winner = match->team2;
                winner->averagePoints++;
            }

            push(&winnersStack, winner);
        }

        printWinners(&winnersStack, file2);

        fprintf(file2,"\n");

        while (winnersStack.top != NULL) {
            struct Team* team = pop(&winnersStack);
            addTeam(&teams, team->name, team->averagePoints);
        }

        roundNum++;
        numTeams = numTeams / 2;
    }


    struct Team* bstRoot = NULL;
    struct Team* currentNode = bstRoot;
    struct Team* current = lastEightTeams;
    while (current != NULL) {
        struct Team* next = current->next;
        current->next = NULL;
        bstRoot = insertTeam(bstRoot, current);
        current = next;
    }

    fprintf(file2,"TOP 8 TEAMS:\n");
    printTeamsBST(bstRoot, file2);

    freeTeamsBST(bstRoot);
    freeTeams(&teams);
    freeMatches(&matchQueue);

    return 0;
}
