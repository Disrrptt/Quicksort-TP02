#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_ARRAY 20

int trocas = 0;
int comparacoes = 0;

typedef struct {
    char **strings;
    int tamanho;
} ArrayDeStrings;

void trocar(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
    trocas++;
}

int particionar(ArrayDeStrings *array, int inicio, int fim) {
    char *pivo = array->strings[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        comparacoes++;
        if (strcmp(array->strings[j], pivo) <= 0) {
            i++;
            trocar(&array->strings[i], &array->strings[j]);
        }
    }

    trocar(&array->strings[i + 1], &array->strings[fim]);
    return (i + 1);
}

void quickSort(ArrayDeStrings *array, int inicio, int fim) {
    comparacoes++;
    if (inicio < fim) {
        int indicePivo = particionar(array, inicio, fim);
        quickSort(array, inicio, indicePivo - 1);
        quickSort(array, indicePivo + 1, fim);
    }
}

void imprimirArray(ArrayDeStrings *array) {
    for (int i = 0; i < array->tamanho; i++) {
        comparacoes += 2;
        if (i == array->tamanho - 1) {
            comparacoes -= 1;
            printf("%s", array->strings[i]);
            break;
        }
        if (i == 6 || i == 12)
            printf("\n");
        printf("%s, ", array->strings[i]);
    }
}

void criarArquivo(ArrayDeStrings *array) {
    FILE *arquivo = fopen("ArrayOrdenado.txt", "w");

    fprintf(arquivo, "\t\tARQUIVO FINAL\n\n");
    fprintf(arquivo, "Array ordenado: ");
    
    for (int i = 0; i < array->tamanho; i++) {
        comparacoes += 2;
        if (i == array->tamanho - 1) {
            comparacoes -= 1;
            fprintf(arquivo, "%s", array->strings[i]);
            break;
        }
        if (i == 6 || i == 12)
            fprintf(arquivo, "\n\t\t\t\t");
        fprintf(arquivo, "%s, ", array->strings[i]);
    }

    fprintf(arquivo, "\nTrocas: %d\n", trocas);
    fprintf(arquivo, "Comparacoes: %d\n", comparacoes);
    fprintf(arquivo, "Mediana do array: %s\n", array->strings[array->tamanho / 2]);

    fclose(arquivo);
}

int main() {
    ArrayDeStrings array;

    array.strings = (char **)malloc(TAMANHO_ARRAY * sizeof(char *));
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        array.strings[i] = (char *)malloc(50 * sizeof(char));
    }

    array.tamanho = TAMANHO_ARRAY;

    // Adicione os elementos ao vetor
    strcpy(array.strings[0], "maca");
    strcpy(array.strings[1], "banana");
    strcpy(array.strings[2], "pera");
    strcpy(array.strings[3], "uva");
    strcpy(array.strings[4], "laranja");
    strcpy(array.strings[5], "abacaxi");
    strcpy(array.strings[6], "limão");
    strcpy(array.strings[7], "manga");
    strcpy(array.strings[8], "abacate");
    strcpy(array.strings[9], "kiwi");
    strcpy(array.strings[10], "cereja");
    strcpy(array.strings[11], "morango");
    strcpy(array.strings[12], "pêssego");
    strcpy(array.strings[13], "goiaba");
    strcpy(array.strings[14], "melancia");
    strcpy(array.strings[15], "framboesa");
    strcpy(array.strings[16], "amora");
    strcpy(array.strings[17], "caqui");
    strcpy(array.strings[18], "figo");
    strcpy(array.strings[19], "papaya");

    quickSort(&array, 0, array.tamanho - 1);

    printf("\nArray Ordenado\n");
    imprimirArray(&array);
    printf(", e a mediana do array é: %s\n", array.strings[array.tamanho / 2]);

    criarArquivo(&array);

    for (int i = 0; i < array.tamanho; i++) {
        free(array.strings[i]);
    }
    free(array.strings);

    return 0;
}
