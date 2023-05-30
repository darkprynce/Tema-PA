#include "cerinte.h"

struct Team* insertTeam(struct Team* root, struct Team* team) {
    if (root == NULL)
        return team;

    if (team->averagePoints > root->averagePoints) {
        root->right = insertTeam(root->right, team);
    } else if (team->averagePoints < root->averagePoints) {
        root->left = insertTeam(root->left, team);
    } else {
        int nameComparison = strcmp(team->name, root->name);
        if (nameComparison > 0) {
            root->right = insertTeam(root->right, team);
        } else {
            root->left = insertTeam(root->left, team);
        }
    }

    return root;
}

void printTeamsBST(struct Team* root, FILE *file2) {
    if (root == NULL)
        return;

    printTeamsBST(root->right, file2);
    fprintf(file2,"%-32s - %.2lf\n", root->name, root->averagePoints);
    printTeamsBST(root->left, file2);
}

void freeTeamsBST(struct Team* root) {
    if (root == NULL)
        return;

    freeTeamsBST(root->right);
    freeTeamsBST(root->left);

    free(root->name);
    free(root);
}
