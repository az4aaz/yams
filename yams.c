#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void resetScore(int tabScore[2][17]) {
    for (int joueur = 0; joueur < 2; joueur++) {
        for (int Case = 0; Case < 17; Case++) {
            tabScore[joueur][Case] = 0;
		}	
    }
}


void printScoreSheet(int tabScore[2][17], char prenomJ1[8], char prenomJ2[8]) {
    printf("╔══════════════════════╦════════╦═══════╗\n");
    printf("║        Score         ║%s\t║%s\t║\n", prenomJ1, prenomJ2);
    printf("╠══════════════════════╬════════╬═══════╣\n");
    printf("║ 1 [total de 1]    ⚀  ║%d\t║%d\t║\n",tabScore[0][0],tabScore[1][0]);
    printf("║ 2 [total de 2]    ⚁  ║%d\t║%d\t║\n",tabScore[0][1],tabScore[1][1]);
    printf("║ 3 [total de 3]    ⚂  ║%d\t║%d\t║\n",tabScore[0][2],tabScore[1][2]);
    printf("║ 4 [total de 4]    ⚃  ║%d\t║%d\t║\n",tabScore[0][3],tabScore[1][3]);
    printf("║ 5 [total de 5]    ⚄  ║%d\t║%d\t║\n",tabScore[0][4],tabScore[1][4]);
    printf("║ 6 [total de 6]    ⚅  ║%d\t║%d\t║\n",tabScore[0][5],tabScore[1][5]);
    printf("║ -Bonus (t1>62→+32)   ║%d\t║%d\t║\n",tabScore[0][6],tabScore[1][6]);
    printf("║ --Total superieur--  ║%d\t║%d\t║\n",tabScore[0][7],tabScore[1][7]);
    printf("║ Brelan [total]       ║%d\t║%d\t║\n",tabScore[0][8],tabScore[1][8]);
    printf("║ Carré [total]        ║%d\t║%d\t║\n",tabScore[0][9],tabScore[1][9]);
    printf("║ Full House [25]      ║%d\t║%d\t║\n",tabScore[0][10],tabScore[1][10]);
    printf("║ Petite suite [30]    ║%d\t║%d\t║\n",tabScore[0][11],tabScore[1][11]);
    printf("║ Grande suite [40]    ║%d\t║%d\t║\n",tabScore[0][12],tabScore[1][12]);
    printf("║ Yams [50]            ║%d\t║%d\t║\n",tabScore[0][13],tabScore[1][13]);
    printf("║ Chance [total]       ║%d\t║%d\t║\n",tabScore[0][14],tabScore[1][14]);
    printf("║ --Total superieur    ║%d\t║%d\t║\n",tabScore[0][15],tabScore[1][15]);
    printf("║ ==Total 3 (t1+t2)    ║%d\t║%d\t║\n",tabScore[0][16],tabScore[1][16]);
    printf("╚══════════════════════╩════════╩═══════╝\n");
}

void saisieNom(char prenomJ1[8], char prenomJ2[8]) {
    char prenom[50];
    printf("Quel est le nom du joueur 1 ? \n");
    scanf("%s", prenom);
    while(strlen(prenom)>7) {
        printf("Erreur : veuillez saisir un nom compris entre 1 et 7 caractères\n");
        printf("Quel est le nom du joueur 1 ? \n");
        scanf("%s", prenom);
    };
    strcpy(prenomJ1, prenom);
    printf("Quel est le nom du joueur 2 ? \n");
    scanf("%s", prenom);
    while(strlen(prenom)>7) {
        printf("Erreur : veuillez saisir un nom compris entre 1 et 7 caractères\n");
        printf("Quel est le nom du joueur 2 ? \n");
        scanf("%s", prenom);
    };
    strcpy(prenomJ2, prenom);
    printf("%s : %s\n", prenomJ1, prenomJ2);
}

void lancerDe(int qtDe, int sortieDe[5]) {
    for (int de=0; de<qtDe; de++) {
        printf("┌───┐  ");
    }
    printf("\n");
    for (int de=0; de<qtDe; de++) {
        sortieDe[de] = (rand()%6)+1;
        printf("│ %d │  ", sortieDe[de]);
    }
    printf("\n");
    for (int de=0; de<qtDe; de++) {
        printf("└───┘  ");
    }
    printf("\n");
}

void conservDe(int lesDe[5]) {

}

void rentreeScore(int lesDe[5], int tabScore[2][17], int joueur) {

}

int main() {
    srand(time(NULL));
    int score[2][17];
    char nameJ1[8], nameJ2[8];
    int de[5];
    char reponse[20];
    printf("__  _____    __  ________\n");
    printf("\\ \\/ /   |  /  |/  / ___/\n");
    printf(" \\  / /| | / /|_/ /\\__ \\ \n");
    printf(" / / ___ |/ /  / /___/ / \n");
    printf("/_/_/  |_/_/  /_//____/  \n");
    printf("\n"); 
    resetScore(score);
    score[0][0] = 100;
    saisieNom(nameJ1, nameJ2);
    for (int tour = 1; tour < 27; tour++ ) {
        printScoreSheet(score, nameJ1, nameJ2);
        printf("Tour de %s :\n", nameJ1);
        lancerDe(5, de);
        conservDe(de);
        rentreeScore(de, score, tour+1);
    }
    
    
}

