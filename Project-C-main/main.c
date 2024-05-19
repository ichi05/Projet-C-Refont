#include <stdio.h>
#include <stdlib.h>
#include "Fonction.h"

int main() {
    int choice;
    Column* columns[100];
    int num_columns = 0;
    char title[100];
    int value;
    int col_index;

    do {
        printf("\nMenu :\n");
        printf("1. Creer une colonne\n");
        printf("2. Inserer une valeur dans une colonne existante\n");
        printf("3. Afficher le contenu d'une colonne existante\n");
        printf("4. Afficher le contenu de toute les colonnes \n");
        printf("5. Delete une colonne \n");
        printf("Choix : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Entrez le titre de la colonne : ");
                scanf("%s", title);
                columns[num_columns] = create_column(title);
                num_columns++;
                printf("Colonne creee avec succes.\n");
                break;
            case 2:
                if (num_columns == 0) {
                    printf("Aucune colonne n'a ete creee.\n");
                    break;
                }
                printf("Entrez l'indice de la colonne dans laquelle inserer la valeur (0-%d) : ", num_columns-1);
                scanf("%d", &col_index);
                if (col_index < 0 || col_index >= num_columns) {
                    printf("Indice invalide.\n");
                    break;
                }
                printf("Entrez la valeur à inserer : ");
                scanf("%d", &value);
                if (insert_value(columns[col_index], value)) {
                    printf("Valeur inseree avec succès dans la colonne %s.\n", columns[col_index]->title);
                } else {
                    printf("Erreur lors de l'insertion de la valeur dans la colonne %s.\n", columns[col_index]->title);
                }
                break;
            case 3:
                if (num_columns == 0) {
                    printf("Aucune colonne n'a ete creee.\n");
                    break;
                }
                printf("Entrez l'indice de la colonne à afficher (0-%d) : ", num_columns-1);
                scanf("%d", &col_index);
                if (col_index < 0 || col_index >= num_columns) {
                    printf("Indice invalide.\n");
                    break;
                }
                printf("Contenu de la colonne %s :\n", columns[col_index]->title);
                print_col(columns[col_index]);
                break;
            case 4:
                if (num_columns == 0) {
                    printf("Aucune colonne n'a ete creee.\n");
                    break;
                }
                for (int i=0;i<num_columns;i++) {
                    print_col(columns[i]);
                }
                break;
            case 5 :
                if (num_columns == 0) {
                    printf("Aucune colonne n'a ete creee.\n");
                    break;
                }
                printf("Entrez l'indice de la colonne à afficher (0-%d) : ", num_columns-1);
                scanf("%d", &col_index);
                if (col_index < 0 || col_index >= num_columns) {
                    printf("Indice invalide.\n");
                    break;
                }
                delete_column(columns[col_index]);
                num_columns += -1;
                break;


        }
    } while(choice >= 6);

    return 0;
}
