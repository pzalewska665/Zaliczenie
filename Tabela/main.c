
#include <stdio.h>
#define SIZE 10


void printArray(int *array) {
    for (int i = 0; i < SIZE; i++) {
        printf("array[%d] = %d\n", i, array[i]);
        printf("*(%p) = %d\n\n", array + i, *(array + 1));
    }
}
int findMax(int *array) {
    int max = *array;
    for (int i = 1; i < SIZE; i++) {
        if (*(array + i) > max) {
            max = *(array + i);
        }
    }
    return max;
}

int findMin(int *array) {
    int min = *array;
    for (int i = 1; i < SIZE; i++) {
        if (*(array + i) < min) {
            min = *(array + i);
        }
    }
    return min;
}

float findAverage(int *array) {
    int sum = *array;
    for (int i = 0; i < SIZE; i++) {
        sum += *(array + i);
    }
    return (float) sum / SIZE;
}

int saveArrayToFile(int array[]) {
    FILE *fptr = NULL;
    fptr = fopen("../array.txt", "w");
    if (fptr == NULL) {
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        fprintf(fptr, "%d\n", array[i]);
    }
    fclose(fptr);
    return 0;
}

int restoreArrayFromFile(int array[]) {
    FILE *fptr = NULL;
    fptr = fopen("../array.txt", "r");
    if (fptr == NULL) {
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        fscanf(fptr, "%d\n", &array[i]);
    }
    fclose(fptr);
    return 0;
}

void menu(void) {
    printf("1. Enter the values into the array\n");
    printf("2. Print array\n");
    printf("3. Determine the maximum value\n");
    printf("4. Determine the minimum value\n");
    printf("5. Determine the average value\n");
    printf("6. Determinate the median\n");
    printf("7. Restore array\n");
    printf("0. Exit\n");
    printf("Choose the option\n");
}

int main() {

    int array[SIZE] = {4, 2, 19, 4, 13, 1, 42, 3, 5, 15};
    int option = 0;
    int errorCode = 0;

    do {
        menu();
        scanf("%d", &option);
        switch (option) {
            case 0:
                break;
            case 1:
                printf("Enter the value into the array\n");
                break;
            case 2:
                printArray(array);
                break;
            case 3:
                printf("Maximum value into the array is %d\n", findMax(array));
                break;
            case 4:
                printf("Minimum value into the array is %d\n", findMin(array));
                break;
            case 5:
                printf("Average value into the array is %f\n", findAverage(array));
                break;
            case 6:
                    printf("Saving data to the file\n\n");
                    errorCode = saveArrayToFile(array);
                if (!errorCode) {
                    printf("Array saved to the file\n\n");
                }else {
                    printf("Error saving data to the file\n\n");
                 }
                break;
            case 7:
                printf("Restoring data from the file\n\n");
                errorCode = restoreArrayFromFile(array);
                if (!errorCode) {
                    printf("Array restored from file\n\n");
                }else {
                    printf("Error restoring data from the file\n\n");
                }
                break;
            default:
                printf("Invalid option!");


        }
    }
        while (option != 0);
        printf("The end.\n");

        return 0;
    }


