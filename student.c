#include <stdio.h>
#include "student.h"

struct student class[30];
int studentCount = 0;

void ajouterEtudiant() {
    if (studentCount >= 30) {
        printf("Maximum number of students reached!\n");
        return;
    }

    printf("Enter student's ID: ");
    scanf("%d", &class[studentCount].id);
    printf("Enter first name: ");
    scanf("%s", class[studentCount].firstname);
    printf("Enter last name: ");
    scanf("%s", class[studentCount].lastname);

    studentCount++;
    printf("Student added successfully!\n");
}

void afficherEtudiants() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d | First name: %s | Last name: %s | Grades: [",
               class[i].id, class[i].firstname, class[i].lastname);
        for (int g = 0; g < 3; g++) {
            printf("%.2f, ", class[i].grade[g]);
        }
        printf("%.2f] | Average: %.2f\n", class[i].grade[3], class[i].average);
    }
}
