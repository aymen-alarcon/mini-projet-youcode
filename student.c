#include <stdio.h>
#include <string.h>
#include "student.h"
 
struct student class[30];
int studentCount = 0;


void ajouterEtudiant() {
    if (studentCount >= 30) {
        printf("Maximum number of students reached!\n");
        return;
    }

    main();
    printf("Please enter your id");

    const char *sql_insert =
        "INSERT INTO Students (id, Name, Grade) VALUES ('Alice', 17.5);";

    rc = sqlite3_exec(db, sql_insert, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
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
    int index = searchStudents();
    for (int j = index; j < studentCount - 1; j++) {
        class[j] = class[j + 1];
    }
    studentCount--;
}

void updateStudent(){
    int index  = searchStudents();
    int updatechoice;
            printf("please enter the what do you want to edit\n");
            printf("1. to update the first name\n");
            printf("2. to update the last name\n");
            printf("3. to update the id\n");
            scanf("%d", &updatechoice);
            switch (updatechoice)
            {
            case 1 :
                printf("please enter the new first name ");
                scanf("%s", &class[index].firstname);
            break;
            case 2 :
                printf("please enter the new last name ");
                scanf("%s", &class[index].lastname);
            break;
            case 3 :
                printf("please enter the new ID ");
                scanf("%d", &class[index].id);
            break;
            default:
            break;
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