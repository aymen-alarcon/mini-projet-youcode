#include <stdio.h>
#include "student.h"
#include "grades.h"

void showMenu() {
    int choice;
    do {
        printf("\n=== STUDENT MANAGEMENT MENU ===\n");
        printf("1. Add a student\n");
        printf("2. Add student grades\n");
        printf("3. Display all students\n");
        printf("4. Display student bulletin\n");
        printf("5. Calculate class average\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: ajouterEtudiant(); break;
            case 2: saisirNotes(); break;
            case 3: afficherEtudiants(); break;
            case 4: afficherBulletin(); break;
            case 5: calculerMoyenneGenerale(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
}
