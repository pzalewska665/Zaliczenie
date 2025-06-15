#include <stdio.h>
#include <math.h>

void clearInputBuffer() {
    while (getchar() != '\n');
}

void showMenu() {
    printf("\nWybierz sposób zaokrąglania:\n");
    printf("1. obcięcie (int)\n");
    printf("2. round\n");
    printf("3. w górę: ceil\n");
    printf("4. w dół: floor\n");
    printf("0. Koniec\n");
}

void processChoice(int choice) {
    if (choice < 0 || choice > 4) {
        printf("Wybrana opcja (%d) jest niepoprawna.\n", choice);
        return;
    }
    if (choice == 0) {
        printf("Zakończenie programu.\n");
        return;
    }

    double number;
    printf("Wpisz liczbę do zaokrąglenia: ");
    if (scanf("%lf", &number) != 1) {
        printf("Błąd: Wprowadzono niepoprawne dane!\n");
        clearInputBuffer();
        return;
    }

    if (number == (int)number) {
        printf("Wpisana liczba jest całkowita!\n");
    }

    switch (choice) {
        case 1:
            printf("Liczba %.2f po obcięciu: %d\n", number, (int)number);
            break;
        case 2:
            printf("Liczba %.2f po zaokrągleniu: %.0f\n", number, round(number));
            break;
        case 3:
            printf("Liczba %.2f po zaokrągleniu w górę: %.0f\n", number, ceil(number));
            break;
        case 4:
            printf("Liczba %.2f po zaokrągleniu w dół: %.0f\n", number, floor(number));
            break;
    }
}

int main() {
    int choice;
    do {
        showMenu();
        printf("Wybierz polecenie: ");
        if (scanf("%d", &choice) != 1) {
            printf("Błąd: Wprowadzono niepoprawne dane!\n");
            clearInputBuffer();
            continue;
        }
        processChoice(choice);
    } while (choice != 0);

    return 0;
}

