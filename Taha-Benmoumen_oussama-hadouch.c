#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficher_jouer(int choix_j1, int choix_j2, int *score_j1, int *score_j2) {
    if (choix_j1 == choix_j2) {
       printf("\033[1;31m"); printf("Match nul !\n");printf("\033[0m");
    } else if (
        (choix_j1 == 0 && choix_j2 == 1) ||
        (choix_j1 == 1 && choix_j2 == 2) ||
        (choix_j1 == 2 && choix_j2 == 0)
    ) {
        printf("Le joueur 1 gagne !\n");
        (*score_j1)++;
    } else {
        printf("Le joueur 2 gagne !\n");
        (*score_j2)++;
    }
}

void afficher_score(int score_j1, int score_j2) { printf("\033[1;32m");
    printf("Score : Joueur 1 : %d, Joueur 2 : %d\n", score_j1, score_j2);printf("\033[0m");
}

int main() {
    srand(time(NULL));
    int nombre_parties;
    printf("Entrer le nombre de parties : ");
    scanf("%d", &nombre_parties);

    int score_j1 = 0;
    int score_j2 = 0;

    for (int i = 0; i < nombre_parties; i++) {
        int choix_j1, choix_j2;

        printf("\033[1;33m");
        printf("Choisissez l'élément pour le joueur 1 (0 - PAPIER, 1 - CAILLOUX, 2 - CISEAUX) : ");
        printf("\033[0m");
        scanf("%d", &choix_j1);

        
        while (choix_j1 < 0 || choix_j1 > 3) {
            printf("\033[1;31m");
            printf("Erreur: Valeur incorrecte. Veuillez entrer une valeur entre 0 et 3 : ");
            printf("\033[0m");
            scanf("%d", &choix_j1);
        }

        choix_j2 = rand() % 3;

         printf("\033[1;34m");printf("Partie %d : ", i + 1);
        afficher_jouer(choix_j1, choix_j2, &score_j1, &score_j2);
        afficher_score(score_j1, score_j2);printf("\033[0m");
    }

    return 0;
}