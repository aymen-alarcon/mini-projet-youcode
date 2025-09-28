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

void deleteStudent(){
    int search;
    printf("can you please enter the ID of the student you wish to delete");
    scanf("%d", &search);

    for (int i = 0; i < studentCount; i++)
    {
        if (class[i].id == search)
        {
            for (int j = i; j < studentCount - 1; j++) {
                class[j] = class[j + 1];
            }
            studentCount--;
            printf("Student with ID %d has been deleted.\n", search);
            break;
        }
        else
        {
            printf("No student found with ID %d.\n", search);
        }
    }
}

void updateStudent(){
    int search;
    int updatechoice;
    printf("can you please enter the ID of the student you wish to update");
    scanf("%d", &search);

    for (int i = 0; i < studentCount; i++)
    {
        if (class[i].id == search)
        {
            printf("please enter the what do you want to edit\n");
            printf("1. to update the first name\n");
            printf("2. to update the last name\n");
            printf("3. to update the id\n");
            scanf("%d", &updatechoice);
            switch (updatechoice)
            {
            case 1 :
                printf("please enter the new first name ");
                scanf("%s", &class[i].firstname);
            break;
            case 2 :
                printf("please enter the new last name ");
                scanf("%s", &class[i].lastname);
            break;
            case 3 :
                printf("please enter the new ID ");
                scanf("%d", &class[i].id);
            break;
            default:
            break;
            }
            printf("Student with ID %d has been updated.\n", search);
            break;
        }
        else
        {
            printf("No student found with ID %d.\n", search);
        }
    }
}
    
void deleteAllStudents(){
    char answer;
    printf("are you sure:!!!(Y/N)");
    scanf(" %c", &answer);
    if (answer == 'Y' || answer == 'y')
    {
        studentCount = 0;
        printf("fuck you then");
    }   
}