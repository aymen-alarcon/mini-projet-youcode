#include <stdio.h>
#include "student.h"

int search;
float sum = 0;

void saisirNotes() {
    int index = searchStudents();
    for (int g = 0; g < 4; g++) {
        do {
            printf("Enter grade %d: ", g + 1);
            scanf("%f", &class[index].grade[g]);
            if (class[index].grade[g] < 1 || class[index].grade[g] > 20) {
                printf("Invalid grade. Please enter between 1 and 20.\n");
            }
        } while (class[index].grade[g] < 1 || class[index].grade[g] > 20);

        sum += class[index].grade[g];
    }
    class[index].average = sum / 4;
    printf("Average for %s: %.2f\n", class[index].firstname, class[index].average);
}

void afficherBulletin() {
    int index = searchStudents();
    printf("\nBulletin for %s %s:\n", class[index].firstname, class[index].lastname);
    for (int g = 0; g < 4; g++) {
        printf("Grade %d: %.2f\n", g + 1, class[index].grade[g]);
    }
    printf("Average: %.2f\n", class[index].average);
}

void calculerMoyenneGenerale() {
    if (studentCount == 0) {
        printf("No students to calculate average.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < studentCount; i++) {
        total += class[i].average;
    }

    printf("Class average: %.2f\n", total / studentCount);
}

void deleletStudentAllGrades(){
    int index = searchStudents();
    for (int j = 0; j < 4; j++)
    {
        class[index].grade[j] = 0;
    }
    class[index].average = 0;
}

void UpdateStudentAllGrades(){
    int found = 0;
    sum = 0;
    printf("can you please enter the ID of the student you wish to update: ");
    scanf("%d", &search);
    
    for (int i = 0; i < studentCount; i++)
    {
        if (class[i].id == search)
        {
            found = 1;
            for (int j = 0; j < 4; j++)
            {
                printf("please the value of the %d grade", j + 1);
                scanf("%f", &class[i].grade[j]);
            }
            for (int j = 0; j < 4; j++) {
                sum += class[i].grade[j];
            }
            class[i].average = sum / 4;

            printf("Updated average for %s: %.2f\n", class[i].firstname, class[i].average);
            break;
        }
    }
    if (found == 0)
    {
        printf("Sorry there is no student with that id");
    }
}

void deleteStudentsGrade() {
    int search;
    int gradesearch;
    int found = 0;
    float sum = 0;

    printf("Enter the ID of the student: ");
    scanf("%d", &search);

    for (int i = 0; i < studentCount; i++) {
        if (class[i].id == search) {
            found = 1;
            printf("Enter the grade number to delete (1-4): ");
            scanf("%d", &gradesearch);

            if (gradesearch < 1 || gradesearch > 4) {
                printf("Invalid grade number!\n");
                return;
            }

            int index = gradesearch - 1;
            class[i].grade[index] = 0;

            for (int j = 0; j < 4; j++) {
                sum += class[i].grade[j];
            }
            class[i].average = sum / 4;

            printf("Updated average for %s: %.2f\n", class[i].firstname, class[i].average);
            break;
        }
    }

    if (found = 0) {
        printf("No student found with ID %d\n", search);
    }
}

void updateStudentsGrade() {
    int search;
    int gradesearch;
    int found = 0;
    float sum = 0;

    printf("Enter the ID of the student: ");
    scanf("%d", &search);

    for (int i = 0; i < studentCount; i++) {
        if (class[i].id == search) {
            found = 1;
            printf("Enter the grade number to update (1-4): ");
            scanf("%d", &gradesearch);

            if (gradesearch < 1 || gradesearch > 4) {
                printf("Invalid grade number!\n");
                return;
            }

            printf("please the new grade for grade number %d: ", gradesearch);
            int index = gradesearch - 1;
            scanf("%f", &class[i].grade[index]);

            for (int j = 0; j < 4; j++) {
                sum += class[i].grade[j];
            }
            class[i].average = sum / 4;

            printf("Updated average for %s: %.2f\n", class[i].firstname, class[i].average);
            break;
        }
    }

    if (found = 0) {
        printf("No student found with ID %d\n", search);
    }
}