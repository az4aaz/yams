/**
 * @file yams.c
 * @author Lucien HERVE J2
 * @brief Jeu du YAMS
 * @version 0.1
 * @date 2021-11-28
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/**
 * @brief Une procedure qui permet de reinitialiser le tableau des scores.
 * 
 * @param tabScore Le tableau des scores
 */
void resetScore(int tabScore[2][13]) {
    for (int joueur = 0; joueur < 2; joueur++) {
        for (int Case = 0; Case < 13; Case++) {
            tabScore[joueur][Case] = 0;
		}	
    }
}

/**
 * @brief Fonction qui convertie un int en str
 * 
 * @param val 
 * @param chaine 
 */
void changeTab(int val,char chaine[5]){
    sprintf(chaine,"%d", val);
}

/**
 * @brief Une procédure qui permet d'afficher le tableau des scores.
 * 
 * @param tabScore Le tableau des scores
 * @param prenomJ1 Une chaine de caractères qui contient le surnom du J1
 * @param prenomJ2 Une chaine de caractères qui contient le surnom du J2
 * @param totaux Un tableau qui contient les totaux des 2 joueurs
 */
void printScoreSheet(int tabScore[2][13], char prenomJ1[8], char prenomJ2[8], int totaux[2][3]) {
    char chaine1[5];
    char chaine2[5];
    printf("╔══════════════════════╦════════╦═══════╗\n");
    printf("║        Score         ║%s\t║%s\t║\n", prenomJ1, prenomJ2);
    printf("╠══════════════════════╬════════╬═══════╣\n");
    changeTab(tabScore[0][0], chaine1);
    changeTab(tabScore[1][0], chaine2);
    printf("║ 1 [total de 1]   ⚀   ║%s\t║%s\t║\n",(tabScore[0][0] == -1) ? "X":chaine1,(tabScore[1][0] == -1) ? "X":chaine2);
    changeTab(tabScore[0][1], chaine1);
    changeTab(tabScore[1][1], chaine2);
    printf("║ 2 [total de 2]   ⚁   ║%s\t║%s\t║\n",(tabScore[0][1] == -1) ? "X":chaine1,(tabScore[1][1] == -1) ? "X":chaine2);
    changeTab(tabScore[0][2], chaine1);
    changeTab(tabScore[1][2], chaine2);
    printf("║ 3 [total de 3]   ⚂   ║%s\t║%s\t║\n",(tabScore[0][2] == -1) ? "X":chaine1,(tabScore[1][2] == -1) ? "X":chaine2);
    changeTab(tabScore[0][3], chaine1);
    changeTab(tabScore[1][3], chaine2);
    printf("║ 4 [total de 4]   ⚃   ║%s\t║%s\t║\n",(tabScore[0][3] == -1) ? "X":chaine1,(tabScore[1][3] == -1) ? "X":chaine2);
    changeTab(tabScore[0][4], chaine1);
    changeTab(tabScore[1][4], chaine2);
    printf("║ 5 [total de 5]   ⚄   ║%s\t║%s\t║\n",(tabScore[0][4] == -1) ? "X":chaine1,(tabScore[1][4] == -1) ? "X":chaine2);
    changeTab(tabScore[0][5], chaine1);
    changeTab(tabScore[1][5], chaine2);
    printf("║ 6 [total de 6]   ⚅   ║%s\t║%s\t║\n",(tabScore[0][5] == -1) ? "X":chaine1,(tabScore[1][5] == -1) ? "X":chaine2);
    printf("║ -Bonus (t1>62→+32)   ║%d\t║%d\t║\n",(totaux[0][0] > 62) ? 32:0, (totaux[1][0] > 62) ? 32:0);
    printf("║ --Total superieur--  ║%d\t║%d\t║\n",totaux[0][0],totaux[1][0]);
    changeTab(tabScore[0][6], chaine1);
    changeTab(tabScore[1][6], chaine2);
    printf("║ Brelan [total]       ║%s\t║%s\t║\n",(tabScore[0][6] == -1) ? "X":chaine1,(tabScore[1][6] == -1) ? "X":chaine2);
    changeTab(tabScore[0][7], chaine1);
    changeTab(tabScore[1][7], chaine2);
    printf("║ Carré [total]        ║%s\t║%s\t║\n",(tabScore[0][7] == -1) ? "X":chaine1,(tabScore[1][7] == -1) ? "X":chaine2);
    changeTab(tabScore[0][8], chaine1);
    changeTab(tabScore[1][8], chaine2);
    printf("║ Full House [25]      ║%s\t║%s\t║\n",(tabScore[0][8] == -1) ? "X":chaine1,(tabScore[1][8] == -1) ? "X":chaine2);
    changeTab(tabScore[0][9], chaine1);
    changeTab(tabScore[1][9], chaine2);
    printf("║ Petite suite [30]    ║%s\t║%s\t║\n",(tabScore[0][9] == -1) ? "X":chaine1,(tabScore[1][9] == -1) ? "X":chaine2);
    changeTab(tabScore[0][10], chaine1);
    changeTab(tabScore[1][10], chaine2);
    printf("║ Grande suite [40]    ║%s\t║%s\t║\n",(tabScore[0][10] == -1) ? "X":chaine1,(tabScore[1][10] == -1) ? "X":chaine2);
    changeTab(tabScore[0][11], chaine1);
    changeTab(tabScore[1][11], chaine2);
    printf("║ Yams [50]            ║%s\t║%s\t║\n",(tabScore[0][11] == -1) ? "X":chaine1,(tabScore[1][11] == -1) ? "X":chaine2);
    changeTab(tabScore[0][12], chaine1);
    changeTab(tabScore[1][12], chaine2);
    printf("║ Chance [total]       ║%s\t║%s\t║\n",(tabScore[0][12] == -1) ? "X":chaine1,(tabScore[1][12] == -1) ? "X":chaine2);
    printf("║ --Total superieur    ║%d\t║%d\t║\n",totaux[0][1],totaux[1][1]);
    printf("║ ==Total 3 (t1+t2)    ║%d\t║%d\t║\n",totaux[0][2],totaux[1][2]);
    printf("╚══════════════════════╩════════╩═══════╝\n");
}

/**
 * @brief Une procédure qui permet de saisir les noms de chaques joueurs
 * 
 * @param prenomJ1 Une chaine de caractères qui contient le surnom du J1
 * @param prenomJ2 Une chaine de caractères qui contient le surnom du J1
 */
void saisieNom(char prenomJ1[8], char prenomJ2[8]) {
    char prenom[50];
    printf("Quel est le nom du joueur 1 ? \n");
    scanf("%s", prenom);
    while(strlen(prenom)>6) {
        printf("Erreur : veuillez saisir un nom compris entre 1 et 6 caractères\n");
        printf("Quel est le nom du joueur 1 ? \n");
        scanf("%s", prenom);
    };
    strcpy(prenomJ1, prenom);
    printf("Quel est le nom du joueur 2 ? \n");
    scanf("%s", prenom);
    while(strlen(prenom)>6) {
        printf("Erreur : veuillez saisir un nom compris entre 1 et 6 caractères\n");
        printf("Quel est le nom du joueur 2 ? \n");
        scanf("%s", prenom);
    };
    strcpy(prenomJ2, prenom);
    printf("%s : %s\n", prenomJ1, prenomJ2);
}

/**
 * @brief Une procédure qui permet d'afficher les dés
 * 
 * @param lesDe Un tableau qui contient les valeurs des dés
 */
void afficherDe(int lesDe[5]) {
    for (int de=0; de<5; de++) {
        printf("┌───┐  ");
    }
    printf("\n");
    for (int de=0; de<5; de++) {
        printf("│ %d │  ", lesDe[de]);
    }
    printf("\n");
    for (int de=0; de<5; de++) {
        printf("└───┘  ");
    }
    printf("\n");
}

/**
 * @brief Une procédure qui permet de generer un liste de dés alétoires
 * 
 * @param lesDe Un tableau qui contient les valeurs des dés
 */
void lancerDe(int lesDe[5]) {
    for (int de = 0; de < 5; de++) {
        if (lesDe[de]==0) {
            lesDe[de] = (rand()%6)+1;
        }
    }
}

/**
 * @brief Un procédure qui permet à l'utilisateur de conserver ses dés/lancer
 * 
 * @param lesDe Un tableau qui contient les valeurs des dés
 */
void conservDe(int lesDe[5]) {
    int cmpt = 0;
    char entree2[5];
    char entree1[5];
    do {
        afficherDe(lesDe);
        printf("Voulez-vous conserver ce lancer ? (oui ou non)\n");
        scanf("%s", entree1);
        if (strcmp(entree1,"oui")!=0 && strcmp(entree1,"Oui")!=0 && strcmp(entree1,"O")!=0 && strcmp(entree1,"o")!=0) {
            do {
                printf("Quel dé voulez-vous relancer ? (n° du dé ou 'non' si fini)\n");
                scanf("%s", entree2);
                if (strcmp(entree2, "non")!=0 && strcmp(entree2, "Non")!=0 && strcmp(entree2, "N")!=0 && strcmp(entree2, "n")!=0) {
                    lesDe[atoi(entree2)-1] = 0;
                }
            } while (strcmp(entree2, "non")!=0 && strcmp(entree2, "Non")!=0 && strcmp(entree2, "N")!=0 && strcmp(entree2, "n")!=0);
            cmpt++;
            lancerDe(lesDe);
        }
    } while (cmpt < 2 && strcmp(entree1,"oui")!=0 && strcmp(entree1,"Oui")!=0 && strcmp(entree1,"O")!=0 && strcmp(entree1,"o")!=0);
}

/**
 * @brief Procédure de tri (bulle) permettant de trier les dés
 * 
 * @param lesDe Un tableau qui contient les valeurs des dés
 */
void triBulle(int lesDe[5]) {
  for (int j = 0; j < 5 - 1; ++j) {
    for (int i = 0; i < 5 - j - 1; ++i) {
      if (lesDe[i] > lesDe[i + 1]) {
        int temp = lesDe[i];
        lesDe[i] = lesDe[i + 1];
        lesDe[i + 1] = temp;
      }
    }
  }
}

/**
 * @brief Une fonction qui permet de ressortir le nombre total qu'apparait une valeur x de dé dans un tableau
 * 
 * @param x le dé recherché
 * @param lesDe Un tableau qui contient les valeurs des dés
 * @return int Le nombre de fois qu'apparait cette valeur
 */
int total_x(int x, int lesDe[5]) {
    int somme = 0;
    for (int de = 0; de < 5; de++) {
        if (lesDe[de] == x) {
            somme++;
        }
    }
    return somme*x;
}

/**
 * @brief Fonction qui permet de generer la somme d'un tableau de dé
 * 
 * @param lesDe Un tableau qui contient les valeurs des dés
 * @return int La somme de toutes les valeurs du tableau
 */
int sommeDe(int lesDe[5]) {
    int somme = 0;
    for (int de = 0; de < 5; de++) {
        somme+=lesDe[de];
    }
    return somme;
}

/**
 * @brief Un procédure qui permet de remetre à 0 un tableau de taille 13
 * 
 * @param tab le tableau a remettre a 0
 */
void videTableau(int tab[13]) {
    for (int i = 0; i<13; i++) {
        tab[i] = 0;
    }
}

/**
 * @brief Une procédure qui permet de supprimer les doublons
 * 
 * @param lesDe Un tableau qui contient les valeurs des dés
 */
void sansDoublons(int lesDe[5]) {
    int valeurs[6] = {0,0,0,0,0,0};
    for (int i = 0; i < 5; i++){
        if (valeurs[lesDe[i]-1] == 0) {
            valeurs[lesDe[i]-1] += 1;
        } else {
            lesDe[i] = -1;
        }
    }
    triBulle(lesDe);
}

/**
 * @brief Une procédure qui permet de detecter les combinaisons possibles a partir de dés
 * 
 * @param lesDe Un tableau qui contient les valeurs des dés
 * @param possibilite Un tableau qui contient toutes les possibilités qu'a le joueur
 */
void detectionComb(int lesDe[5], int possibilite[13]) {
    triBulle(lesDe);
    int totalValTab[5];
    int brelan[2] = {0,0};
    videTableau(possibilite);
    for (int val = 0; val < 6; val++) {
        totalValTab[val] = total_x(val+1, lesDe);
        if (brelan[0] == 1 && val != brelan[1] && totalValTab[val]>2) { //Full house
            possibilite[7] = 25;
        }
        if (totalValTab[val] >= (val+1)*3) { // Brelan
            possibilite[6] = (val+1)*3;
            brelan[0] = 1;
            brelan[1] = val;
        } if (totalValTab[val] >= (val+1)*4) { // Carré
            possibilite[7] = (val+1)*4;
            printf("%d", totalValTab[val]);
        } if (totalValTab[val] == (val+1)*5) { // Yams
            possibilite[11] = 50;
        }
    }
    for (int val = 0; val < 6; val++) {
        possibilite[val] = totalValTab[val];
    }
    if (lesDe[1]==(lesDe[0]+1) && lesDe[2]==(lesDe[1]+1) && lesDe[3]==(lesDe[2]+1) && lesDe[4]==(lesDe[3]+1)) { // Grande suite
        possibilite[10] = 40;
    } 
    int lesDe2[5];
    for (int i = 0; i < 5; i++) {
        lesDe2[i] = lesDe[i];
    }
    sansDoublons(lesDe2);
    if ((lesDe2[1]==(lesDe2[0]+1) && lesDe2[2]==(lesDe2[1]+1) && lesDe2[3]==(lesDe2[2]+1)) || 
     (lesDe2[2]==(lesDe2[1]+1) && lesDe2[3]==(lesDe2[2]+1) && lesDe2[4]==(lesDe2[3]+1))) { // Petite suite
        possibilite[10] = 30;
    }
}

/**
 * @brief Procédure qui permet de bloquer une case
 * 
 * @param tabScore Un tableau qui contient les scores des 2 joueurs
 */
void bloquageCase(int tabScore[2][13], int joueur) {
    int j = 0;
    int saisie;
    int savePosition[13];
    char noms[13][20] = {"Somme des 1","Somme des 2","Somme des 3","Somme des 4","Somme des 5","Somme des 6","Brelan","Carré", "Full house", "Petite suite", "Grande suite", "Yams", "Chance"};
    for (int i = 0; i < 13; i++) {
        if (tabScore[joueur][i] == 0) {
            savePosition[j] = i;
            j++;
            printf("%d - %s\n", j, noms[i]);
        }
    }
    printf("Choix : ");
    printf("Choisir une case à bloquer : \n");
    scanf("%d", &saisie);
    tabScore[joueur][savePosition[saisie-1]] = -1;
    
}

/**
 * @brief Une procédure qui permet de saisir les scores dans le tableau des scores
 * 
 * @param lesDe Un tableau qui contient les valeurs des dés
 * @param tabScore Un tableau qui contient les scores des 2 joueurs
 * @param joueur Int qui correspond au joueur actif
 */
void rentreeScore(int lesDe[5], int tabScore[2][13], int joueur) {
    int poss[13];
    char noms[13][20] = {"Somme des 1","Somme des 2","Somme des 3","Somme des 4","Somme des 5","Somme des 6","Brelan","Carré", "Full house", "Petite suite", "Grande suite", "Yams", "Chance"};
    int saisie;
    int savePosition[10];
    int saveScore[10];
    int j = 0;
    detectionComb(lesDe, poss);
    printf("Où souhaitez-vous placer votre score ?\n");
    for (int i = 0; i<13; i++) {
        if (poss[i] != 0) {
            savePosition[j] = i;
            saveScore[j] = poss[i];
            if (tabScore[joueur][savePosition[j]] == 0) {
                j++;
                printf("%d - %s (%d)\n", j, noms[i], poss[i]);
            }
        }
    }
    printf("%d - Bloquer une case\n", j+1);
    printf("%d - Case chance\n", j+2);
    printf("Choix : ");
    scanf("%d", &saisie);
    if (saisie == j+1) {
        bloquageCase(tabScore, joueur);
    } else if (saisie == j+2){
        if (tabScore[joueur][12]==0) {
            tabScore[joueur][12] = sommeDe(lesDe);
        } else {
            printf("Case déjà prise !\n");
        }
    } else {
        tabScore[joueur][savePosition[saisie-1]] = saveScore[saisie-1];
    }
}

/**
 * @brief Procédure qui permet de reinitialiser les dés
 * 
 * @param lesDe Un tableau qui contient les valeurs des dés
 */
void resetDe(int lesDe[5]) {
    for (int de = 0; de < 5; de++) {
        lesDe[de] = 0;
    }
}

/**
 * @brief Procédure qui met a jour les totaux
 * 
 * @param tabScore Un tableau qui contient les scores des 2 joueurs
 * @param totaux Un tableau qui contient les totaux des 2 joueurs
 */
void updateTotaux(int tabScore[2][13], int totaux[2][3]) {
    bool dejaFait = false;
    int somme = 0;
    for (int j = 0; j < 2; j++) {
        somme = 0;
        for (int i = 0; i < 6; i++) {
            if (tabScore[j][i] != -1) {
                somme+=tabScore[j][i];
            }
        }
        if (somme>62 && dejaFait != true) {
            totaux[j][0] = somme+32;
            dejaFait = true;
        } else {
            totaux[j][0] = somme;
        }
        totaux[j][0] = somme;
        somme=0;
        for (int i = 6; i < 13; i++) {
            if (tabScore[j][i] != -1) {
                somme+=tabScore[j][i];
            }
        }
        totaux[j][1] = somme;
        totaux[j][2] = totaux[j][0] + totaux[j][1];
    }
    
}

/**
 * @brief Procédure qui affiche le gagant
 * 
 * @param prenomJ1 Prénom du joueur 1
 * @param prenomJ2 Prénom du joueur 2
 * @param totaux Tableau qui contient les totaux des 2 joueursS
 */
void gagnant(char prenomJ1[8], char prenomJ2[8], int totaux[2][3]) {
    if (totaux[0][3]>totaux[1][3]) {
        printf("Bravo %s ! Tu as gagné\n", prenomJ1);
    } else if (totaux[0][3] == totaux[1][3]) {
        printf("Égalité !\n");
    } else {
        printf("Bravo %s ! Tu as gagné\n", prenomJ2);
    }
}

/**
 * @brief Le main
 * 
 * @return int EXIT_SUCCESS
 */
int main() {
    srand(time(NULL));
    int score[2][13];
    int total[2][3];
    char names[2][8];
    int de[5];
    printf("__  _____    __  ________\n\\ \\/ /   |  /  |/  / ___/\n \\  / /| | / /|_/ /\\__ \\ \n / / ___ |/ /  / /___/ / \n/_/_/  |_/_/  /_//____/  \n\n");
    //affichage titre du jeu
    resetScore(score);
    saisieNom(names[0], names[1]);
    for (int tour = 0; tour < 26; tour++ ) {
        resetDe(de);
        printScoreSheet(score, names[0], names[1], total);
        printf("Tour de %s :\n", names[tour%2]);
        lancerDe(de);
        /* for (int i =0; i<5; i++){
            de[i] = (i%2)+2;
        } */
        conservDe(de);
        afficherDe(de);
        rentreeScore(de, score, tour%2);
        updateTotaux(score, total);
    }
    gagnant(names[0], names[1], total);
}

