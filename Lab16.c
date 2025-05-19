#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size, const char *name) {
    printf("%s: ", name);
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int size1, size2;
    int *array1 = NULL;
    int *array2 = NULL;
    int i;

    printf("Введіть розмір першого масиву: ");
    scanf("%d", &size1);

    if (size1 <= 0) {
        printf("Розмір масиву повинен бути додатнім числом.\n");
        return 1;
    }

    array1 = (int *)malloc(size1 * sizeof(int));
    if (array1 == NULL) {
        printf("Помилка виділення пам'яті для першого масиву.\n");
        return 1;
    }

    printf("Введіть елементи для першого масиву (%d елементів):\n", size1);
    for (i = 0; i < size1; i++) {
        printf("Елемент %d: ", i);
        scanf("%d", array1 + i);
    }

    printf("\nВведіть розмір другого масиву: ");
    scanf("%d", &size2);

    if (size2 <= 0) {
        printf("Розмір масиву повинен бути додатнім числом.\n");
        free(array1);
        return 1;
    }

    array2 = (int *)malloc(size2 * sizeof(int));
    if (array2 == NULL) {
        printf("Помилка виділення пам'яті для другого масиву.\n");
        free(array1);
        return 1;
    }

    printf("Введіть елементи для другого масиву (%d елементів):\n", size2);
    for (i = 0; i < size2; i++) {
        printf("Елемент %d: ", i);
        scanf("%d", array2 + i);
    }

    printf("\nМасиви до обміну:\n");
    print_array(array1, size1, "Масив 1");
    print_array(array2, size2, "Масив 2");

    int min_size = (size1 < size2) ? size1 : size2;
    for (i = 0; i < min_size; i++) {
        int temp = *(array1 + i);
        *(array1 + i) = *(array2 + i);
        *(array2 + i) = temp;
    }

    printf("\nМасиви після обміну (обміняно %d елементів):\n", min_size);
    print_array(array1, size1, "Масив 1");
    print_array(array2, size2, "Масив 2");

    free(array1);
    free(array2);

    return 0;
}