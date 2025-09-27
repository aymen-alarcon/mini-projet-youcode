#include <stdio.h>
#include "student.h"

int search;

void saisirNotes() {
    if (studentCount == 0) {
        printf("No students available.\n");
        return;
    }

    int search;
    printf("Enter student ID to add grades: ");
    scanf("%d", &search);

    int index = -1;
    for (int i = 0; i < studentCount; i++) {
        if (class[i].id == search) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student not found!\n");
        return;
    }

    float sum = 0;
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
    if (studentCount == 0) {
        printf("No students available.\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &search);

    int ind = -1;
    for (int i = 0; i < studentCount; i++) {
        if (class[i].id == search) {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        printf("Student not found!\n");
        return;
    }

    printf("\nBulletin for %s %s:\n", class[ind].firstname, class[ind].lastname);
    for (int g = 0; g < 4; g++) {
        printf("Grade %d: %.2f\n", g + 1, class[ind].grade[g]);
    }
    printf("Average: %.2f\n", class[ind].average);
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

void deleletstudentsgrade(){
    printf("can you please enter the ID of the student you wish to delete");
    scanf("%d", &search);
    
    for (int i = 0; i < studentCount; i++)
    {
        if (class[i].id == search)
        {
            for (int j = 0; j < 4; j++)
            {
                
            }
            
        }
        else
        {
            /* code */
        }
        
    }
    
}