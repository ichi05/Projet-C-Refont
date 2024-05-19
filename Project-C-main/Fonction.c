#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fonction.h"


// Créer une colonne vide
Column* create_column(char* title) {
    Column* col = (Column*)malloc(sizeof(Column));
    if (col == NULL) {
        printf("Erreur lors de l'allocation de mémoire pour la colonne\n");
        exit(EXIT_FAILURE);
    }
    col->title = strdup(title);
    col->data = NULL;
    col->physical_size = 0;
    col->logical_size = 0;
    return col;
}

// Insérer une valeur dans une colonne
int insert_value(Column* col, int value) {
    if (col == NULL) {
        printf("La colonne est NULL\n");
        return 0;
    }
    if (col->data == NULL) {
        col->data = (int*)malloc(sizeof(int) * 256); // Allocation initiale de 256 cases
        if (col->data == NULL) {
            printf("Erreur lors de l'allocation de mémoire pour les données de la colonne\n");
            exit(EXIT_FAILURE);
        }
        col->physical_size = 256;
    } else if (col->logical_size >= col->physical_size) {
        // Réallocation de mémoire si besoin
        col->data = (int*)realloc(col->data, sizeof(int) * (col->physical_size + 256));
        if (col->data == NULL) {
            printf("Erreur lors de la réallocation de mémoire pour les données de la colonne\n");
            exit(EXIT_FAILURE);
        }
        col->physical_size += 256;
    }
    col->data[col->logical_size++] = value;
    return 1;
}

// Libérer l'espace alloué par une colonne
void delete_column(Column* col) {
    if (col != NULL) {
        free(col->title);
        free(col->data);
        free(col);
    }
}

// Afficher le contenu d'une colonne
void print_col(Column* col) {
    if (col != NULL) {
        printf("Colonne \"%s\":\n", col->title);
        for (int i = 0; i < col->logical_size; i++) {
            printf("[%d] %d\n", i, col->data[i]);
        }
    }
}
void occurence(Column* col, int val) {
    if (col != NULL) {
        printf("Colonne \"%s\":\n", col->title);
        for (int i=0;i<col->logical_size;i++);
            if (col[i]==val){

            }
    }


}