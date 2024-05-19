#ifndef FONCTION_H
#define FONCTION_H

typedef struct {
    char* title;    // Titre de la colonne
    int* data;      // Tableau des données
    int physical_size;  // Taille physique du tableau
    int logical_size;   // Taille logique du tableau
} Column;

Column* create_column(char* title);
int insert_value(Column* col, int value);
void delete_column(Column* col);
void print_col(Column* col);

#endif /* FONCTION_H */
